/*
 * software timer: prototype
 */
//--------------------------------------"sf_timer.h"
#include <stdint.h>
typedef struct SoftWareTimer{
    uint32_t startTime;
    uint32_t elapseTime;
}sftimer_t ;
void runTimer(sftimer_t* time, uint32_t t);
void downTimer(sftimer_t* time);
//--------------------------------------"sf_timer.c"
#include "sf_timer.h"
/********************************************************************
 * @fn      runTimer
 * @brief   run a software timer
 * @param   time - struct of software timer, store timer state
 *          t    - time interval
 * @return  none
 *******************************************************************/
void runTimer(sftimer_t* time, uint32_t t)
{
    time->startTime = sys_tick(); // notice! this is system tick
    time->elapseTime = t;
}

/********************************************************************
 * @fn      downTimer
 * @brief   check whether a timer is down
 * @param   time - struct of software timer, store timer state
 * @return  1 - timer down
 *          0 - timer still running
 *******************************************************************/
void downTimer(sftimer_t* time)
{
    return sys_tick() >= (time->startTime + time->elapseTime);
}
//--------------------------------------"main.c"
#include "sf_timer.h"
sftimer_t countdown[3];
int main(int argc, const char *argv[])
{
    runTimer(&countdown[0], 500); // 500ms
    while(1){
        if(downTimer(&countdown[0])){
            // do something ...
            runTimer(&countdown[0], 500);
        }
    }
    return 0;
}

