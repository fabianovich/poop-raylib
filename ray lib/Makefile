# Compiler
CC = emcc

# Project paths
SRC = main.cpp
OUT_DIR = dist
RES_DIR = resources

# Raylib paths
RAYLIB_INCLUDE = C:\raylib\x64-windows\include
RAYLIB_LIB = C:/raylib/raylib/src/libraylib.a

# Compiler & Linker flags
CFLAGS = -O2 -Wall -I$(RAYLIB_INCLUDE)
LDFLAGS = -s USE_GLFW=3 -s ASYNCIFY=1 -s FORCE_FILESYSTEM=1 --preload-file $(RES_DIR)@/resources
LIBS = $(RAYLIB_LIB) -lm -ldl -lpthread -s USE_GLFW=3 -s FULL_ES3=1

# Output target
TARGET = $(OUT_DIR)/index.html

# Build rule
all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(LIBS)

# Clean rule
clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
