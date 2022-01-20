#include "LEDs_Sincronoscopio_VTL.h"
#include "DFT.h"
#include "stdio.h"
#include "PE_Types.h"
#include "Comandos_sincronoscopio.h"
#include "LEDs_Comandos_VTL.h"
#include "secuencia_fase.h"
#include "LEDs_Edos_VTL.h"
#include "secuencia_fase.h"



bool led_falla_sec_fase=0;


void LEDs_Sec_Fase_VTL() 
{
  if(Fases_CFE_GEN_conectadas&&(!Band_Sec_Fase_OK))
    led_falla_sec_fase++;
  else  
    led_falla_sec_fase=0;
}

