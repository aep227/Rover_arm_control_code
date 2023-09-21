/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== pwmled2.c ========
 */
/* For usleep() */
#include <unistd.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/PWM.h>

/* Driver configuration */
#include "ti_drivers_config.h"

#define RIGHT 0
#define LEFT 1

/*
 *  ======== armMovement ========
 *  Task periodically reads from queue and adjusts arm position
 */
void *armMovement(void *arg0)
{
    /* Period and duty in microseconds */
    uint16_t pwmPeriod = 20000; //20 milliseconds = 20,000 microseconds
    uint16_t duty_base = 1350;  //1ms-2ms = 1000-2000 microseconds = 5-10% duty cycle
    uint16_t duty_grab = 1350;  //1ms-2ms = 1000-2000 microseconds = 5-10% duty cycle
    uint16_t duty_left = 1350;  //1ms-2ms = 1000-2000 microseconds = 5-10% duty cycle
    uint16_t duty_right = 1350; //1ms-2ms = 1000-2000 microseconds = 5-10% duty cycle
    uint16_t dutyInc = 5;

    /* Sleep time in microseconds */
    uint32_t time = 3000;
    PWM_Handle pwm_base = NULL;
    PWM_Handle pwm_grab = NULL;
    PWM_Handle pwm_left = NULL;
    PWM_Handle pwm_right = NULL;

    PWM_Params params;

    /* Call driver init functions. */
    PWM_init();

    PWM_Params_init(&params);
    params.dutyUnits = PWM_DUTY_US;
    params.dutyValue = 0;
    params.periodUnits = PWM_PERIOD_US;
    params.periodValue = pwmPeriod;
    pwm_base = PWM_open(CONFIG_PWM_0, &params);
    int dir = LEFT;
    if (pwm_base == NULL)
    {
        /* CONFIG_PWM_0 did not open */
        while (1)
            ;
    }

    PWM_start(pwm_base);

    /* Loop forever incrementing the PWM duty */
    while (1)
    {
        PWM_setDuty(pwm_base, duty_base);

        if (dir == RIGHT)
        {
            duty_base = (duty_base + dutyInc);
            if (duty_base >= 2500)
            {
                dir = LEFT;
            }
        }
        else if (dir == LEFT)
        {
            duty_base = (duty_base - dutyInc);
            if (duty_base <= 500)
            {
                dir = RIGHT;
            }
        }

        usleep(time);
    }
}
