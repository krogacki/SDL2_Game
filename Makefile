C_FLAGS := -std=c++14 -g -Wall -Wextra
CC := g++
RM := rm
LINKFLAGS := -L ../SDL2-2.28.5/i686-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2

.PHONY: $(TARGET)
.PHONY: clean
VPATH:= ./src/ ./bin/obj/ ./bin/obj/debug ./include

# path for .cpp, .h and .o Files
SRC_PATH := ./src/
OBJ_PATH := ./bin/obj/
INC_PATH := -I ./include  \
			-I C:/SDL2/SDL2-2.28.5/i686-w64-mingw32/include

#executable Name
TARGET := ./bin/debug/main

OBJ1 := main.o testprint.o Game.o

OBJ := $(patsubst %,$(OBJ_PATH)%,$(OBJ1))

# Build .o first
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
				@echo [CC] $<
				@$(CC) $(C_FLAGS) -o $@ -c $< $(INC_PATH)                  

# Build final Binary
$(TARGET):		$(OBJ)
				@echo [INFO] Creating Binary Executable [$(TARGET)]
				@$(CC) -o $@ $^ $(LINKFLAGS)

run:
	@echo "[Starting program...]" && start $(TARGET)

# Clean all the object files and the binary
clean:   
				@echo "[Cleaning]"
				@$(RM) -rf $(TARGET).exe
				@$(RM) -rf $(OBJ)