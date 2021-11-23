TARGET=all

OUT_DIR=../outr

SRC_DIR= ./src
SRC_DRIVERSDIR= ./drivers/src

INC_DIR= ./inc
INC_DRIVERSDIR= ./drivers/inc

MEM_MAP=-nostartfiles -T .\settings\F103C8Tx.ld

MODULES_SRC= $(wildcard $(SRC_DIR)/*.cpp)
MODULES_SRCDRIVERS= $(wildcard $(SRC_DRIVERSDIR)/*.cpp)

OBJ_SRC=$(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.o,$(MODULES_SRC))
OBJ_SRCDRIVERS=$(patsubst $(SRC_DRIVERSDIR)/%.cpp,$(OUT_DIR)/%.o,$(MODULES_SRCDRIVERS))

OBJ_SRC_ASM=$(patsubst $(SRC_DIR)/%.cpp,$(OUT_DIR)/%.s,$(MODULES_SRC))
OBJ_SRCDRIVERS_ASM=$(patsubst $(SRC_DRIVERSDIR)/%.cpp,$(OUT_DIR)/%.s,$(MODULES_SRCDRIVERS))

SRC_ALL=$(MODULES_SRC) $(MODULES_SRCDRIVERS)
OBJ_ALL=$(OBJ_SRC) $(OBJ_SRCDRIVERS)

INCLUDE= -I $(INC_DIR) -I $(INC_DRIVERSDIR)

MAP_FILE_OLD= -Map $(OUT_DIR)/program_$(VER).map
MAP_FILE= -Xlinker -Map=$(OUT_DIR)/program_$(VER).map

CPP_FLAGS=-c -fno-common -O0 -g -specs=nosys.specs -mcpu=cortex-m3 -mthumb

OBJECTS=$(wildcard $(OUT_DIR)/*.o)
ASEMS=$(wildcard $(OUT_DIR)/*.s)
ELFS=$(wildcard $(OUT_DIR)/*.elf)
HEXS=$(wildcard $(OUT_DIR)/*.hex)
MAPS=$(wildcard $(OUT_DIR)/*.map)

GCC_PATH=E:\Programy\eclipseCpp\ARM_GCC

CC=$(GCC_PATH)\bin\arm-none-eabi-gcc
CPP=$(GCC_PATH)\bin\arm-none-eabi-g++
LD=$(GCC_PATH)\bin\arm-none-eabi-ld
AR=$(GCC_PATH)\bin\arm-none-eabi-ar
AS=$(GCC_PATH)\bin\arm-none-eabi-as
CP=$(GCC_PATH)\bin\arm-none-eabi-objcopy
OD=$(GCC_PATH)\bin\arm-none-eabi-objdump
SE=$(GCC_PATH)\bin\arm-none-eabi-size
NU=$(GCC_PATH)\bin\arm-none-eabi-nm
SF=$(GCC_PATH)\stlink\ST-LINK_CLI
RM=$(GCC_PATH)\rm

.PHONY:$(TARGET)

run:cls clean $(TARGET).hex $(TARGET).asm flush

rebulid:cls clean $(TARGET).hex $(TARGET).asm

$(TARGET):cls $(TARGET).hex $(TARGET).asm
	
$(TARGET).hex:$(OBJ_SRC) $(OBJ_SRCDRIVERS)
	$(CPP) -Wl,-LE:/Programy/eclipseCpp/ARM_GCC/lib/gcc/arm-none-eabi/7.2.1/thumb $(MEM_MAP) $(MAP_FILE) --specs=nosys.specs $(OUT_DIR)/*.o -o $(OUT_DIR)/program_$(VER).elf	
	$(CP) -O ihex $(OUT_DIR)/program_$(VER).elf $(OUT_DIR)/program_$(VER).hex
	$(SE) --format=berkeley -d $(OUT_DIR)/program_$(VER).elf
	
$(TARGET).asm:$(OBJ_SRC_ASM) $(OBJ_SRCDRIVERS_ASM)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(MEM_MAP) $(INCLUDE) -o $@ $<   
	
$(OUT_DIR)/%.o: $(SRC_DRIVERSDIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(MEM_MAP) $(INCLUDE) -o $@ $< 
	
$(OUT_DIR)/%.s: $(SRC_DIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(MEM_MAP) $(INCLUDE) -S -o $@ $<   
	
$(OUT_DIR)/%.s: $(SRC_DRIVERSDIR)/%.cpp
	$(CPP) $(CPP_FLAGS) $(MEM_MAP) $(INCLUDE) -S -o $@ $< 
   
clean:cls	
	$(RM) -f $(OBJECTS)
	$(RM) -f $(ASEMS)
	$(RM) -f $(ELFS)
	$(RM) -f $(HEXS)
	$(RM) -f $(MAPS)	
cls:
	cls
num:
	$(NU) --numeric-sort $(OUT_DIR)/program_$(VER).elf
flush:
	$(SF) -c SWD -ME -p $(OUT_DIR)/program_$(VER).hex -Rst -Run
	