/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Bit3.C
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
**                       21            |  PTC2_RGPIO10_TPM3CH2
**             ----------------------------------------------------
**
**         Port name                   : PTC
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : 0x0004
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : up
**
**         Port data register          : PTCD      [0xFFFF8004]
**         Port control register       : PTCDD     [0xFFFF8005]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Bit3_GetVal(void);
**         PutVal - void Bit3_PutVal(bool Val);
**         ClrVal - void Bit3_ClrVal(void);
**         SetVal - void Bit3_SetVal(void);
**         NegVal - void Bit3_NegVal(void);
**
**     (c) Copyright UNIS, spol. s r.o. 1997-2006
**     UNIS, spol. s r.o.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE Bit3. */

#include "Bit3.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  Bit3_GetVal (bean BitIO)
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
/*
bool Bit3_GetVal(void)

**  This method is implemented as a macro. See Bit3.h file.  **
*/

/*
** ===================================================================
**     Method      :  Bit3_PutVal (bean BitIO)
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
void Bit3_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTCD, 0x04);           /* PTCD2=0x01 */
  } else { /* !Val */
    clrReg8Bits(PTCD, 0x04);           /* PTCD2=0x00 */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  Bit3_ClrVal (bean BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Bit3_ClrVal(void)

**  This method is implemented as a macro. See Bit3.h file.  **
*/

/*
** ===================================================================
**     Method      :  Bit3_SetVal (bean BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Bit3_SetVal(void)

**  This method is implemented as a macro. See Bit3.h file.  **
*/

/*
** ===================================================================
**     Method      :  Bit3_NegVal (bean BitIO)
**
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Bit3_NegVal(void)

**  This method is implemented as a macro. See Bit3.h file.  **
*/


/* END Bit3. */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [03.89]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
