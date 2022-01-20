#include "secuencia_fase.h"
#include "stdio.h"




int   Band_Sec_Fase_OK;
int   sec_pos_CFE_VTL,sec_neg_CFE_VTL;
int   sec_pos_GEN_VTL,sec_neg_GEN_VTL;
int   Fases_CFE_GEN_conectadas=0;



// x: 1=Determina sec de CFE. 0=No determinar. 
// y: 1=Determina sec de GEN. 0=No determinar.                                      

bool    calc_sec_fase(int x,int y)
{

int32_t sec_fase[4]; 
int32_t dif1,dif2,dif3;
int  sec_cont=0;
int  sec_pos_CFE=0,sec_neg_CFE=0;
int  sec_pos_GEN=0,sec_neg_GEN=0;
int  Fases_CFE_conectadas=0,Fases_GEN_conectadas=0;

  if(x) 
    {
    if(Mag_Fase[0][0]>50)    
      if(Mag_Fase[1][0]>50)     
        if(Mag_Fase[2][0]>50) 
          {
            Fases_CFE_conectadas=1;
            
            sec_fase[0]=Mag_Fase[0][1]; 
            sec_fase[1]=Mag_Fase[1][1]; 
            sec_fase[2]=Mag_Fase[2][1]; 
            sec_fase[3]=Mag_Fase[0][1]; 

            dif1=sec_fase[0]-sec_fase[1];
            dif2=sec_fase[1]-sec_fase[2];
            dif3=sec_fase[2]-sec_fase[3];

            if(dif1<0)
              sec_cont++;
            if(dif2<0)
              sec_cont++;
            if(dif3<0)
              sec_cont++;

            if(sec_cont==2)   //Secuencia positiva.
              {
              sec_pos_CFE=1;
              sec_neg_CFE=0;
              }
            else              //Secuencia negativa.
              {
              sec_pos_CFE=0;
              sec_neg_CFE=1;
              }
          }
    }
  
  sec_cont=0;
  
  if(y) 
    {
    if(Mag_Fase[3][0]>50)    
      if(Mag_Fase[4][0]>50)     
        if(Mag_Fase[5][0]>50) 
          {
            Fases_GEN_conectadas=1;
            
            sec_fase[0]=Mag_Fase[3][1]; 
            sec_fase[1]=Mag_Fase[4][1]; 
            sec_fase[2]=Mag_Fase[5][1]; 
            sec_fase[3]=Mag_Fase[3][1]; 

            dif1=sec_fase[0]-sec_fase[1];
            dif2=sec_fase[1]-sec_fase[2];
            dif3=sec_fase[2]-sec_fase[3];

            if(dif1<0)
              sec_cont++;
            if(dif2<0)
              sec_cont++;
            if(dif3<0)
              sec_cont++;

            if(sec_cont==2)  //Secuencia positiva.
              {
              sec_pos_GEN=1;
              sec_neg_GEN=0;
              }
            else        //Secuencia negativa.
              {
              sec_pos_GEN=0;
              sec_neg_GEN=1;
              }
          }
    }
    
if(Fases_CFE_conectadas&&Fases_GEN_conectadas) 
  {
  Fases_CFE_GEN_conectadas=1;
  
  if((sec_pos_CFE&&sec_pos_GEN)||(!sec_pos_CFE&&!sec_pos_GEN)) // ¿Ambos sitemas tienen secuencia + o -?.
    Band_Sec_Fase_OK=1;
  else
    Band_Sec_Fase_OK=0;
  } 
else 
  {
  Fases_CFE_GEN_conectadas=0;
  Band_Sec_Fase_OK=0;
  }


sec_pos_CFE_VTL=sec_pos_CFE;
sec_neg_CFE_VTL=sec_neg_CFE;

sec_pos_GEN_VTL=sec_pos_GEN;
sec_neg_GEN_VTL=sec_neg_GEN;

return(Band_Sec_Fase_OK);

}
