#include "Depuracion_Hyperterminal.h"
#include "DFT.h"
#include "stdio.h"


#define NoMUESTRAS_ADC   96    





extern word    lec_adc[NoFASES][NoMUESTRAS_ADC];




void    depurador_Hyper(void)
{


  char buffer[40];
  

 /*sprintf(buffer,"OTRO CICLO\t\r\n\n\n\n\n");   
 TxMen(buffer);*/               
                              
 /*for(i=0;i<NoMUESTRAS_ADC;i++) 
    { 
    sprintf(buffer,"%d\t%d\t%d\t\r\n",Lec_ADC[0][i],Lec_ADC[1][i],Lec_ADC[2][i]);   
    TxMen(buffer);            
    }*/   
    
        //un canal
 /*for(i=0;i<NoMUESTRAS_ADC;i++) 
    { 
    sprintf(buffer,"%d\t\r\n",lec_adc[0][i]);   
    TxMen(buffer);            
    }*/  
     
 // Para depurar la raiz.
 /*sprintf(buffer,"%d\t%d\t\r\n",aux_radicando,aux_raiz);   
 TxMen(buffer);            
    */  
    
  // una Fase.
 /*sprintf(buffer,"%d\t\r\n",Mag_Fase[0][1]);   
 TxMen(buffer);*/    

  //dos Fases.
 /*sprintf(buffer,"%d\t%d\t\r\n",Mag_Fase[0][1],Mag_Fase[1][1]);   
 TxMen(buffer);*/    

 // Para depurar la frecuencia.
 /*sprintf(buffer,"%d\t%d\t%d\t%d\t%d\t%ld\t\r\n",vector[0][0],vector[0][1],vector[0][2],vector[0][3],vector[0][4],Periodo);   
 TxMen(buffer);*/
  
 // Para depurar la frecuencia. Periodo
 /*if( cont_T_VTL==24) 
   {
   sprintf(buffer,"%ld\t%ld\t %d\t%d\t%d\t%d\t\r\n",Frecuencia,Periodo, Periodo,t_ini_rec,t_fin_rec,cont_T_VTL);   
   TxMen(buffer);
   }*/
   
 // Para depurar la frecuencia. Periodo
 /*if( cont_T_VTL==24) 
   {
   sprintf(buffer,"%ld\t\r\n",Periodo);   
   TxMen(buffer);
   }*/
     
 //3 Fases.
 /*sprintf(buffer,"%d\t%d\t%d\t\r\n",Mag_Fase[0][1],Mag_Fase[1][1],Mag_Fase[2][1]);   
 TxMen(buffer);*/    

  //Mag, Fases y desfasamientos.
 /*sprintf(buffer,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\r\n",Mag_Fase[0][0],Mag_Fase[0][1],Mag_Fase[1][0],Mag_Fase[1][1],Mag_Fase[2][0],Mag_Fase[2][1],Defasamiento12_13_23[0],Defasamiento12_13_23[1],Defasamiento12_13_23[2]);   
 TxMen(buffer);*/     
 
  //Mag, Fases.
 /*sprintf(buffer,"%d\t%d\t%d\t%d\t%d\t%d\t\r\n",Mag_Fase[0][0],Mag_Fase[0][1],Mag_Fase[1][0],Mag_Fase[1][1],Mag_Fase[2][0],Mag_Fase[2][1]);   
 TxMen(buffer);*/
      
  //Mag
 /*sprintf(buffer,"%d\t%d\t%d\t\r\n",Mag_Fase[0][0],Mag_Fase[1][0],Mag_Fase[2][0]);   
 TxMen(buffer);*/     

  //Fases y desfasamientos.
 /*sprintf(buffer,"%d\t%d\t%d\t%d\t%d\t%d\t\r\n",Mag_Fase[0][1],Mag_Fase[1][1],Mag_Fase[2][1],Defasamiento12_13_23[0],Defasamiento12_13_23[1],Defasamiento12_13_23[2]);   
 TxMen(buffer);*/    
 
}




void TxMen(char *apmen)

{
	char dato;
	char buffer;
	
	dato=*apmen;
	while(dato!='\n')
		{
     do
  		 {
  			buffer=AS1_GetCharsInTxBuf();
  		 }	while(buffer!=0);
				
			AS1_SendChar(*apmen);					
  		apmen++;
  		dato=*apmen;			
		}
}


