#include<stdint.h>
#include<stdbool.h>

#include "performance.h"

void InitTimer() {
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
    ROM_SysCtlPeripheralReset(SYSCTL_PERIPH_TIMER4);
    ROM_TimerConfigure(TIMER4_BASE, TIMER_CFG_PERIODIC_UP);
    ROM_TimerControlStall(TIMER4_BASE, TIMER_A, true);
}

void StartTimer() {
    ROM_TimerDisable(TIMER4_BASE, TIMER_A) ;
    TimerLoadSet(TIMER4_BASE, TIMER_A,0xFFFFFFFF);
    HWREG(TIMER4_BASE + TIMER_O_TAV) = 0;
    ROM_TimerEnable(TIMER4_BASE, TIMER_A) ;
}

uint32_t CaptureTimer() {
    return ROM_TimerValueGet(TIMER4_BASE, TIMER_A);
}