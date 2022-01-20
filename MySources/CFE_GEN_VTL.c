#include "CFE_GEN_VTL.h"
#include "DFT.h"



int32_t Mag_Fase_VTL[NoFASES][NoDIMENSIONES];      




void    CFE_GEN_VTL(void)
{

int i,j;
 // Copia de Magnitud y Fase para VTL
    for(i=0;i<NoFASES;i++)
        for(j=0;j<NoDIMENSIONES;j++)
          Mag_Fase_VTL[i][j]=Mag_Fase[i][j];/**/ 

}

void    Clr_CFE_GEN_VTL(void)
{
int i,j;

 // Copia de Magnitud y Fase para VTL
    for(i=0;i<NoFASES;i++)
        for(j=0;j<NoDIMENSIONES;j++)
          Mag_Fase_VTL[i][j]=0;/**/ 

}

void    Clr_GEN_VTL(void)
{
int i,j;

 // Copia de Magnitud y Fase para VTL
    for(i=3;i<NoFASES;i++)
        for(j=0;j<NoDIMENSIONES;j++)
          Mag_Fase_VTL[i][j]=0;/**/ 

}


void    CFE_VTL(void)
{

int i,j;
 // Copia de Magnitud y Fase para VTL
    for(i=0;i<3;i++)
        for(j=0;j<NoDIMENSIONES;j++)
          Mag_Fase_VTL[i][j]=Mag_Fase[i][j];/**/ 

}

void    CFE_GENVrms_VTL(void)
{
int i,j;
  // Copia de Magnitud y Fase para VTL
  for(i=0;i<6;i++)
    for(j=0;j<NoDIMENSIONES;j++)
      {
      Mag_Fase_VTL[i][j]=Mag_Fase[i][j]; 
      if(i>2) 
        j++;//Para q no copie las fases de GEN a VTL
      }
}/**/

