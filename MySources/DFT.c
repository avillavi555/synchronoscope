#include "DFT.h"
#include "stdio.h"
#include "PE_Types.h"
#include "Bit2.h"



#define FACTOR_1        98304         //  (NoMUESTRAS_ADC/2)*FACTOR_Q11
#define DIF_dFASES      1             //  Calcula Dif d fases: 1:=L1&G1; 2:=L1&G1 & L2&G2; 3:=L1&G1 & L2&G2 & L3&G3. 
#define NoELEMENTOS_TABLA_SEC 65      //  De 0--->64
#define NoFASES         6
#define NoDIMENSIONES   2
#define NoMUESTRAS_ADC   96    

int calc_DFT=0;



//  VINT16 Tabla_COS[] y SEN[] "DFT", 96 valores.txt
VINT16 TABLA_COS[NoMUESTRAS_ADC] = {2048,2043,2030,2008,1978,1939,1892,1836,1773,1702,1624,1539,1448,1350,1246,1137,1024,905,783,658,530,399,267,133,0,-134,-268,-400,-531,-659,-784,-906,-1024,-1138,-1247,-1351,-1449,-1540,-1625,-1703,-1774,-1837,-1893,-1940,-1979,-2009,-2031,-2044,-2048,-2044,-2031,-2009,-1979,-1940,-1893,-1837,-1774,-1703,-1625,-1540,-1449,-1351,-1247,-1138,-1024,-906,-784,-659,-531,-400,-268,-134,-1,133,267,399,530,658,783,905,1024,1137,1246,1350,1448,1539,1624,1702,1773,1836,1892,1939,1978,2008,2030,2043};
VINT16 TABLA_SEN[NoMUESTRAS_ADC] = {0,133,267,399,530,658,783,905,1024,1137,1246,1350,1448,1539,1624,1702,1773,1836,1892,1939,1978,2008,2030,2043,2048,2043,2030,2008,1978,1939,1892,1836,1773,1702,1624,1539,1448,1350,1246,1137,1024,905,783,658,530,399,267,133,0,-134,-268,-400,-531,-659,-784,-906,-1024,-1138,-1247,-1351,-1449,-1540,-1625,-1703,-1774,-1837,-1893,-1940,-1979,-2009,-2031,-2044,-2048,-2044,-2031,-2009,-1979,-1940,-1893,-1837,-1774,-1703,-1625,-1540,-1449,-1351,-1247,-1138,-1024,-906,-784,-659,-531,-400,-268,-134};

VUINT16 TABLA_SEC[NoELEMENTOS_TABLA_SEC] = {9000,8910,8820,8731,8641,8551,8462,8372,8281,8191,8101,8010,7919,7828,7736,7644,7552,7459,7366,7272,7179,7084,6989,6893,6797,6700,6603,6504,6405,6305,6204,6102,6000,5896,5791,5684,5577,5468,5357,5245,5131,5016,4898,4778,4656,4532,4404,4274,4140,4003,3862,3716,3565,3409,3246,3075,2895,2704,2500,2279,2036,1761,1436,1014,0};

int32_t Dif_Fases[3];
int32_t Mag_Fase[NoFASES][NoDIMENSIONES];

int32_t Re_Im[NoFASES][NoDIMENSIONES];
int32_t Re_Im_aux[NoFASES][NoDIMENSIONES];





void    Calc_DFT_parte_inicial(void)
{
  int k,l;

  for(k=0;k<NoFASES;k++) 
     {
      Re_Im_aux[k][0]=Re_Im_aux[k][0]+tabla_adc[k]*TABLA_COS[cont_adc]; // Re.
      Re_Im_aux[k][1]=Re_Im_aux[k][1]+tabla_adc[k]*TABLA_SEN[cont_adc]; // Im.
     } 
 
  cont_adc++;
  

  if(cont_adc==NoMUESTRAS_ADC)    // Respaldo y cambio al main  
     {
      for(k=0;k<NoFASES;k++) 
          for(l=0;l<NoDIMENSIONES;l++) 
             {
              Re_Im[k][l]=Re_Im_aux[k][l];
              Re_Im_aux[k][l]=0;
             }

      cont_adc=0;
      calc_DFT=1;
      Bit2_NegVal();   
     }

}



void    Calc_DFT_parte_final(void)
{

  int i;
  int32_t cociente;


  for(i=0;i<NoFASES;i++)//1;i++)//3;i++) 
    {
                                        // FACTOR_1:=
    Re_Im[i][0]=Re_Im[i][0]/FACTOR_1;   // (Re_Im[x][x]/(NoMUESTRAS_ADC/2))/FACTOR_Q11)
    Re_Im[i][1]=Re_Im[i][1]/FACTOR_1;   // (Re_Im[x][x]/(MITAD_NoMUESTRAS_ADC))/FACTOR_Q11)
    

    Mag_Fase[i][0]=Re_Im[i][0]*Re_Im[i][0]+Re_Im[i][1]*Re_Im[i][1];
    Mag_Fase[i][0]=raiz(Mag_Fase[i][0]);


    if(Mag_Fase[i][0]!=0)
       cociente=(Re_Im[i][0]*4096)/Mag_Fase[i][0];  
    else
       cociente=0;
    
                 
    Mag_Fase[i][1]=Fase(cociente);
    
    
    if((Re_Im[i][0]<0)&&(Re_Im[i][1]>0))    
       Mag_Fase[i][1]=18000-Mag_Fase[i][1];
     
    if((Re_Im[i][0]<=0)&&(Re_Im[i][1]<0))  
       Mag_Fase[i][1]=18000+Mag_Fase[i][1];
    
    if((Re_Im[i][0]>0)&&(Re_Im[i][1]<0))    
       Mag_Fase[i][1]=36000-Mag_Fase[i][1];
       
    if((Re_Im[i][0]<0)&&(Re_Im[i][1]==0))    
       Mag_Fase[i][1]+=18000;
     
    }//Fin del 1er for  /**/
    
    
   // Ajuste de angulos para synchronoscopio
  for(i=0;i<DIF_dFASES;i++)
    {
    Dif_Fases[i]=Mag_Fase[i][1]-Mag_Fase[i+3][1]; 
               
    if(Dif_Fases[i]>18000)
    Dif_Fases[i]=Dif_Fases[i]-36000;
       
    if(Dif_Fases[i]<-18000)
      Dif_Fases[i]=Dif_Fases[i]+36000;
    }
       
  calc_DFT=0;
}



VUINT32 raiz(VUINT32 x)          
{
  VUINT32 r=x,t=0;
  
  if(x>0)
     do {
         t = r;
         r = (x/r + r)/2;
        } while(t>r);
     
  return t;
}



int32_t Fase(int32_t val)                
{
  VUINT16 mult=NoELEMENTOS_TABLA_SEC-1;  
  VUINT16 x,y,x1,y1,x2,y2;
  VUINT16 i=0,j=0;                       
 
  if(val<0) 
     val=-val;       //signado de 32 siempre positivo.
  
     
  x=val;   
 
  do{                                    
     j=i*mult;
     i++;
     }while(x>j);/**/
     
  if(x==0)
     i=2;    
     
  x1=(i-2)*mult;
  x2=(i-1)*mult;
  y1=TABLA_SEC[i-2];   
  y2=TABLA_SEC[i-1];
  
  y=((y2-y1)/(x2-x1))*(x-x1)+y1;
    
  return y;
}

