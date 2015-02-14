#ifndef IRQ_ADDR_H
#define  IRQ_ADDR_H

#include <stdint.h>

#define VTOR        (*( volatile uint32_t*) 0xE000ED08)
#define AIRCR       (*(volatile uint32_t *) 0xE000ED0C)

#define NVIC_ISER   (*(volatile uint32_t *) 0xE000E100)
#define NVIC_ICER   (*(volatile uint32_t *) 0xE000E180)

#endif
