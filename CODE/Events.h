/** ###################################################################
**     Filename  : Events.H
**     Project   : DFT_3FASES
**     Processor : MCF51QE128LQFP64
**     Beantype  : Events
**     Version   : Driver 01.02
**     Compiler  : CodeWarrior ColdFireV1 C Compiler
**     Date/Time : 19/09/2007, 07:41 p.m.
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         AS1_OnRxChar    - void AS1_OnRxChar(void);
**         AS1_OnTxChar    - void AS1_OnTxChar(void);
**         AD1_OnEnd       - void AD1_OnEnd(void);
**         TI1_OnInterrupt - void TI1_OnInterrupt(void);
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "TI1.h"
#include "Bit1.h"
#include "AD1.h"
#include "Bit2.h"
#include "AS1.h"
#include "Bit3.h"
#include "REELE_GEN.h"
#include "REELE_CFE.h"
#include "Parp_EDOs.h"

void AD1_OnEnd(void);
/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     From bean   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which
**         consists of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void TI1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     From bean   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the bean is enabled - <"Enable"> and the events are
**         enabled - <"EnableEvent">). This event is enabled only if
**         a interrupt service/event is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


void AS1_OnRxChar(void);
/*
** ===================================================================
**     Event       :  AS1_OnRxChar (module Events)
**
**     From bean   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is
**         received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the
**         <Receiver> property is enabled or the <SCI output mode>
**         property (if supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void ENABLE_CFE_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  ENABLE_CFE_OnInterrupt (module Events)
**
**     From bean   :  ENABLE_CFE [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void DISABLE_CFE_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  DISABLE_CFE_OnInterrupt (module Events)
**
**     From bean   :  DISABLE_CFE [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Parp_EDOs_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Parp_EDOs_OnInterrupt (module Events)
**
**     From bean   :  Parp_EDOs [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the bean is enabled - <"Enable"> and the events are
**         enabled - <"EnableEvent">). This event is enabled only if
**         a interrupt service/event is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void APAGAR_GEN_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  APAGAR_GEN_OnInterrupt (module Events)
**
**     From bean   :  APAGAR_GEN [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [03.89]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
