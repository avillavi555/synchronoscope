#include "secuencia_fase.h"
#include "Frecuencimetro.h"
#include "LEDs_Sincronoscopio_VTL.h"
#include "Comandos_sincronoscopio.h"
#include "CFE_GEN_VTL.h"
#include "LEDs_edos_VTL.h"
#include "Estados.h"
#include "VTL.h"




void Estados_VTL() 
{
  

    switch(edo_synch) 
      {
        
        
        
        case(EDO_FUERA_INICIO):
          {
           Clr_LEDs_Sincronoscopio_VTL();
           Clr_LEDs_Comandos_Synch();
           Clr_CFE_GEN_VTL();
           Frecuencia_VTL=0;
          }
        break;
           
           
           
        case(EDO_NORMAL):
          {
           Clr_LEDs_Sincronoscopio_VTL();
           Clr_LEDs_Comandos_Synch();
          }
        break;



        case(EDO_SINCRONIZANDO): 
          {
          }
        break;
           
           
           
        case(EDO_SINCRONIZADO):
          {
           CFE_GEN_VTL();
           sincronoscopio_VTL();
          }
        break;



        default: 
        break;
      }
      
}
