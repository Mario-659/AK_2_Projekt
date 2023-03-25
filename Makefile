CC = g++
CFLAGS = -Wall -g -std=c++11
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXE_NAME = bcd_arithmetic

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE_NAME) $(OBJS)

clean:
	rm -f *.o a.out
