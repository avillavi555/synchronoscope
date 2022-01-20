#include "Estados.h"
#include "Frecuencimetro.h"
#include "Comandos_sincronoscopio.h"
#include "LEDs_Sincronoscopio_VTL.h"
#include "secuencia_fase.h"
#include "LEDs_edos_VTL.h"
#include "DFT.h"
#include "stdio.h"
#include "PE_Types.h"
#include "Condiciones.h"




void Definicion_EDO_FUERA_INICIO(void)
{
 Band_GEN=0;
 
 Band_CFE=0;               
 
 calc_sec_fase(0,0);       //No determinar secuencias de fases de CFE y GEN.
}



void Definicion_EDO_NORMAL(void)
{
 Band_GEN=0;
 
 Band_CFE=1;               
 
 
 
 
 if(Band_GEN_desincronizado) 
   {
   calc_sec_fase(1,1);       //Determina la secuencia de fase de CFE y GEN.
   
   if(calc_Fcia)             //Calcula la frecuencia del generador.
     Calc_Frecuencia_parte_final();
   
   if((Frecuencia>=5900)&&(Frecuencia<=6100))//Para q no parpadee la visualizacion tanto.
     CFE_GEN_VTL();
   else   
     Clr_GEN_VTL();
   
   }
 else 
   {
   CFE_VTL();
   Clr_GEN_VTL();
   Frecuencia_VTL=0;
   calc_sec_fase(1,0);       //Determina la secuencia de fase de CFE.
   }
 
}



void Definicion_EDO_SINCRONIZANDO(void)
{
 Band_GEN=0;
 
 
 if(calc_Fcia)             //Calcula la frecuencia del generador.
   Calc_Frecuencia_parte_final();
 

 
 if((Frecuencia>=5950)&&(Frecuencia<=6050))//Nivel de frecuencia optimo +/- 0.5Hz.            
   CFE_GEN_VTL();
 else 
   {
   Clr_GEN_VTL(); 
   CFE_VTL();
   }
 
    
}



void Definicion_EDO_SINCRONIZADO(void)
{
 Band_GEN=1;
 
 
 if(calc_Fcia)//Calcula la frecuencia del generador.
   Calc_Frecuencia_parte_final();
}


