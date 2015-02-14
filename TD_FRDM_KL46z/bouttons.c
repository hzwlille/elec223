#include <stdint.h>
#include "irq.h"


#define SIM_SCGC5   (*( volatile uint32_t*) 0x40048038)
#define PORTC_PCR3  (*( volatile uint32_t*) 0x4004B00C)
#define PORTE_PCR29 (*(volatile uint32_t *) 0x4004D074)
#define GPIOE_PTOR  (*(volatile uint32_t *) 0x400FF10C)
#define GPIOE_PDDR  (*(volatile uint32_t *) 0x400FF114)
#define GPIOC_PDDR  (*(volatile uint32_t *) 0x400ff094)
#define GPIOE_PCOR  (*(volatile uint32_t *) 0x400FF108) 

void button_init(void){

	//activer l'horloge
	SIM_SCGC5  |= (1<<11);
	SIM_SCGC5  |= 0x00003000;
	//en GPIO, en entrée, avec pull-up, un filtre passe-bas, intérruption sur front descendant
	PORTC_PCR3 |= 0x000a0113;

	irq_enable(31);
	GPIOC_PDDR &= ~0x00000003;

}

void Dummy_IRQHandler(void) {
	//aquittement
	PORTC_PCR3 |= 1<<28;
	//toggle de la LED rouge
	//GPIOE_PTOR=0x20000000;
	PORTE_PCR29 &=~0x00000600;
	PORTE_PCR29 |= 0x00000100;
	GPIOE_PDDR  |= 0x20000000;
	for(int i = 0; i < 2000000; i++)
	  asm volatile ("nop");

}

