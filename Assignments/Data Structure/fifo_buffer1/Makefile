# @copyright: fady emad
CC=
CFLAGS=
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
PROJECT_NAME=learn-in-depth
BoardType=$($(BoardType))

all: $(PROJECT_NAME).bin
	@echo "============================================================================="
	@echo "==============================Build is done=================================="
	@echo "============================================================================="
%.o: %.s	
	$(CC)as.exe -g $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)gcc.exe $(INCS) -g $(CFLAGS) -c $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ) 
	$(CC)ld.exe -T Linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all:
	rm *.o *.elf *.bin

clean: 
	rm *.elf *.bin
	@echo "Everything is clean"
