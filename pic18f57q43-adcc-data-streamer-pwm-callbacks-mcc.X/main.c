 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include "mcc_generated_files/system/system.h"

static void ADCC_ConversionDone_Callback(void);
static void PWM_DutyCycleSetPercentage_Slice1(uint16_t, uint16_t, uint16_t);
static void Timer_Callback_20ms(void);

#define MAXIMUM_INPUT_VALUE 4100  // TODO: Replace with the desired maximum value, e.g. a 16 bit ADC connected to a potentiometer could be 4100)
static uint16_t Count = 0;
static uint16_t periodCountTop = 100;

static const struct TMR_INTERFACE *Timer = &Timer2; // TODO: Replace TimerX with name of const struct TMR_INTERFACE, from MCC Generated Files > timer > tmrx.c 
static volatile bool sendFrame = false;

void PWM_DutyCycleSetPercentage_Slice1(uint16_t current, uint16_t max, uint16_t periodCountTop)
{
    uint16_t PWM_DytyCyclePercentage = (1.0f - ((double) current / (double) max)) * periodCountTop;
    PWM_SetSlice1Output1DutyCycleRegister(PWM_DytyCyclePercentage);
    PWM_LoadBufferRegisters();
}

void ADCC_ConversionDone_Callback(void)
{
    DataStreamer.adcResult = ADCC_GetConversionResult();
    DataStreamer.adcSampleCount++;
    PWM_DutyCycleSetPercentage_Slice1(DataStreamer.adcResult, MAXIMUM_INPUT_VALUE, periodCountTop);
    IO_Debug_Toggle();
    sendFrame = true;
}

void Timer_Callback_20ms(void)
{
    ADCC_DischargeSampleCapacitor(); 
    ADCC_StartConversion(channel_ANA7); // TODO: Replace x with the ADCC Channel you selected in Pin Grid View
}

int main(void)
{
    SYSTEM_Initialize();

    DataStreamer.adcSampleCount = 0;
    DataStreamer.adcResult = 0;
    ADCC_SetADIInterruptHandler(ADCC_ConversionDone_Callback);
    Timer->TimeoutCallbackRegister(Timer_Callback_20ms);
    PWM_WritePeriodRegister(periodCountTop);
    
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