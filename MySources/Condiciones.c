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




int     Band_CFE=0;
int     Band_GEN=0;
int     Band_GEN_desincronizado=0;
int     Cont_seg,Cont_aux,Cont_p_abrir_candado=0;


int Monitorea_C1(void) 
{
 if(Mag_Fase[0][0]>800)
   return(0xABCD);
 else
   return(0);
}



int Monitorea_C2(void)
{
 if(Mag_Fase[0][0]<800)
   return(0xABCD);
 else
   return(0);
}



int Monitorea_C3(void)
{
if(Band_GEN_desincronizado)//Se saco de sincronia y han pasado 4 seg? 
  {
   if(((Mag_Fase[3][0]>100)&&(Mag_Fase[3][0]<200))||(Frecuencia<=3000))
     {
      Cont_p_abrir_candado=1;
      if(!Cont_seg)   
        Band_GEN_desincronizado=0;
     }
   else 
     {
      Cont_p_abrir_candado=0;
      return(0);
     }
   
  } 
else
  {
   if((Mag_Fase[3][0]>50)&&(Mag_Fase[4][0]>50)&&(Mag_Fase[5][0]>50))     //Solicitud de sincronizacion.
     return(0xABCD);
   else
     return(0);
  } 
}



int Monitorea_C4(void)
{
 if((Mag_Fase[3][0]<50)&&(Mag_Fase[4][0]<50)&&(Mag_Fase[5][0]<50))     //El generador es desactivado.
   return(0xABCD);
 else
   return(0);
}



int Monitorea_C5(void)
{
   if(calc_sec_fase(1,1))//Determina la secuencia de fase de CFE y GEN.
     {
       comandos_synch(); 

       if((Frecuencia>=5900)&&(Frecuencia<=6100))//Para q no parpadee la visualizacion tanto.
         CFE_GEN_VTL();
       
       if((Frecuencia>=5950)&&(Frecuencia<=6050))//Nivel de frecuencia optimo +/- 0.5Hz.            
         {
         band_Fcia_OK=1;
         
         if((Mag_Fase[3][0]>804)&&(Mag_Fase[3][0]<888))//Nivel de voltaje optimo    +/- 5% .      
           {
           band_Voltaje_OK=1;          
           sincronoscopio_VTL();
           
           if(cont_led==0)//Nivel de angulo de fase optimo +/- 5°.
             {
             REELE_GEN_PutVal(1);      //Para activar el reelevador del GEN.
             edo_synch=EDO_SINCRONIZADO;
             Band_GEN=1;
             band_Angulo_Fase_OK=1;
             }
           } 
         else 
           {
           band_Voltaje_OK=0;          
           Clr_LEDs_Sincronoscopio_VTL();
           band_Angulo_Fase_OK=0;          
           }
         }
       else
         {
         Clr_LEDs_Sincronoscopio_VTL();
         Clr_GEN_VTL();
         band_Fcia_OK=0;
         band_Voltaje_OK=0;
         band_Angulo_Fase_OK=0;          
         }
     } 
   else 
    Clr_LEDs_Comandos_Synch(); 
   
}



int Monitorea_C6(void)
{
 if((Mag_Fase[0][0]<800)&&(Mag_Fase[1][0]<800)&&(Mag_Fase[2][0]<800))
   return(0xABCD);
 else
   return(0);
}

    

int Monitorea_C7(void)
{
 if(0)
   {
    Band_GEN_desincronizado=1;
    Cont_seg=4; //Inicializa el contador para esperar 4 segundos.
    return(0xABCD);
   }
 else 
   {
    Band_GEN_desincronizado=0;
    return(0);
   }
}



int Monitorea_C8(void)
{
 if(Mag_Fase[0][0]<800)
   return(0xABCD);
 else
   return(0);
}


