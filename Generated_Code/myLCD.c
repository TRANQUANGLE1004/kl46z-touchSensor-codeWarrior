/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : myLCD.c
**     Project     : myProject
**     Processor   : MKL46Z256VLL4
**     Component   : SegLCD_LDD
**     Version     : Component 01.017, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-07-01, 15:02, # CodeGen: 15
**     Abstract    :
**         This component "SegLCD_LDD" implements the segment Liquid Crystal Display (SegLCD)
**         driver module. It can drive an LCD which is composed of variable number
**         of frontplanes and backplanes. It can control also current mode of display.
**     Settings    :
**          Component name                                 : myLCD
**          Segment LCD module                             : LCD
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_LCD
**            Interrupt priority                           : medium priority
**          Stop in Wait mode                              : no
**          Stop in Stop mode                              : no
**          Power supply                                   : 
**            LCD operation voltage                        : 3V
**            Power mode selection                         : Charge Pump
**            Voltage supply control                       : Drive VLL3 internally from VDD
**            Charge pump                                  : Enabled
**              Charge pump clock adjust                   : Slowest clock
**              Charge pump clock                          : 1.365 kHz
**              Voltage regulator                          : Disabled
**            Bias voltage VLL1                            : (VLL3 * 1/3) = 0.99V
**            Bias voltage VLL2                            : (VLL3 * 2/3) = 1.98V
**            Bias voltage VLL3                            : Connect internally to VDD(must be 3V)
**          Blink rate bits value                          : 0
**          Blink rate                                     : 16 Hz
**          LCD frame frequency                            : 64 Hz
**          Base clock                                     : 1000 Hz
**          Fault detect                                   : Disabled
**          Backplane pins                                 : 8
**            Backplane pin0                               : 
**              Backplane pin                              : LCD_P37/PTC17
**              Backplane pin signal                       : 
**            Backplane pin1                               : 
**              Backplane pin                              : LCD_P17/PTB21
**              Backplane pin signal                       : 
**            Backplane pin2                               : 
**              Backplane pin                              : LCD_P7/PTB7
**              Backplane pin signal                       : 
**            Backplane pin3                               : 
**              Backplane pin                              : LCD_P8/PTB8/SPI1_PCS0/EXTRG_IN
**              Backplane pin signal                       : 
**            Backplane pin4                               : 
**              Backplane pin                              : LCD_P53/PTE5
**              Backplane pin signal                       : 
**            Backplane pin5                               : 
**              Backplane pin                              : LCD_P38/PTC18
**              Backplane pin signal                       : 
**            Backplane pin6                               : 
**              Backplane pin                              : LCD_P10/PTB10/SPI1_PCS0
**              Backplane pin signal                       : 
**            Backplane pin7                               : 
**              Backplane pin                              : LCD_P11/PTB11/SPI1_SCK
**              Backplane pin signal                       : 
**          Frontplane pins                                : 4
**            Frontplane pin0                              : 
**              Frontplane  pin                            : LCD_P40/PTD0/SPI0_PCS0/TPM0_CH0
**              Frontplane pin signal                      : 
**            Frontplane pin1                              : 
**              Frontplane  pin                            : LCD_P52/PTE4/SPI1_PCS0
**              Frontplane pin signal                      : 
**            Frontplane pin2                              : 
**              Frontplane  pin                            : LCD_P19/PTB23
**              Frontplane pin signal                      : 
**            Frontplane pin3                              : 
**              Frontplane  pin                            : LCD_P18/PTB22
**              Frontplane pin signal                      : 
**          Initialization                                 : 
**            Enable in init. code                         : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnFaultDetectComplete                      : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init              - LDD_TDeviceData* myLCD_Init(LDD_TUserData *UserDataPtr);
**         SetFrontplaneData - LDD_TError myLCD_SetFrontplaneData(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file myLCD.c
** @version 01.06
** @brief
**         This component "SegLCD_LDD" implements the segment Liquid Crystal Display (SegLCD)
**         driver module. It can drive an LCD which is composed of variable number
**         of frontplanes and backplanes. It can control also current mode of display.
*/         
/*!
**  @addtogroup myLCD_module myLCD module documentation
**  @{
*/         

/* MODULE myLCD. */
/*lint -save  Disable MISRA rule () checking. */

#include "myLCD.h"
#include "LCD_PDD.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} myLCD_TDeviceData;

typedef myLCD_TDeviceData *myLCD_TDeviceDataPtr; /* Pointer to the device data structure. */


/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static myLCD_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define  BACKPLANE_NUMBER        0x08U
#define  FRONTPLANE_NUMBER       0x04U

static const uint8_t FrontplaneLCDxxPin[FRONTPLANE_NUMBER] = {0x28U, 0x34U, 0x13U, 0x12U}; /* List of used LCDxx frontplane pin */


/*
** ===================================================================
**     Method      :  myLCD_Init (component SegLCD_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the device data structure.
*/
/* ===================================================================*/
LDD_TDeviceData* myLCD_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate HAL device structure */
  myLCD_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* SIM_SCGC5: SLCD=1 */
  SIM_SCGC5 |= SIM_SCGC5_SLCD_MASK;
  /* LCD_GCR: LCDEN=0 */
  LCD_GCR &= (uint32_t)~(uint32_t)(LCD_GCR_LCDEN_MASK); /* Disable LCD device */
  /* PORTC_PCR17: ISF=0,MUX=0 */
  PORTC_PCR17 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR21: ISF=0,MUX=0 */
  PORTB_PCR21 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR7: ISF=0,MUX=0 */
  PORTB_PCR7 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR8: ISF=0,MUX=0 */
  PORTB_PCR8 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTE_PCR5: ISF=0,MUX=0 */
  PORTE_PCR5 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTC_PCR18: ISF=0,MUX=0 */
  PORTC_PCR18 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR10: ISF=0,MUX=0 */
  PORTB_PCR10 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR11: ISF=0,MUX=0 */
  PORTB_PCR11 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTD_PCR0: ISF=0,MUX=0 */
  PORTD_PCR0 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTE_PCR4: ISF=0,MUX=0 */
  PORTE_PCR4 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR23: ISF=0,MUX=0 */
  PORTB_PCR23 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* PORTB_PCR22: ISF=0,MUX=0 */
  PORTB_PCR22 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));
  /* LCD_GCR: RVEN=0,??=0,??=0,??=0,RVTRIM=0,CPSEL=1,??=0,LADJ=3,??=0,??=0,VSUPPLY=0,??=0,PADSAFE=0,FDCIEN=0,ALTDIV=0,ALTSOURCE=0,FFR=1,LCDDOZE=0,LCDSTP=0,LCDEN=0,SOURCE=1,LCLK=4,DUTY=7 */
  LCD_GCR = LCD_GCR_RVTRIM(0x00) |
            LCD_GCR_CPSEL_MASK |
            LCD_GCR_LADJ(0x03) |
            LCD_GCR_ALTDIV(0x00) |
            LCD_GCR_FFR_MASK |
            LCD_GCR_SOURCE_MASK |
            LCD_GCR_LCLK(0x04) |
            LCD_GCR_DUTY(0x07);        /* Set general control register */
  /* LCD_AR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0,BLINK=0,ALT=0,BLANK=0,??=0,BMODE=0,BRATE=0 */
  LCD_AR = (LCD_AR_BRATE(0x00) | 0x8000U); /* Set auxillary register */
  /* LCD_PENL: PEN=0x000E0D80 */
  LCD_PENL = LCD_PEN_PEN(0x000E0D80);  /* Set pin enable register low */
  /* LCD_PENH: PEN=0x00300160 */
  LCD_PENH = LCD_PEN_PEN(0x00300160);  /* Set pin enable register high */
  /* LCD_BPENL: BPEN=0x00020D80 */
  LCD_BPENL = LCD_BPEN_BPEN(0x00020D80); /* Set backplane enable register low */
  /* LCD_BPENH: BPEN=0x00200060 */
  LCD_BPENH = LCD_BPEN_BPEN(0x00200060); /* Set backplane enable register high */
  /* LCD_WF3TO0: WF3=0,WF2=0,WF1=0,WF0=0 */
  LCD_WF3TO0 = LCD_WF_WF3(0x00) |
               LCD_WF_WF2(0x00) |
               LCD_WF_WF1(0x00) |
               LCD_WF_WF0(0x00);       /* Clear waveform register */
  /* LCD_WF7TO4: WF7=4,WF6=0,WF5=0,WF4=0 */
  LCD_WF7TO4 = LCD_WF_WF7(0x04) |
               LCD_WF_WF6(0x00) |
               LCD_WF_WF5(0x00) |
               LCD_WF_WF4(0x00);       /* Configure which phase the backplane pins are active in. */
  /* LCD_WF11TO8: WF11=0x80,WF10=0x40,WF9=0,WF8=8 */
  LCD_WF11TO8 = LCD_WF_WF11(0x80) |
                LCD_WF_WF10(0x40) |
                LCD_WF_WF9(0x00) |
                LCD_WF_WF8(0x08);      /* Configure which phase the backplane pins are active in. */
  /* LCD_WF15TO12: WF15=0,WF14=0,WF13=0,WF12=0 */
  LCD_WF15TO12 = LCD_WF_WF15(0x00) |
                 LCD_WF_WF14(0x00) |
                 LCD_WF_WF13(0x00) |
                 LCD_WF_WF12(0x00);    /* Clear waveform register */
  /* LCD_WF19TO16: WF19=0,WF18=0,WF17=2,WF16=0 */
  LCD_WF19TO16 = LCD_WF_WF19(0x00) |
                 LCD_WF_WF18(0x00) |
                 LCD_WF_WF17(0x02) |
                 LCD_WF_WF16(0x00);    /* Configure which phase the backplane pins are active in. */
  /* LCD_WF23TO20: WF23=0,WF22=0,WF21=0,WF20=0 */
  LCD_WF23TO20 = LCD_WF_WF23(0x00) |
                 LCD_WF_WF22(0x00) |
                 LCD_WF_WF21(0x00) |
                 LCD_WF_WF20(0x00);    /* Clear waveform register */
  /* LCD_WF27TO24: WF27=0,WF26=0,WF25=0,WF24=0 */
  LCD_WF27TO24 = LCD_WF_WF27(0x00) |
                 LCD_WF_WF26(0x00) |
                 LCD_WF_WF25(0x00) |
                 LCD_WF_WF24(0x00);    /* Clear waveform register */
  /* LCD_WF31TO28: WF31=0,WF30=0,WF29=0,WF28=0 */
  LCD_WF31TO28 = LCD_WF_WF31(0x00) |
                 LCD_WF_WF30(0x00) |
                 LCD_WF_WF29(0x00) |
                 LCD_WF_WF28(0x00);    /* Clear waveform register */
  /* LCD_WF35TO32: WF35=0,WF34=0,WF33=0,WF32=0 */
  LCD_WF35TO32 = LCD_WF_WF35(0x00) |
                 LCD_WF_WF34(0x00) |
                 LCD_WF_WF33(0x00) |
                 LCD_WF_WF32(0x00);    /* Clear waveform register */
  /* LCD_WF39TO36: WF39=0,WF38=0x20,WF37=1,WF36=0 */
  LCD_WF39TO36 = LCD_WF_WF39(0x00) |
                 LCD_WF_WF38(0x20) |
                 LCD_WF_WF37(0x01) |
                 LCD_WF_WF36(0x00);    /* Configure which phase the backplane pins are active in. */
  /* LCD_WF43TO40: WF43=0,WF42=0,WF41=0,WF40=0 */
  LCD_WF43TO40 = LCD_WF_WF43(0x00) |
                 LCD_WF_WF42(0x00) |
                 LCD_WF_WF41(0x00) |
                 LCD_WF_WF40(0x00);    /* Clear waveform register */
  /* LCD_WF47TO44: WF47=0,WF46=0,WF45=0,WF44=0 */
  LCD_WF47TO44 = LCD_WF_WF47(0x00) |
                 LCD_WF_WF46(0x00) |
                 LCD_WF_WF45(0x00) |
                 LCD_WF_WF44(0x00);    /* Clear waveform register */
  /* LCD_WF51TO48: WF51=0,WF50=0,WF49=0,WF48=0 */
  LCD_WF51TO48 = LCD_WF_WF51(0x00) |
                 LCD_WF_WF50(0x00) |
                 LCD_WF_WF49(0x00) |
                 LCD_WF_WF48(0x00);    /* Clear waveform register */
  /* LCD_WF55TO52: WF55=0,WF54=0,WF53=0x10,WF52=0 */
  LCD_WF55TO52 = LCD_WF_WF55(0x00) |
                 LCD_WF_WF54(0x00) |
                 LCD_WF_WF53(0x10) |
                 LCD_WF_WF52(0x00);    /* Configure which phase the backplane pins are active in. */
  /* LCD_WF59TO56: WF59=0,WF58=0,WF57=0,WF56=0 */
  LCD_WF59TO56 = LCD_WF_WF59(0x00) |
                 LCD_WF_WF58(0x00) |
                 LCD_WF_WF57(0x00) |
                 LCD_WF_WF56(0x00);    /* Clear waveform register */
  /* LCD_WF63TO60: WF63=0,WF62=0,WF61=0,WF60=0 */
  LCD_WF63TO60 = LCD_WF_WF63(0x00) |
                 LCD_WF_WF62(0x00) |
                 LCD_WF_WF61(0x00) |
                 LCD_WF_WF60(0x00);    /* Clear waveform register */
    LCD_PDD_EnableDevice(LCD_BASE_PTR,PDD_ENABLE); /* Enable device */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_myLCD_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the data data structure */
}

/*
** ===================================================================
**     Method      :  myLCD_SetFrontplaneData (component SegLCD_LDD)
*/
/*!
**     @brief
**         Set data to the LCD frontplane data registers. It
**         sets/clears all used segments.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer.
**     @param
**         Index           - Index of frontplane waveform. Value
**                           corresponds with the index frontplane pins,
**                           what is connected to LCD segment.
**     @param
**         Data            - Value of the frontplane segment. Each
**                           value is the array boolean, word - that
**                           defines state of an LCD segment (On - 1/Off
**                           - 0). Bit position of the word (number of
**                           backplane..0), when is segment on/off,
**                           corresponds with the value of backplane
**                           pins index.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_INDEX - Value of index is out of
**                           range.
**                           ERR_PARAM_DATA - Value of frontplane is out
**                           of range.
*/
/* ===================================================================*/
LDD_TError myLCD_SetFrontplaneData(LDD_TDeviceData *DeviceDataPtr, LDD_SegLCD_TPinIndex Index, LDD_SegLCD_TFrontplaneData Data)
{
  myLCD_TDeviceData *DeviceDataPrv = (myLCD_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;                 /* Parameter is not used, suppress unused argument warning */
  /* FrontPlane index value test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if(Index >= FRONTPLANE_NUMBER) {     /* Is the parameter Index within an expected range? */
    return ERR_PARAM_INDEX;            /* If no then error. */
  }
  LCD_PDD_SetWaveform(LCD_BASE_PTR,FrontplaneLCDxxPin[Index],Data);
  return ERR_OK;
}

/*lint -restore Enable MISRA rule () checking. */
/* END myLCD. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/