EXEC = b_tree

CXX = g++
CXXFLAGS = -Wall -g

SRC_DIR = src
CPP_DIR = $(SRC_DIR)/cpp
H_DIR = $(SRC_DIR)/h

SRCS = $(SRC_DIR)/main.cpp $(CPP_DIR)/InputGenerator.cpp $(CPP_DIR)/BlockCommander.cpp $(CPP_DIR)/QuickSort.cpp $(CPP_DIR)/SaveFiles.cpp $(CPP_DIR)/PolyPhase.cpp $(CPP_DIR)/b_tree.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(EXEC)