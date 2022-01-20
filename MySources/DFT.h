#include "PE_Types.h"


#define NoFASES 6
#define NoDIMENSIONES 2


extern  int32_t Mag_Fase[NoFASES][NoDIMENSIONES];
extern  int32_t Re_Im[NoFASES][NoDIMENSIONES];
extern  int32_t Dif_Fases[3];
extern  int calc_Fcia;
extern  int calc_DFT;
extern unsigned short tabla_adc[6];
extern int cont_adc;
extern int calc_DFT;





void    Calc_DFT_parte_inicial(void);
void    Calc_DFT_parte_final(void);
VUINT32 raiz(VUINT32);                
int32_t Fase(int32_t);                









