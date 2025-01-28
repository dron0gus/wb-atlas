#include "ch.h"
#include "hal.h"

#include "io_pins.h"
#include "livedata.h"

#include "sampling.h"
#include "port.h"

static Sampler samplers[AFR_CHANNELS];

const ISampler& GetSampler(int ch)
{
    return samplers[ch];
}

static THD_WORKING_AREA(waSamplingThread, 256);

#ifdef BOARD_HAS_VOLTAGE_SENSE
static float supplyVoltage = 0;

float GetSupplyVoltage()
{
    return supplyVoltage;
}
#endif

static void SamplingThread(void*)
{
    chRegSetThreadName("Sampling");

    SetupESRDriver(GetSensorType());

    /* GD32: Insert 20us delay after ADC enable */
    chThdSleepMilliseconds(1);

    while(true)
    {
        auto result = AnalogSample();

        // Toggle the pin after sampling so that any switching noise occurs while we're doing our math instead of when sampling
        ToggleESRDriver(GetSensorType());

        #ifdef BOARD_HAS_VOLTAGE_SENSE
        supplyVoltage = result.SupplyVoltage;
        #endif

        for (int ch = 0; ch < AFR_CHANNELS; ch++)
        {
            samplers[ch].ApplySample(result.ch[ch], result.VirtualGroundVoltageInt);
        }

#if defined(TS_ENABLED)
        /* tunerstudio */
        SamplingUpdateLiveData();
#endif
    }
}

void StartSampling()
{
    for (int i = 0; i < AFR_CHANNELS; i++)
    {
        samplers[i].Init();
    }

    adcStart(&ADCD1, nullptr);
    chThdCreateStatic(waSamplingThread, sizeof(waSamplingThread), NORMALPRIO + 5, SamplingThread, nullptr);
}
