/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F18446
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "AT30E754.h"
#include "4864.h"
#include "bma2x2_support.h"
#include "stdlib.h"


#define STATE_MACHINE_TEMPERATURE				0
#define STATE_MACHINE_3AXIS						1
#define STATE_MACHINE_MOTION					2
#define STATE_MACHINE_LOGO						3
#define STATE_MACHINE_MAX						STATE_MACHINE_LOGO


#define BUTTON_ACTION_TIMING					3			// 40 ms* BUTTON_ACTION_TIMING
#define SHOW_ICON_TIMING						75			// 3 seconds

#define UPDATE_TEMPERATURE_TIMING				25			// refresh temperature every second
#define UPDATE_MOTION_TIMING					25			// refresh motion picture every second
#define UPDATE_LOG_TIMING						50			// refresh LOGO picture every 2 second
#define UPDATE_ORIENT_TIMING					5			// refresh orient picture every 200ms


void hardware_delay_40_ms(uint32_t ms)
{
 	volatile int j;
	uint32_t i;
	for(i=0;i<ms;i++)
		{
		for(j=0;j<12000;j++)
			{
			
			}
		}
}

/*
                         Main application
 */
void main(void)
{
	volatile uint8_t motion=0,orient=0;;
	uint8_t motion_detecting_mode=0,motion_detecting_mode_bak;
	uint8_t logo_index=PICTURE_INDEX_FE_LOGO;
	uint8_t state_machine=0;
	uint16_t button_press_timer=0,state_machine_timer=0,CF_timer=0,show_icon_timer=0;
	uint8_t C_or_F=1,get_button=0;
    
  
    extern int buttonPressed; // Added 

   // initialize the device
     SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

     INTERRUPT_GlobalInterruptEnable();
     INTERRUPT_PeripheralInterruptEnable();

	 //init sensor and panel
	 AT30E754_I2C2_config();
	 init_bma2x2();
	 initial_4864();

	 show_picutre(PICTURE_INDEX_TEMP_ICON);

   while (1)
    {
         // Add your application code
		//if((button_GetValue()==0))
       if((buttonPressed == 1))     //added
			{
			//button_press_timer++;
			//if((button_press_timer>BUTTON_ACTION_TIMING)&&(get_button==0))			//1000ms
				//{
				state_machine=state_machine++;
				if(state_machine>STATE_MACHINE_MAX)
					{
					state_machine=STATE_MACHINE_TEMPERATURE;
					}
				led_yellow_SetLow();
				state_machine_timer=0;			//	clear timer when chaged state
				show_icon_timer=0;				//reset timer
				if(state_machine==STATE_MACHINE_TEMPERATURE)
					{
					show_picutre(PICTURE_INDEX_TEMP_ICON);
					}
				if(state_machine==STATE_MACHINE_MOTION)
					{
					show_picutre(PICTURE_INDEX_8BALL_ICON);
					}
				if(state_machine==STATE_MACHINE_LOGO)
					{
					show_picutre(logo_index);
					}
				get_button=1;
                buttonPressed = 0;          //Added
				//}
			}
		else
			{
			led_yellow_SetHigh();
			button_press_timer=0;
			get_button=0;
			}

		switch(state_machine)
			{
			case STATE_MACHINE_TEMPERATURE:
				if(show_icon_timer++>SHOW_ICON_TIMING)
					{
					//update temperature every 1 second
					if(state_machine_timer++>UPDATE_TEMPERATURE_TIMING)
						{
						int16_t temp_current=0;
						int8_t negative=0,ten_dig,dig,decimal;
						if(CF_timer++>5)
							{
							CF_timer=0;
							C_or_F=!C_or_F;
							refresh_picture_CF(C_or_F);
							}
						temp_current=get_AT30E754_temperature(C_or_F);
						negative=temp_current>0?0:1;
						decimal=abs(temp_current)%10;
						dig=abs(temp_current/10)%10;
						ten_dig=abs(temp_current/100)%10;
						show_temperature(negative,ten_dig,dig,decimal);
						state_machine_timer=0;
						}
					show_icon_timer=SHOW_ICON_TIMING+1;		//don't update this timer anymore
					}
				break;
			case STATE_MACHINE_3AXIS:
				if(state_machine_timer++>UPDATE_ORIENT_TIMING)
					{
					state_machine_timer=0;
					orient=bma2x2_check_orient();
					if(orient<5)
						{
						show_picutre(PICTURE_INDEX_3AXIS_DOWN+orient);
						}
					}
				break;
			case STATE_MACHINE_MOTION:
				if(show_icon_timer++>SHOW_ICON_TIMING)
					{
					motion=bma2x2_check_motion();
					if(state_machine_timer++>UPDATE_MOTION_TIMING)
						{
						if(motion)
							{
							led_yellow_SetLow();
							motion_detecting_mode=rand()%(PICTURE_INDEX_8BALL_ICON+1);
							//make sure there are no same value
							if(motion_detecting_mode==motion_detecting_mode_bak)
								{
								motion_detecting_mode=(motion_detecting_mode+1)%PICTURE_INDEX_8BALL_ICON;
								}
							show_picutre(motion_detecting_mode);
							motion_detecting_mode_bak=motion_detecting_mode;
							state_machine_timer=0;
							}
						else
							{
							led_yellow_SetHigh();
							state_machine_timer=26;
							}
						}
					}
				break;
			
			case STATE_MACHINE_LOGO:
				if(state_machine_timer++>UPDATE_LOG_TIMING)
					{
					state_machine_timer=0;
					logo_index=logo_index+1;
					if(logo_index>PICTURE_INDEX_EVK_LOGO)
						{
						logo_index=PICTURE_INDEX_FE_LOGO;
						}
					show_picutre(logo_index);
					}
				break;
			}
		hardware_delay_40_ms(1);
    }
}
/**
 End of File
*/