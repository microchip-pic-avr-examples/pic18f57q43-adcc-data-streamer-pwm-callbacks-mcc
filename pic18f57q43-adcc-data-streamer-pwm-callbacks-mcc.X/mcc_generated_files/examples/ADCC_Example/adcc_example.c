/**
 * ADCC Data Streamer - Callback Example Driver File
 * 
 * @file adcc_example.c
 * 
 * @addtogroup adcc_example
 * 
 * @brief This is the generated example implementation for ADCC Data Streamer - Callback driver.
 *
 * @version ADCC Data Streamer - Callback Example Version 1.0.0
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/* Use Case 2 - Callback implementation. Copy this code to your project source, e.g., to main.c  */
/* ------------------------------------------------------------------

#include "mcc_generated_files/system/system.h"

static void ADCC_ConversionDone_Callback(void);
static void Timer_Callback_100ms(void);

static const struct TMR_INTERFACE *Timer = &TimerX; // TODO: Replace TimerX with name of const struct TMR_INTERFACE, from MCC Generated Files > timer > tmrx.c 
static volatile bool sendFrame = false;

void ADCC_ConversionDone_Callback(void)
{
    DataStreamer.adcResult = ADCC_GetConversionResult();
    DataStreamer.adcSampleCount++;
    IO_LED_Toggle();
    IO_Debug_Toggle();
    sendFrame = true;
}

void Timer_Callback_100ms(void)
{
    ADCC_DischargeSampleCapacitor(); 
    ADCC_StartConversion(channel_ANAx); // TODO: Replace x with the ADCC Channel you selected in Pin Grid View
}

int main(void)
{
    SYSTEM_Initialize();

    DataStreamer.adcSampleCount = 0;
    DataStreamer.adcResult = 0;
    ADCC_SetADIInterruptHandler(ADCC_ConversionDone_Callback);
    Timer->TimeoutCallbackRegister(Timer_Callback_100ms);
    
    INTERRUPT_GlobalInterruptEnable();

    while (1)
    {
        if (sendFrame)
        {
            WriteFrame();
            sendFrame = false;
        }
    }
}
------------------------------------------------------------------ */
/**
 End of File
*/