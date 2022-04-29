CC_FILES = $(wildcard */*.cpp)
BIN_FILES = $(notdir $(CC_FILES:.cpp=))
CC_FLAGS = -std=c++17 -pthread -O2
CC = g++

all: $(BIN_FILES)

.SECONDEXPANSION:
$(BIN_FILES): %: $$(wildcard */$$*.cpp)
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)
