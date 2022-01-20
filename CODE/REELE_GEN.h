/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : REELE_GEN.H
**     Project   : DFT_3FASES
**     Processor : MCF51QE128LQFP64
**     Beantype  : BitIO
**     Version   : Bean 02.068, Driver 03.06, CPU db: 3.00.002
**     Compiler  : CodeWarrior ColdFireV1 C Compiler
**     Date/Time : 29/07/2008, 06:32 p.m.
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       5             |  PTE7_RGPIO7_TPM3CLK
**             ----------------------------------------------------
**
**         Port name                   : PTE
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : 0x0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : PTED      [0xFFFF8008]
**         Port control register       : PTEDD     [0xFFFF8009]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool REELE_GEN_GetVal(void);
**         PutVal - void REELE_GEN_PutVal(bool Val);
**         ClrVal - void REELE_GEN_ClrVal(void);
**         SetVal - void REELE_GEN_SetVal(void);
**         NegVal - void REELE_GEN_NegVal(void);
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef REELE_GEN_H_
#define REELE_GEN_H_

/* MODULE REELE_GEN. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  REELE_GEN_GetVal (bean BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define REELE_GEN_GetVal() ( \
    (bool)((getReg8(PTED) & 0x80))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  REELE_GEN_PutVal (bean BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void REELE_GEN_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  REELE_GEN_ClrVal (bean BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define REELE_GEN_ClrVal() ( \
    (void)clrReg8Bits(PTED, 0x80)      /* PTED7=0x00 */ \
  )

/*
** ===================================================================
**     Method      :  REELE_GEN_SetVal (bean BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define REELE_GEN_SetVal() ( \
    (void)setReg8Bits(PTED, 0x80)      /* PTED7=0x01 */ \
  )

/*
** ===================================================================
**     Method      :  REELE_GEN_NegVal (bean BitIO)
**
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define REELE_GEN_NegVal() ( \
    (void)setReg8(PTETOG, 0x80)        /* PTETOG7=0x01 */ \
  )



/* END REELE_GEN. */
#endif /* #ifndef __REELE_GEN_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [03.89]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
