#include "Comandos_sincronoscopio.h"
#include "LEDs_Sincronoscopio_VTL.h"
#include "DFT.h"
#include "stdio.h"
#include "LEDs_Comandos_VTL.h"



//Señales de comando
int band_Fcia_Baja,band_Fcia_Alta,band_Fcia_OK;
int band_Voltaje_Bajo,band_Voltaje_Alto,band_Voltaje_OK;
int band_Angulo_Fase_adelantado,band_Angulo_Fase_atraso,band_Angulo_Fase_OK;
extern uint32_t Frecuencia; 



void    Clr_LEDs_Comandos_Synch(void) 
{
    band_Fcia_OK=0;
    band_Fcia_Baja=0;
    band_Fcia_Alta=0;
    
    band_Voltaje_OK=0;          
    band_Voltaje_Bajo=0;
    band_Voltaje_Alto=0;
      
    band_Angulo_Fase_OK=0;         
    band_Angulo_Fase_adelantado=0; 
    band_Angulo_Fase_atraso=0;
    
    led1_com_VTL=0;
    led2_com_VTL=0;
    led3_com_VTL=0;
    led4_com_VTL=0;
    led5_com_VTL=0;
    led6_com_VTL=0;
        

}


void    comandos_synch(void)
{

 //Señales de comando: Frecuencia. VTL 
  if(!band_Fcia_OK)//Si es < la fcia.
    {
    if(Frecuencia<=5950)//Si es < la fcia.
      {
      band_Fcia_Baja=1;
      band_Fcia_Alta=0;
      }
    if(Frecuencia>=6050)//Si es > la fcia.
      {
      band_Fcia_Baja=0;
      band_Fcia_Alta=1;
      }
    }
  else
    {
    band_Fcia_Baja=0;
    band_Fcia_Alta=0;
    }    
    
 //Señales de comando: Voltaje. VTL 
  if(band_Fcia_OK) 
    {
    if(!band_Voltaje_OK) 
      {
      if(Mag_Fase[3][0]<804) 
        {
        band_Voltaje_Bajo=1;
        band_Voltaje_Alto=0;
        }
      if(Mag_Fase[3][0]>888) 
        {
        band_Voltaje_Bajo=0;
        band_Voltaje_Alto=1;
        }
      } 
    else
      {
      band_Voltaje_Bajo=0;
      band_Voltaje_Alto=0;
      }
    }
 //Señales de comando: Angulos de fases.     
  if(band_Fcia_OK&&band_Voltaje_OK) 
    {
    if(cont_led==0)
      band_Angulo_Fase_OK=1;
    else
      band_Angulo_Fase_OK=0;
    } 
  else  
    band_Angulo_Fase_OK=0;
    
  if(!band_Angulo_Fase_OK) 
    {
    if((cont_led>=1)&&(cont_led<18))
      {
      band_Angulo_Fase_adelantado=1;
      band_Angulo_Fase_atraso=0;    
      }
    if((cont_led<=35)&&(cont_led>18))
      {
      band_Angulo_Fase_adelantado=0;
      band_Angulo_Fase_atraso=1;    
      }
    if(cont_led==18) 
      {
      band_Angulo_Fase_adelantado=1;
      band_Angulo_Fase_atraso=1;    
      }
    } 
  else  
    {
    band_Angulo_Fase_adelantado=0;
    band_Angulo_Fase_atraso=0;    
    }
}

