#============================================================================#
#Output Files
PROJECT=firmware
EXECUTABLE=$(PROJECT).elf
BIN_IMAGE=$(PROJECT).bin
TEST_EXE=run_test
#============================================================================#
#Cross Compiler
HOST_CC=gcc
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
GDB=arm-none-eabi-gdb
#============================================================================#
#Stm32F4xx Standard Libraries
CMSIS=../../STM_Lib/CMSIS
ST=../../STM_Lib/STM32F4xx_StdPeriph_Driver
STARTUP=./startup_stm32f429_439xx.S
#Linker
CFLAGS= -Wl,-T,stm32f429zi_flash.ld
#Source Files
SRC+=	$(CMSIS)/system_stm32f4xx.c \
        $(ST)/src/misc.c \
        $(ST)/src/stm32f4xx_rcc.c \
        $(ST)/src/stm32f4xx_dma.c \
        $(ST)/src/stm32f4xx_flash.c \
        $(ST)/src/stm32f4xx_gpio.c \
        $(ST)/src/stm32f4xx_usart.c \
        $(ST)/src/stm32f4xx_tim.c \
        $(ST)/src/stm32f4xx_spi.c \
        $(ST)/src/stm32f4xx_i2c.c \
        $(ST)/src/stm32f4xx_sdio.c 

#Included Header Files
CFLAGS_INCLUDE=-I./ \
	-I$(CMSIS) \
	-I$(ST)/inc \
#============================================================================#
#User's Application
PERIPHERAL=../../Peripherals
HARDWARE=../../Hardware
USER_LIB=../../User_Lib

#User Source Files
SRC+=	./main.c \
	$(HARDWARE)/LED/led.c \
	$(HARDWARE)/ILI9341/ili9341.c \
	$(PERIPHERAL)/spi5/spi5.c \
	$(USER_LIB)/myfont/myfont.c

#User Header Files
CFLAGS_INCLUDE+=-I./ \
		-I$(HARDWARE)/LED \
		-I$(HARDWARE)/ILI9341 \
		-I$(PERIPHERAL)/spi5 \
		-I$(USER_LIB)/myfont
#============================================================================# 
CFLAGS_DEFINE= \
        -D USE_STDPERIPH_DRIVER \
	-D STM32F429_439xx \
        -D __FPU_PRESENT=1 \
        -D ARM_MATH_CM4 \
        -D __FPU_USED=1 \
#__CC_ARM
CFLAGS_OPTIMIZE= \
		-O2
CFLAGS_NEW_LIB_NANO= \
		--specs=nano.specs --specs=nosys.specs -u _printf_float
CFLAGS_WARNING= \
		-Wall \
		-Wextra \
		-Wdouble-promotion \
		-Wshadow \
		-Werror=array-bounds \
		-Wfatal-errors \
		-Wmissing-prototypes \
		-Wbad-function-cast \
		-Wstrict-prototypes \
		-Wmissing-parameter-type

CFLAGS+=-g -mlittle-endian -mthumb -mcpu=cortex-m4 \
	-mfpu=fpv4-sp-d16 -mfloat-abi=hard \
	${CFLAGS_INCLUDE} \
        ${CFLAGS_DEFINE} \
        ${CFLAGS_NEW_LIB_NANO} \
        ${CFLAGS_WARNING}

LDFLAGS=-lm
#============================================================================#
#Make all
all:$(BIN_IMAGE)

$(BIN_IMAGE):$(EXECUTABLE)
	@$(OBJCOPY) -O binary $^ $@
	@echo '    OBJCOPY $(BIN_IMAGE)'

STARTUP_OBJ = startup_stm32f429_439xx.o

$(STARTUP_OBJ): $(STARTUP)
	@$(CC) $(CFLAGS) $^ -c $(STARTUP)
	@echo '    CC $(STARTUP_OBJ)'

$(EXECUTABLE):$(SRC) $(STARTUP_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo '    CC $(EXECUTABLE)'
PC_SIM:$(TEST_EXE)

$(TEST_EXE):$(HOST_SRC)
	$(HOST_CC) $(HOST_CFLAG) $^ -o $@
#Make clean
clean:
	rm -rf $(STARTUP_OBJ)
	rm -rf $(EXECUTABLE)
	rm -rf $(BIN_IMAGE)

#Make flash
flash:
	st-flash write $(BIN_IMAGE) 0x8000000
#Make cgdb
cgdb:
	cgdb -d $(GDB) -x ./st_util_init.gdb
#Make gdbauto
gdbauto: cgdb
#automatically formate
astyle: 
	astyle -r --exclude=lib  *.c *.h
#============================================================================#

.PHONY:all clean flash openocd gdbauto gdbtui cgdb astyle
