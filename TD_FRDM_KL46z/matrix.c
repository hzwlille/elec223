#include"matrix.h"
#include<stdint.h>
extern char _binary_image_raw_start, _binary_image_raw_end;
void test_static_image();
void test_pixels();
void send_byte0(){
  int i;
  SB(0);
  for (i=0;i<6;i++){
    SDA(1);
    pulse_SCK();
  }
}


void  void_bank0(){
  for (int i=0;i<24;i++)
    send_byte0();
  pulse_LAT();
    
}


void matrix_init(){
  //mis en marche les horloges
  SIM_SCGC5 |=0x00001E00;
  //mis en mode GPIO
  PORTB_PCR0  = 0x00000100;  
  PORTB_PCR1  = 0x00000100;
  PORTB_PCR2  = 0x00000100; 
  PORTC_PCR8  = 0x00000100;  
  PORTC_PCR9  = 0x00000100; 
  PORTA_PCR13 = 0x00000100;
  PORTD_PCR2  = 0x00000100;
  PORTD_PCR4  = 0x00000100;
  PORTD_PCR6  = 0x00000100;
  PORTD_PCR7  = 0x00000100;
  PORTD_PCR5  = 0x00000100;
  PORTA_PCR12 = 0x00000100;
  PORTA_PCR4  = 0x00000100;

  //mis en sorties
  GPIOA_PDDR= 0x3010;
  GPIOB_PDDR= 0x0007;
  GPIOC_PDDR= 0x0300;
  GPIOD_PDDR= 0x00F4;
  //positionner les sorties
  RST((0));
  LAT(1);
  SB(1);
  SCK(0);
  SDA(0);
  deactivate_rows(); 
  //attend initialisation
  for(int k=0;k<2400000;k++)
     asm volatile("nop");	

  RST(1);

 //inithialiser bank0
  void_bank0();
  SB(1);
  //test_pixels();
  test_static_image();
}


void send_byte(uint8_t val){
  int i;
   SB(1);
   uint8_t mask; 
  for (i=7;i>=0;i--){
    SDA(val&(mask<<i));
    pulse_SCK();
  }
   LAT(1);
}


void mat_set_row(int row, const rgb_color *val){

  for (int i=7;i>=0;i--){
    send_byte(val[i].r);
    send_byte(val[i].g);
    send_byte(val[i].b);
  }	
  activate_rows(row);
  pulse_LAT();

}


void test_pixels(){
  rgb_color test_color[8];
                    
  for(int j=0;j<8;j++){			
    test_color[j].r = 0;
    test_color[j].g = 0;
    test_color[j].b = 5;
  }

  while(1){
    for(int w=0;w<8;w++){
      deactivate_rows();
      mat_set_row(w, test_color);
      for(int i = 0; i < 2000000; i++)
	asm volatile ("nop");
    }
  }

}




void test_static_image(){

  char buffer[192];

  int j=0;
  char* begin=(char*) &_binary_image_raw_start;
  char* end  =(char*) &_binary_image_raw_end;


  for(char* i=begin;i<end;i++) 
     buffer[j++]=*i;
   

  //met dans chaque ligne
  rgb_color test_color[8];
  for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){			
	test_color[j].r = buffer[i*24+j*3];
	test_color[j].g = buffer[i*24+j*3+1];
	test_color[j].b = buffer[i*24+j*3+2];
      }
    }


   
  while(1){
    for(int w=0;w<8;w++){
      deactivate_rows();
      for(int i = 0; i < 60; i++)
	asm volatile ("nop");
      mat_set_row(w,test_color+192*w);
      for(int i = 0; i < 60; i++)
	asm volatile ("nop");
    }
  }

}


