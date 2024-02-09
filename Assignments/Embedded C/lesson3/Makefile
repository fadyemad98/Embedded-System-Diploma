# @copyright: fady emad
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s
INCS=-I .
LIBS=
PROJECT_NAME=learn-in-depth

all: $(PROJECT_NAME).bin
	@echo "=========Build is done========="
Startup.o: Startup.s	
	$(CC)as.exe -g $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(INCS) -g $(CFLAGS) -c $< -o $@

$(PROJECT_NAME).elf: App.o Startup.o Uart.o
	$(CC)ld.exe -T Linker_script.ld $(LIBS) App.o Startup.o Uart.o -o $@ -Map=Map_file.map

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all:
	rm *.o *.elf *.bin

clean: 
	rm *.elf *.bin