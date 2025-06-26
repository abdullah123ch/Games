# === Cross-Platform Makefile for Pong Masters ===

TARGET = PongMasters
SRC = game.cpp

CXX = g++
CXXFLAGS = -Wall -std=c++17

# Detect OS and set raylib dependencies
ifeq ($(OS),Windows_NT)
    PLATFORM = WINDOWS
    RAYLIB_LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm
    INCLUDES = -IC:/raylib/include
    LIBS = -LC:/raylib/lib
    EXT = .exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM = LINUX
        RAYLIB_LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    endif
    ifeq ($(UNAME_S),Darwin)
        PLATFORM = MAC
        RAYLIB_LIBS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
    endif
    EXT =
endif

# Build target
all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)$(EXT) $(LIBS) $(RAYLIB_LIBS)

# Run (only on non-Windows)
run: all
ifeq ($(PLATFORM),WINDOWS)
	@echo "Run manually on Windows: ./$(TARGET).exe"
else
	./$(TARGET)$(EXT)
endif

# Clean
clean:
	rm -f $(TARGET)$(EXT)
