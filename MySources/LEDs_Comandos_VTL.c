#include "LEDs_Sincronoscopio_VTL.h"
#include "DFT.h"
#include "stdio.h"
#include "PE_Types.h"
#include "Comandos_sincronoscopio.h"
#include "LEDs_Comandos_VTL.h"
#include "LEDs_Edos_VTL.h"
  
  

bool led1_com_VTL,led2_com_VTL,led3_com_VTL,led4_com_VTL,led5_com_VTL,led6_com_VTL;

extern int edo_synch;


void LEDs_Comandos_VTL() 

  {
    //Intermitencia de Comandos de Frecuencia.
    if(edo_synch==EDO_SINCRONIZANDO) 
    {
      if(!band_Fcia_OK) 
        {
        if(band_Fcia_Baja) 
          {
          led1_com_VTL++;
          led2_com_VTL=0;
          }
          
        if(band_Fcia_Alta) 
          {
          led2_com_VTL++;
          led1_com_VTL=0;
          }
        } 
      else 
        {    
        led1_com_VTL=0;
        led2_com_VTL=0;
        }

      //Intermitencia de Comandos de Voltaje.
      if(band_Fcia_OK)  
        {
        if(!band_Voltaje_OK)  
          {
          if(band_Voltaje_Bajo)
            {
            led3_com_VTL++;
            led4_com_VTL=0;
            }
            
          if(band_Voltaje_Alto) 
            {
            led4_com_VTL++;
            led3_com_VTL=0;
            }
          } 
        else
          {    
          led4_com_VTL=0;
          led3_com_VTL=0;
          }
        }
      else
        {    
        led4_com_VTL=0;
        led3_com_VTL=0;
        }

      //Intermitencia de Comandos de Angulo de fase.
        if(band_Angulo_Fase_adelantado) 
          {
          led5_com_VTL++;
          led6_com_VTL=0;
          }
        if(band_Angulo_Fase_atraso) 
          {
          led6_com_VTL++;
          led5_com_VTL=0;
          }
        if(band_Angulo_Fase_OK)
          {
          led6_com_VTL=0;
          led5_com_VTL=0;
          }
    } 
  else
    {
    led1_com_VTL=0;
    led2_com_VTL=0;
    led3_com_VTL=0;
    led4_com_VTL=0;
    led5_com_VTL=0;
    led6_com_VTL=0;
    }

  }

