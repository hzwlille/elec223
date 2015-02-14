#include "irq.h"
//void PORTCD_IRQHandler(void);
void matrix_init();
void button_init();

int main(){   
   irq_init();
   button_init();
   //  PORTCD_IRQHandler();
   matrix_init();
   return 0;
}
 
