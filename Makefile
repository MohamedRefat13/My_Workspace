CC      := g++
CCFLAGS := -fdiagnostics-color=always -g -Wall #-c 
TARGET  := main.exe
SOURCES := $(wildcard *.cpp) $(wildcard SortinngAlgorithms/*.cpp) $(wildcard Tree/*.cpp)

all:
	@$(CC) $(CCFLAGS) $(SOURCES) -o $(TARGET)
	@./$(TARGET)

clean:
	@echo CLEANING ..........
	@del *.o
	@del *.bin
	@del *.exe
	@del *.dot
	@echo DONE ..........

help:
	@echo "make 	   -->  build the cpp project and run the output"
	@echo "make clean -->  clean all executables, binaries and dot files"
	@echo "make build -->  build ONLY without running" 