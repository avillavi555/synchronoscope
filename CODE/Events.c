/** ###################################################################
**     Filename  : Events.C
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
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "stdio.h"
#include "secuencia_fase.h"
#include "Condiciones.h"





#define NoMUESTRAS_ADC   96    
#define NoFASES          6


unsigned short tabla_adc[6];
word lec_adc[NoFASES][NoMUESTRAS_ADC];
int cont_adc=0;





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
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
  
  AD1_Measure(0);
  
  Bit1_NegVal();   
  
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     From bean   :  AD1 [POT_ADC8_SCI]
**     Description :
**         This event is called after the measurement (which
**         consists of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
  
  AD1_GetValue(&tabla_adc[0]);
    
  lec_adc[0][cont_adc]=tabla_adc[0];
  lec_adc[1][cont_adc]=tabla_adc[1];
  lec_adc[2][cont_adc]=tabla_adc[2];
  lec_adc[3][cont_adc]=tabla_adc[3];
  lec_adc[4][cont_adc]=tabla_adc[4];
  lec_adc[5][cont_adc]=tabla_adc[5];/**/
   
   Calc_Frecuencia_parte_inicial(); 
    
   Calc_DFT_parte_inicial();
    
}


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
void Parp_EDOs_OnInterrupt(void)
{
  /* Write your code here ... */

if(Cont_p_abrir_candado)
  {
   Cont_aux++;
   if(Cont_aux==4) 
     {
     if(Cont_seg)
        Cont_seg--;
     Cont_aux=0;
     }
  }
else
  Cont_seg=4;


LEDs_Estados_VTL();

LEDs_Comandos_VTL();

LEDs_Sec_Fase_VTL(); 


}


/* END Events */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [03.89]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
