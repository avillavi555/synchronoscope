#include "LEDs_Edos_VTL.h"
#include "DFT.h"



#define EDO_FUERA_INICIO    101
#define EDO_NORMAL          102
#define EDO_SINCRONIZANDO   103
#define EDO_SINCRONIZADO    104


bool led_FUERA_INICIO_VTL=0;
bool led_NORMAL_VTL=0;
bool led_SINCRONIZANDO_VTL=0;
bool led_SINCRONIZADO_VTL=0;




void LEDs_Estados_VTL(int x)
{
if(edo_synch==EDO_FUERA_INICIO) 
  {
    led_FUERA_INICIO_VTL++;
    led_NORMAL_VTL=0;
    led_SINCRONIZANDO_VTL=0;
    led_SINCRONIZADO_VTL=0;
  }
  
if(edo_synch==EDO_NORMAL) 
  {
    led_FUERA_INICIO_VTL=0;
    led_NORMAL_VTL++;
    led_SINCRONIZANDO_VTL=0;
    led_SINCRONIZADO_VTL=0;
  }
  
if(edo_synch==EDO_SINCRONIZANDO) 
  {
    led_FUERA_INICIO_VTL=0;
    led_NORMAL_VTL=0;
    led_SINCRONIZANDO_VTL++;
    led_SINCRONIZADO_VTL=0;
  }
  
if(edo_synch==EDO_SINCRONIZADO) 
  {
    led_FUERA_INICIO_VTL=0;
    led_NORMAL_VTL=0;
    led_SINCRONIZANDO_VTL=0;
    led_SINCRONIZADO_VTL++;
  }
}

  

