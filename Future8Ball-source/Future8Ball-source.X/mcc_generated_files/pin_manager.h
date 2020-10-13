/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set led_yellow aliases
#define led_yellow_TRIS                 TRISAbits.TRISA2
#define led_yellow_LAT                  LATAbits.LATA2
#define led_yellow_PORT                 PORTAbits.RA2
#define led_yellow_WPU                  WPUAbits.WPUA2
#define led_yellow_OD                   ODCONAbits.ODCA2
#define led_yellow_ANS                  ANSELAbits.ANSA2
#define led_yellow_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define led_yellow_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define led_yellow_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define led_yellow_GetValue()           PORTAbits.RA2
#define led_yellow_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define led_yellow_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define led_yellow_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define led_yellow_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define led_yellow_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define led_yellow_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define led_yellow_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define led_yellow_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set oled_reset aliases
#define oled_reset_TRIS                 TRISAbits.TRISA5
#define oled_reset_LAT                  LATAbits.LATA5
#define oled_reset_PORT                 PORTAbits.RA5
#define oled_reset_WPU                  WPUAbits.WPUA5
#define oled_reset_OD                   ODCONAbits.ODCA5
#define oled_reset_ANS                  ANSELAbits.ANSA5
#define oled_reset_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define oled_reset_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define oled_reset_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define oled_reset_GetValue()           PORTAbits.RA5
#define oled_reset_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define oled_reset_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define oled_reset_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define oled_reset_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define oled_reset_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define oled_reset_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define oled_reset_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define oled_reset_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SDA2 aliases
#define SDA2_TRIS                 TRISBbits.TRISB5
#define SDA2_LAT                  LATBbits.LATB5
#define SDA2_PORT                 PORTBbits.RB5
#define SDA2_WPU                  WPUBbits.WPUB5
#define SDA2_OD                   ODCONBbits.ODCB5
#define SDA2_ANS                  ANSELBbits.ANSB5
#define SDA2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SDA2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SDA2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SDA2_GetValue()           PORTBbits.RB5
#define SDA2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SDA2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SDA2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SDA2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SDA2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SDA2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SDA2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SDA2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCL2 aliases
#define SCL2_TRIS                 TRISBbits.TRISB7
#define SCL2_LAT                  LATBbits.LATB7
#define SCL2_PORT                 PORTBbits.RB7
#define SCL2_WPU                  WPUBbits.WPUB7
#define SCL2_OD                   ODCONBbits.ODCB7
#define SCL2_ANS                  ANSELBbits.ANSB7
#define SCL2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SCL2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SCL2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SCL2_GetValue()           PORTBbits.RB7
#define SCL2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SCL2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SCL2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SCL2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SCL2_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SCL2_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SCL2_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SCL2_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set button aliases
#define button_TRIS                 TRISCbits.TRISC2
#define button_LAT                  LATCbits.LATC2
#define button_PORT                 PORTCbits.RC2
#define button_WPU                  WPUCbits.WPUC2
#define button_OD                   ODCONCbits.ODCC2
#define button_ANS                  ANSELCbits.ANSC2
#define button_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define button_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define button_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define button_GetValue()           PORTCbits.RC2
#define button_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define button_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define button_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define button_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define button_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define button_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define button_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define button_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/