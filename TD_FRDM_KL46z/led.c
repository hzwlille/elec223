#include "led.h"

void led_init(){
  //activer les horloges des ports D et E dans le registre SIM_SCGCx
  SIM_SCGC5|=0x00003000;
    //configure les broches PTD5 et PTE29 en GPIO : registres PORTD_PCR5 et PORTE_PCR29
  PORTD_PCR5&=~0x00000600;
  PORTD_PCR5|=0x00000100;
  PORTE_PCR29&=~0x00000600;
  PORTE_PCR29|=0x00000100;
  //configure les broches PTD5 et PTE29 en sorties : registres GPIOD_PDDR et GPIOE_PDDR
  GPIOD_PDDR=0x00000020;
  GPIOE_PDDR=0x20000000;
  //allume les deux LEDs : registres GPIOD_PSOR par exemple, et GPIOE_PSOR.
  GPIOD_PCOR|=0x00000020;
  GPIOE_PCOR|=0x20000000;
}

void v_led_on(){
  GPIOD_PCOR=0x00000020;
}
void v_led_off(){
  GPIOD_PSOR=0x00000020;
}
void v_led_toggle(){
  GPIOD_PTOR=0x00000020;
}

void r_led_on(){

  SIM_SCGC5  |= (1<<11);
  GPIOE_PCOR=0x20000000;
}
void r_led_off(){
  GPIOE_PSOR=0x20000000;
}
void r_led_toggle(){

  GPIOE_PTOR=0x20000000;
}
