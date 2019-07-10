/* ###################################################################
**     Filename    : Events.c
**     Project     : myProject
**     Processor   : MKL46Z256VLL4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-06-28, 02:53, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"



#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL46Z256MC4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Timer1_OnInterrupt (module Events)
**
**     Component   :  Timer1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Timer1_OnInterrupt(void)
{
  /* Write your code here ... */
	LED_YELLOW_NegVal();
	void* myLcd = myLCD_Init(NULL);
	printNumberLcd(myLcd,count);
	++count;
	
	//LED_YELLOW_NegVal();
}

/*
** ===================================================================
**     Event       :  Button1_OnInterrupt (module Events)
**
**     Component   :  Button1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Button1_OnInterrupt(void)
{
  /* Write your code here ... */
	//LED_RED_NegVal();
}

/*
** ===================================================================
**     Event       :  TSS1_fOnFault (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is called by TSS after Fault
**         occurence. This event is enabled always and depends on
**         selection 'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**         Option is available from TSS3.0 version.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8FaultElecNum  - The value defines
**                           electrode number on which measurement fault
**                           occured.
**     Returns     : Nothing
** ===================================================================
*/
void TSS1_fOnFault(byte u8FaultElecNum)
{
  #if TSS_USE_PE_COMPONENT
  /* If large or small capacitor fault  */
  if(tss_CSSys.Faults.ChargeTimeout || tss_CSSys.Faults.SmallCapacitor)
  {
    /* Write your code here ... */
  }
  /* If data corruption fault  */
  if(tss_CSSys.Faults.DataCorruption)
  {
    /* Write your code here ... */
  }
  /* If small trigger period fault  */
  if(tss_CSSys.Faults.SmallTriggerPeriod)
  {
    /* Write your code here ... */
  }
  /* Clear the fault flags */
  (void) TSS_SetSystemConfig(System_Faults_Register, 0x00);

  (void) u8FaultElecNum;
  return;
  #endif
}

/*
** ===================================================================
**     Event       :  TSS1_fOnInit (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         This callback function is automatically called during the
**         TSS Init function execution. The function is intended for
**         implementation of peripherals initialization. TSS Component
**         automatically enables clock for all used TSS peripherals in
**         the internal function TSS_InitDevices which is called by
**         this callback.
**         This event is enabled always and depends on selection
**         'generate code' if the callback is used.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TSS1_fOnInit(void)
{
  #if TSS_USE_PE_COMPONENT
    TSS1_InitDevices();
  #endif

  /* Write your code here ... */

}

/*
** ===================================================================
**     Event       :  TSS1_fCallBack0 (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         Callback definition for Control 0. This event is enabled
**         only if Control 0 is enabled.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8ControlId     - Valid unique Identifier of
**                           the Control which generated the CallBack
**                           function. This Id can be used for finding
**                           of Callback's source Control.
**     Returns     : Nothing
** ===================================================================
*/





/*
** ===================================================================
**     Event       :  TSS1_fCallBack0 (module Events)
**
**     Component   :  TSS1 [TSS_Library]
**     Description :
**         Callback definition for Control 0. This event is enabled
**         only if Control 0 is enabled.
**         The default CallBack Name is automatically generated with
**         automatic prefix update by current Component Name. User can
**         define own name, but then the automatic name update is not
**         functional.
**     Parameters  :
**         NAME            - DESCRIPTION
**         u8ControlId     - Valid unique Identifier of
**                           the Control which generated the CallBack
**                           function. This Id can be used for finding
**                           of Callback's source Control.
**     Returns     : Nothing
** ===================================================================
*/
void TSS1_fCallBack0(TSS_CONTROL_ID u8ControlId)
{
  if (TSS1_cKey0.DynamicStatus.Movement)
  {
    if (TSS1_cKey0.Events.Touch)
    {
      if (!(TSS1_cKey0.Events.InvalidPos))
      {
        (void) TSS1_cKey0.Position;
        unsigned int sum =0;
        register unsigned char i;
        for (i = 0; i < 5; i++)
        {
          sum+=TSS1_cKey0.Position;
        }
        uint8_t pos = sum/5;

        if(pos>touchSensorValPrevious){
          dutyLight+=5;
        }
        if(pos<touchSensorValPrevious){
          dutyLight-=5;
        }
        if (dutyLight>100) dutyLight =100;
        if (dutyLight <0) dutyLight = 0;
        
        /* Write your code here ... */
        void* myLcd = myLCD_Init(NULL);
        PWM1_SetRatio16(dutyLight*65535/100);
        printNumberLcd(myLcd,dutyLight);

        //
        touchSensorValPrevious = pos;
        
      }
    }
    else 
    {
      /* Write your code here ... */
    }
  
  }

  (void) u8ControlId;
  return;
}

/* END Events */

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
