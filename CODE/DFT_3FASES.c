/** ###################################################################
**     Filename  : DFT_3FASES.C
**     Project   : DFT_3FASES
**     Processor : MCF51QE128LQFP64
**     Version   : Driver 01.00
**     Compiler  : CodeWarrior ColdFireV1 C Compiler
**     Date/Time : 19/09/2007, 07:41 p.m.
**     Abstract  :
**         Main module.
**         Here is to be placed user's code.
**     Settings  :
**     Contents  :
**         No public methods
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/
/* MODULE DFT_3FASES */


/* Including used modules for compiling procedure */
#include "Cpu.h"
#include "Events.h"
#include "TI1.h"
#include "Bit1.h"
#include "AD1.h"
#include "Bit2.h"
#include "AS1.h"
#include "Bit3.h"
#include "REELE_GEN.h"
#include "REELE_CFE.h"
#include "Parp_EDOs.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "stdio.h"
#include "secuencia_fase.h"
#include "Frecuencimetro.h"
#include "LEDs_Sincronoscopio_VTL.h"
#include "Comandos_sincronoscopio.h"
#include "CFE_GEN_VTL.h"
#include "LEDs_edos_VTL.h"
#include "Estados.h"


//Estados de sincronia
int edo_synch=EDO_FUERA_INICIO;


void main(void)
{
  /* Write your local variable definition here */
   
                             
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  
  for(;;)
    {
    
    if(calc_DFT)
      Calc_DFT_parte_final(); 
      

    switch(edo_synch) 
      {
        
        
        
        case(EDO_FUERA_INICIO):
          {
            Definicion_EDO_FUERA_INICIO();
            
            if(Monitorea_C1()==0xABCD)
              edo_synch=EDO_NORMAL; 
          }
        break;
           
           
           
        case(EDO_NORMAL):
          {
            Definicion_EDO_NORMAL();
            
            if(Monitorea_C2()==0xABCD)
              edo_synch=EDO_FUERA_INICIO; 
            
            if(Monitorea_C3()==0xABCD)
              edo_synch=EDO_SINCRONIZANDO; 
          }
        break;



        case(EDO_SINCRONIZANDO): 
          {
            Definicion_EDO_SINCRONIZANDO();

            if(Monitorea_C4()==0xABCD)
              edo_synch=EDO_NORMAL; 
          
            if(Monitorea_C5()==0xABCD)
              edo_synch=EDO_SINCRONIZADO; 
          
            if(Monitorea_C6()==0xABCD)
              edo_synch=EDO_FUERA_INICIO; 
          }
        break;
           
           
           
        case(EDO_SINCRONIZADO):
          {
            Definicion_EDO_SINCRONIZADO();
            
            if(Monitorea_C7()==0xABCD)
              edo_synch=EDO_NORMAL; 
          
            if(Monitorea_C8()==0xABCD)
              edo_synch=EDO_FUERA_INICIO; 
          }
        break;



        default: 
        break;
      }



//  Actualiza salidas.
    if(Band_GEN)
      REELE_GEN_PutVal(1);
    else
      REELE_GEN_PutVal(0);

    if(Band_CFE)
      REELE_CFE_PutVal(1);
    else
      REELE_CFE_PutVal(0);
    
    
    Estados_VTL(); 
    
    //depurador_Hyper(); 
 
    Bit3_NegVal();             
        
    }
    

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/


/* END DFT_3FASES */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [03.89]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
