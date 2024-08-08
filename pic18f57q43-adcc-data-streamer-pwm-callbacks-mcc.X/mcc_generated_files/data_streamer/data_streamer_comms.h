/**
 * DATASTREAMER Generated Driver Comms API Header File.
 *
 * @file data_streamer_comms.h
 * 
 * @defgroup datastreamer_comms DATASTREAMER_COMMS
 * 
 * @brief This file contains the API prototypes Data Streamer driver's serial Communication operations.
 *
 * @version Data Streamer Driver Version 1.2.1
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

#ifndef DATA_STREAMER_COMMS_H
#define	DATA_STREAMER_COMMS_H

#include <stdbool.h>
/**
 * @ingroup datastreamer_comms
 * @brief  Writes a variable to the Data Streamer.
 * @param char var - 8-bit variable to be sent.
 * @return None.
 */ 
void DataStreamer_VariableWrite(char var);

/**
 * @ingroup datastreamer_comms
 * @brief  Returns the status of the Transmission.
 * @param None.
 * @retval True - Data completely transmitted
 * @retval False - Data is still in transmission
 */ 
bool DataStreamer_IsTxDone(void);

#endif	/* DATA_STREAMER_COMMS_H */
/**
 End of File
*/
