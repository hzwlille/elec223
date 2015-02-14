#include"uart.h"

void uart_init(){
  
  //activer l'horloge du port série
  SIM_SOPT2|=0x04010000;
  SIM_SCGC4|=0x00000400; 
//passer les broches RX et TX du port A en mode UART
  SIM_SCGC5 |= 0x00000200;
  PORTA_PCR1 |= 0x200;
  PORTA_PCR2 |= 0x200;
  //configurer l'oversampling à la valeur la plus grande possible(on prend 29 ce qui revient à 30)
  UART0_C2 &= ~0x0C;
  UART0_C4 = 0x0D;
  //configurer l'UART0 en 8 N 1
  UART0_C4 &= ~0x20;
  UART0_C1 = 0x00;
  //configurer la vitesse du port série à 115200 bauds
  UART0_BDH = 0x00;
  UART0_BDL = 0x07;
  //activer le transmetteur et le récepteur(P752)
  UART0_C2 |= 0x0C;

}


// qui attend que l'UART soit prêt à transmettre quelque chose, puis lui demande de l'envoyer 
void uart_putchar(char c){
  while(!(UART0_S1&0xC0)) ;
  UART0_D = c;
}



// qui attend que l'UART ait reçu un caractère puis le retourne 
unsigned char uart_getchar(){
  while(!(UART0_S1&0x20)) ;
  UART0_S1 &= 0x0c;
  return UART0_D;
} 


void uart_puts(const char *s){
  while(*s!=0){
  }
}



void uart_gets(char *s, int size){
}
