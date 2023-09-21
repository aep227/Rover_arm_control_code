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
 *  ======== location_feeder ========
 *  Task used for testing the armMovement task
 */
void *locFeeder(void *arg0)
{
    static loc_number = 0;
    /*
        read arm out Q
        if(arm at angle)
        {
            switch (loc_number)
            {
                case 0: push new location to arm read Q
                    base all the the way left
                    break;
                case 1: push new location to arm read Q
                    base all the the way right
                    break;
                case 2: push new location to arm read Q
                    base centered
                    break;
                case 3: push new location to arm read Q
                    grabber opens
                    break;
                case 4: push new location to arm read Q
                    right servo extends
                    break;
                case 5: push new location to arm read Q
                    left servo extends
                    break;
                case 6: push new location to arm read Q
                    grabber closes
                break;
                case 7: push new location to arm read Q
                    left servo retracts
                break;
                case 8: push new location to arm read Q
                    right servo retracts
                break;
                default: // code to be executed if n doesn't match any cases
            }
            if(loc_number < 8)
            {
                loc_number = loc_number + 1;
            }
        }

    */
}