#include "Frecuencimetro.h"
#include "stdio.h"
#include "PE_Types.h"
#include "DFT.h"



#define FACTOR_Q15       32768        //  2^15=32768
#define ESCALAM_FREC     18878305734  //18877813806//18828440724//18874368000//18284931681 
#define LONG_MEDIANA     5
#define OFFSET           2210         //  OFFSET de los canales del ADC.  


int Fcia_Canal=3;      //  0-L1, 1-L2, 2-L3, 3-G1, 4-G2 y 5-G3.
 




uint32_t Frecuencia,Frecuencia_VTL; 
extern unsigned short fcia_ini_fin_cont[3];
extern int calc_Fcia;


int cont_cada_x_muestras=0;
unsigned short val_act_adc,val_ant_adc;
unsigned short fcia_ini_fin_cont[3];
unsigned short cont_T;//cont_T:=contador de periodos de muestreo.


int calc_Fcia=0;


void Calc_Frecuencia_parte_inicial(void) 
{

  cont_cada_x_muestras++; 
  if(cont_cada_x_muestras==4)
    {
    val_act_adc=tabla_adc[Fcia_Canal];
    cont_T++;
    if((val_act_adc>=OFFSET)&&(val_ant_adc<OFFSET)) 
      {
      fcia_ini_fin_cont[0]=val_ant_adc;
      fcia_ini_fin_cont[1]=val_act_adc;
      fcia_ini_fin_cont[2]=cont_T;
      calc_Fcia=1;
      cont_T=0;
      }//Fin de buscando finales
    val_ant_adc=val_act_adc;
    cont_cada_x_muestras=0;
    
    }//Fin de if cont_cada_x_muestras/**/

}


void Calc_Frecuencia_parte_final(void)
{

int i,j;
static unsigned short t_ini_rec,t_fin_rec;
uint32_t Periodo,aux_Frec; 
static uint32_t mediana_Frec[LONG_MEDIANA],mediana_Frec_aux[LONG_MEDIANA];

 if(Mag_Fase[3][0]<50) 
   {
    if(Mag_Fase[4][0]>50)
       Fcia_Canal=4;
    else 
      {
      if(Mag_Fase[5][0]>50)
        Fcia_Canal=5;
      else
        Frecuencia=0;
      }
   }

  t_fin_rec=FACTOR_Q15-Interpolacion(fcia_ini_fin_cont[0],fcia_ini_fin_cont[1]);
  Periodo=t_ini_rec-t_fin_rec+4*fcia_ini_fin_cont[2]*FACTOR_Q15;
  for(i=(LONG_MEDIANA-2);i>=0;i--)//Recorre el vector para el nuevo dato
    mediana_Frec[i+1]=mediana_Frec[i];
  mediana_Frec[0]=ESCALAM_FREC/Periodo;
  for(i=0;i<LONG_MEDIANA;i++)//aux sirve para acomodar el vector y mostrar resultado
    mediana_Frec_aux[i]=mediana_Frec[i];
  
  for(i=0;i<=(LONG_MEDIANA-2);i++)
    for(j=(i+1);j<=(LONG_MEDIANA-1);j++)
      if(mediana_Frec_aux[i]>mediana_Frec_aux[j])
        {
         aux_Frec=mediana_Frec_aux[i];
         mediana_Frec_aux[i]=mediana_Frec_aux[j];
         mediana_Frec_aux[j]=aux_Frec;
        }
  Frecuencia=mediana_Frec_aux[2];
  t_ini_rec=t_fin_rec;
  calc_Fcia=0;
  
  Frecuencia_VTL=Frecuencia;
}




unsigned short Interpolacion(unsigned short y1,unsigned short y2) 
{
  static unsigned short x;
  
  if((y2-y1)!=0)
    x=((OFFSET-y1)*FACTOR_Q15)/(y2-y1);
  return(x);/**/

}

