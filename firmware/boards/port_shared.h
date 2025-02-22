#pragma once

#if WB_PROD

#include "hal.h"

#if HAL_USE_CAN
const CANConfig& GetCanConfig();
#endif //HAL_USE_CAN

#endif // WB_PROD
