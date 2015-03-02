COMP=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=analyseur
SRC= $(wildcard src/*/*/*.cpp)
HEADER= $(wildcard src/*/*/*.h)
BUILD_DIR=object
OBJ= $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.cpp=.o)))


all: $(EXEC)

analyseur: $(OBJ)
	$(COMP) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cpp
	$(COMP) $(CFLAGS) -c -o $@ $<

.PHONY: clean test

tests:
	@echo "Execution des tests"

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)
