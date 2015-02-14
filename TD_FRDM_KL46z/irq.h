#ifndef IRQ_H
#define IRQ_H

#define enable_irq()    __asm__ ( "cpsie i")
#define disable_irq()   __asm__ ( "cpsid i")

void irq_init(void);
void irq_enable(int);
void irq_disable(int);

#endif
