#include"matrix_addr.h"
//controle des broches   
#define RST(x)  (x==0?  (GPIOB_PCOR |=0x0004):(GPIOB_PSOR |=0x0004))
#define SB(x)   (x==0?  (GPIOB_PCOR |=0x0001):(GPIOB_PSOR |=0x0001))
#define LAT(x)  (x==0?  (GPIOB_PCOR |=0x0002):(GPIOB_PSOR |=0x0002))
#define SCK(x)  (x==0?  (GPIOC_PCOR |=0x0100):(GPIOC_PSOR |=0x0100))
#define SDA(x)  (x==0?  (GPIOC_PCOR |=0x0200):(GPIOC_PSOR |=0x0200))
#define ROW0(x) (x==0?  (GPIOA_PCOR |=0x2000):(GPIOA_PSOR |=0x2000))
#define ROW1(x) (x==0?  (GPIOD_PCOR |=0x0004):(GPIOD_PSOR |=0x0004))
#define ROW2(x) (x==0?  (GPIOD_PCOR |=0x0010):(GPIOD_PSOR |=0x0010))
#define ROW3(x) (x==0?  (GPIOD_PCOR |=0x0040):(GPIOD_PSOR |=0x0040))
#define ROW4(x) (x==0?  (GPIOD_PCOR |=0x0080):(GPIOD_PSOR |=0x0080))
#define ROW5(x) (x==0?  (GPIOD_PCOR |=0x0020):(GPIOD_PSOR |=0x0020))
#define ROW6(x) (x==0?  (GPIOA_PCOR |=0x1000):(GPIOA_PSOR |=0x1000))
#define ROW7(x) (x==0?  (GPIOA_PCOR |=0x0010):(GPIOA_PSOR |=0x0010))


//générer les pulses
void pulse_SCK(){
  SCK((0));	
  for(int j;j<10;j++)	
    asm volatile("nop");				
  SCK(1);					
  for(int j;j<10;j++)	
    asm volatile("nop");				
  SCK(0);
  for(int j;j<10;j++)	
    asm volatile("nop");		
}
void  pulse_LAT(){ 
  LAT(1);		
  for(int j;j<10;j++)	
    asm volatile("nop");				
  LAT(0);					
  for(int j;j<10;j++)
    asm volatile("nop");				
  LAT(1);					
  for(int j;j<10;j++)	
    asm volatile("nop");}


typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} rgb_color;



//controle des lignes
void deactivate_rows(){
  ROW0(0);
  ROW1(0);
  ROW2(0);
  ROW3(0);
  ROW4(0);
  ROW5(0);
  ROW6(0);
  ROW7(0);
}
void activate_rows(int row){
  switch(row) {
  case 0:
    {  
      ROW0(1);
      break;
    }
  case 1:
    {  
      ROW1(1);
      break;
    }
  case 2:
    {  
      ROW2(1);
      break;
    }
  case 3:
    {  
      ROW3(1);
      break;
    }
  case 4:
    {  
      ROW4(1);
      break;
    }
  case 5:
    {  
      ROW5(1);
      break;
    }
  case 6:
    {  
      ROW6(1);
      break;
    }
  case 7:
    {  
      ROW7(1);
      break;
    }
  defaut: deactivate_rows();
    break;
  }
}
