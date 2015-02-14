PREFIX      = arm-none-eabi-
CC          = $(PREFIX)gcc
OBJCOPY     = $(PREFIX)objcopy
OBJDUMP     = $(PREFIX)objdump
AS          = $(PREFIX)as
GDB         = $(PREFIX)gdb
# For the impicit CC rule
TARGET_ARCH = -mcpu=cortex-m0plus -mthumb
CFLAGS      = -c -g -O1 -std=gnu99
CIBLE       = xxx.elf
# For the impicit AS rule
TARGET_MACH = -mcpu=cortex-m0plus -mthumb

OBJS           = main.o init.o led.o uart.o matrix.o bouttons.o irq.o  flash.o image.o crt0.o
PRESERVED_OBJS = clocks.o


EXE  =  main 

.PHONY: all verify clean debug startgdbserver

all: $(EXE)

$(EXE): $(OBJS) $(PRESERVED_OBJS)
	$(CC) -T ld_ram.lds  -nostdlib  $^ -o $@ 


startgdbserver :
	JLinkGDBServer -if swd -device "MKL46Z256xxx4" -LocalhostOnly

debug:
	$(GDB) $(EXE)

%.o : %.raw
	$(OBJCOPY) -I binary -O elf32-littlearm  -B arm  $< $@

verify: $(EXE)
	$(OBJDUMP) -h $<

clean:
	@rm -f  $(OBJS) $(EXE) 
