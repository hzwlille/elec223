#include<stdio.h>
#include"uart_addr.h"

void uart_init();
void uart_putchar(char c);
unsigned char uart_getchar();
void uart_puts(const char *s);
void uart_gets(char *s, int size);
