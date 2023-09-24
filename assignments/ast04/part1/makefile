# Make file for pointers assignment

OBJS	= allocation_practice.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
MAIN_DEPS	= item.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o practice $(OBJS)
	@echo "Done! Finished building practice program"

allocation_practice.o: allocation_practice.cpp $(MAIN_DEPS)
	@echo "Compiling Allocation Practice..."
	$(CC) $(CCFLAGS) -c allocation_practice.cpp


# -----
# clean by removing object files.

clean:
	rm $(OBJS) allocation_practice.o
