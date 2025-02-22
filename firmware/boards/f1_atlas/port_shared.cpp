#include "port_shared.h"

#if HAL_USE_CAN
// board-specific stuff shared between bootloader and firmware
/* Dave horrible - disable since no CAN */

static const CANConfig canConfig500 =
{
    CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP,
//     For 24MHz http://www.bittiming.can-wiki.info/ gives us Pre-scaler=3, Seq 1=13 and Seq 2=2. Subtract '1' for register values
//
    CAN_BTR_SJW(0) | CAN_BTR_BRP(2)  | CAN_BTR_TS1(12) | CAN_BTR_TS2(1),
};

const CANConfig& GetCanConfig() {
    return canConfig500;
}
#endif // HAL_USE_CAN
