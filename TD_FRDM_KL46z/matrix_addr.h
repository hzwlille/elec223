#include<stdint.h>
//met en marche les horloges
#define SIM_SCGC5  (*( volatile uint32_t*)0x40048038)

//configurer en mode GPIO
#define PORTB_PCR0  (*( volatile uint32_t* )0x4004A000)
#define PORTB_PCR1  (*( volatile uint32_t* )0x4004A004)
#define PORTB_PCR2  (*( volatile uint32_t* )0x4004A008)
#define PORTC_PCR8  (*( volatile uint32_t* )0x4004B020)
#define PORTC_PCR9  (*( volatile uint32_t* )0x4004B024)
#define PORTA_PCR13 (*( volatile uint32_t* )0x40049034)
#define PORTD_PCR2  (*( volatile uint32_t* )0x4004C008)
#define PORTD_PCR4  (*( volatile uint32_t* )0x4004C010)
#define PORTD_PCR6  (*( volatile uint32_t* )0x4004C018)
#define PORTD_PCR7  (*( volatile uint32_t* )0x4004C01C)
#define PORTD_PCR5  (*( volatile uint32_t* )0x4004C014)
#define PORTA_PCR12 (*( volatile uint32_t* )0x40049030)
#define PORTA_PCR4  (*( volatile uint32_t* )0x40049010)
//configurer en sorties
#define GPIOA_PDDR  (*( volatile uint32_t* )0x400FF014)
#define GPIOB_PDDR  (*( volatile uint32_t* )0x400FF054)
#define GPIOC_PDDR  (*( volatile uint32_t* )0x400FF094)
#define GPIOD_PDDR  (*( volatile uint32_t* )0x400FF0D4)
//configurer les valeurs
#define GPIOA_PCOR  (*( volatile uint32_t* )0x400FF008)
#define GPIOB_PCOR  (*( volatile uint32_t* )0x400FF048)
#define GPIOC_PCOR  (*( volatile uint32_t* )0x400FF088)
#define GPIOD_PCOR  (*( volatile uint32_t* )0x400FF0C8)
#define GPIOA_PSOR  (*( volatile uint32_t* )0x400FF004)
#define GPIOB_PSOR  (*( volatile uint32_t* )0x400FF044)
#define GPIOC_PSOR  (*( volatile uint32_t* )0x400FF084)
#define GPIOD_PSOR  (*( volatile uint32_t* )0x400FF0C4)
