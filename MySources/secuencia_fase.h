#include "DFT.h"





extern  int32_t Mag_Fase[NoFASES][NoDIMENSIONES];


extern	int Band_Sec_Fase_OK;
extern	int sec_pos_CFE_VTL,sec_neg_CFE_VTL;
extern	int sec_pos_GEN_VTL,sec_neg_GEN_VTL;
extern  int   Fases_CFE_GEN_conectadas;




bool    calc_sec_fase(int,int);
