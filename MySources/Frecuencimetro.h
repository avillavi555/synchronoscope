#include "PE_Types.h"


#define NoFASES 6
#define NoDIMENSIONES 2



extern  uint32_t Frecuencia,Frecuencia_VTL;
extern  unsigned short tabla_adc[6];
extern int calc_Fcia;
extern  int Fcia_Canal;      //  0-L1, 1-L2, 2-L3, 3-G1, 4-G2 y 5-G3.




void    Calc_Frecuencia_parte_inicial(void); 
void    Calc_Frecuencia_parte_final(void);
unsigned short Interpolacion(unsigned short,unsigned short);
