CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -m32
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXE_NAME = bcd_library

all: $(OBJS)
	$(CXX) $(CXXFLAGS)  -o $(EXE_NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(EXE_NAME)
