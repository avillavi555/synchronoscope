#include "LEDs_Sincronoscopio_VTL.h"
#include "DFT.h"
#include "stdio.h"
#include "PE_Types.h"



#define No_LEDS 36
#define No_LEDS_SYNCHRO 11




int     cont_led,cont_led_aux,led_No_elem_vector;
byte    led[No_LEDS],led_synchro[No_LEDS_SYNCHRO];




void    sincronoscopio_VTL(void) 
{

int i,j;
        

     if((  -500<=Dif_Fases[0])&&(Dif_Fases[0]<=   500))//00
        {
          cont_led=0;

          
          if((  -500<=Dif_Fases[0])&&(Dif_Fases[0]<=  -450))//aux 00
             cont_led_aux=0;
          else 
            if((  -450< Dif_Fases[0])&&(Dif_Fases[0]<=  -350))//aux 01
               cont_led_aux=1;  
            else 
              if((  -350< Dif_Fases[0])&&(Dif_Fases[0]<=  -250))//aux 02
                 cont_led_aux=2;  
              else 
                if((  -250< Dif_Fases[0])&&(Dif_Fases[0]<=  -150))//aux 03
                   cont_led_aux=3;  
                else 
                  if((  -150< Dif_Fases[0])&&(Dif_Fases[0]<=   -50))//aux 04
                     cont_led_aux=4;    
                  else 
                    if((   -50< Dif_Fases[0])&&(Dif_Fases[0]<=    50))//aux 05
                       cont_led_aux=5;    
                    else 
                      if((    50< Dif_Fases[0])&&(Dif_Fases[0]<=   150))//aux 06
                         cont_led_aux=6;    
                      else 
                        if((   150< Dif_Fases[0])&&(Dif_Fases[0]<=   250))//aux 07
                           cont_led_aux=7;  
                        else 
                          if((   250< Dif_Fases[0])&&(Dif_Fases[0]<=   350))//aux 08 
                             cont_led_aux=8; 
                          else 
                            if((   350< Dif_Fases[0])&&(Dif_Fases[0]<=   450))//aux 09
                               cont_led_aux=9;    
                            else 
                              if((   450< Dif_Fases[0])&&(Dif_Fases[0]<=   500))//aux 10
                                 cont_led_aux=10;
                              
        }
     else 
        {

       if((   500< Dif_Fases[0])&&(Dif_Fases[0]<=  1500))//01
          cont_led=1;
       else 
         if((  1500< Dif_Fases[0])&&(Dif_Fases[0]<=  2500))//02
            cont_led=2;  
         else 
           if((  2500< Dif_Fases[0])&&(Dif_Fases[0]<=  3500))//03
              cont_led=3;  
           else 
             if((  3500< Dif_Fases[0])&&(Dif_Fases[0]<=  4500))//04
                cont_led=4;  
             else 
               if((  4500< Dif_Fases[0])&&(Dif_Fases[0]<=  5500))//05
                  cont_led=5;    
               else 
                 if((  5500< Dif_Fases[0])&&(Dif_Fases[0]<=  6500))//06
                    cont_led=6;    
                 else 
                   if((  6500< Dif_Fases[0])&&(Dif_Fases[0]<=  7500))//07
                      cont_led=7;    
                   else 
                     if((  7500< Dif_Fases[0])&&(Dif_Fases[0]<=  8500))//08
                        cont_led=8;  
                     else 
                       if((  8500< Dif_Fases[0])&&(Dif_Fases[0]<=  9500))//09 
                          cont_led=9; 
                       else 
                         if((  9500< Dif_Fases[0])&&(Dif_Fases[0]<= 10500))//10
                            cont_led=10;    
                         else 
                           if(( 10500< Dif_Fases[0])&&(Dif_Fases[0]<= 11500))//11
                              cont_led=11;    
                           else 
                             if(( 11500< Dif_Fases[0])&&(Dif_Fases[0]<= 12500))//12
                                cont_led=12;    
                             else 
                               if(( 12500< Dif_Fases[0])&&(Dif_Fases[0]<= 13500))//13
                                  cont_led=13;  
                               else 
                                 if(( 13500< Dif_Fases[0])&&(Dif_Fases[0]<= 14500))//14
                                    cont_led=14; 
                                 else 
                                   if(( 14500< Dif_Fases[0])&&(Dif_Fases[0]<= 15500))//15
                                      cont_led=15;    
                                   else 
                                     if(( 15500< Dif_Fases[0])&&(Dif_Fases[0]<= 16500))//16
                                        cont_led=16;    
                                     else 
                                       if(( 16500< Dif_Fases[0])&&(Dif_Fases[0]<= 17500))//17
                                          cont_led=17;    
                                       else 
                                         if(( 17500< Dif_Fases[0])||(Dif_Fases[0]< -17500))//18
                                            cont_led=18;  
                                         else 
                                           if((-17500<=Dif_Fases[0])&&(Dif_Fases[0]< -16500))//19 
                                              cont_led=19;   
                                           else 
                                             if((-16500<=Dif_Fases[0])&&(Dif_Fases[0]< -15500))//20
                                                cont_led=20;  
                                             else 
                                               if((-15500<=Dif_Fases[0])&&(Dif_Fases[0]< -14500))//21
                                                  cont_led=21;   
                                               else 
                                                 if((-14500<=Dif_Fases[0])&&(Dif_Fases[0]< -13500))//22
                                                    cont_led=22;   
                                                 else 
                                                   if((-13500<=Dif_Fases[0])&&(Dif_Fases[0]< -12500))//23
                                                      cont_led=23;   
                                                   else 
                                                     if((-12500<=Dif_Fases[0])&&(Dif_Fases[0]< -11500))//24
                                                        cont_led=24;  
                                                     else 
                                                       if((-11500<=Dif_Fases[0])&&(Dif_Fases[0]< -10500))//25
                                                          cont_led=25;   
                                                       else 
                                                         if((-10500<=Dif_Fases[0])&&(Dif_Fases[0]<  -9500))//26
                                                            cont_led=26;
                                                         else 
                                                           if(( -9500<=Dif_Fases[0])&&(Dif_Fases[0]<  -8500))//27
                                                              cont_led=27;
                                                           else 
                                                             if(( -8500<=Dif_Fases[0])&&(Dif_Fases[0]<  -7500))//28
                                                                cont_led=28;
                                                             else 
                                                               if(( -7500<=Dif_Fases[0])&&(Dif_Fases[0]<  -6500))//29
                                                                  cont_led=29;
                                                               else 
                                                                 if(( -6500<=Dif_Fases[0])&&(Dif_Fases[0]<  -5500))//30
                                                                    cont_led=30;
                                                                 else 
                                                                   if(( -5500<=Dif_Fases[0])&&(Dif_Fases[0]<  -4500))//31
                                                                      cont_led=31;
                                                                   else 
                                                                     if(( -4500<=Dif_Fases[0])&&(Dif_Fases[0]<  -3500))//32
                                                                        cont_led=32;
                                                                     else 
                                                                       if(( -3500<=Dif_Fases[0])&&(Dif_Fases[0]<  -2500))//33
                                                                          cont_led=33;
                                                                       else 
                                                                         if(( -2500<=Dif_Fases[0])&&(Dif_Fases[0]<  -1500))//34
                                                                            cont_led=34;
                                                                         else 
                                                                           if(( -1500<=Dif_Fases[0])&&(Dif_Fases[0]<   -500))//35
                                                                              cont_led=35;                                            
 
        }
        
        
             led_No_elem_vector=No_LEDS; 
             ClrAllLEDs_SetLEDx(cont_led,led,led_No_elem_vector);//numero de LED a prender y vector a modificar. 
             
             if(cont_led==0)
              {
               led_No_elem_vector=No_LEDS_SYNCHRO;
               ClrAllLEDs_SetLEDx(cont_led_aux,led_synchro,led_No_elem_vector);   
              } 
             else
              for(i=0;i<No_LEDS_SYNCHRO;i++) //Limpia todos los LED's
                led_synchro[i]=0;/**/ 
                        
}





void    Clr_LEDs_Sincronoscopio_VTL(void)
{
int i,j;

  for(i=0;i<No_LEDS_SYNCHRO;i++) //Limpia todos los LED's
    led_synchro[i]=0;/**/ 
                
  for(i=0;i<No_LEDS;i++) //Limpia todos los LED's
    led[i]=0;/**/ 
}



void ClrAllLEDs_SetLEDx(int x,byte *y,int z)//No de LED, vector a modificar, No de elementos del vector 
{
  int i;
  
  for(i=0;i<z;i++) //Limpia todos los LED's
    y[i]=0;

  y[x]=1;  //Enciende el LED indicado.

}

