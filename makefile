COMP=g++ 
CFLAGS=-W -Wall -ansi -pedantic -lboost_regex -std=c++11
#CFLAGS=
LDFLAGS=-lboost_regex 
EXEC=analyseur
SRC= $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
HEADER= $(wildcard src/*.h src/*/*.h src/*/*/*.h)
BUILD_DIR=object
OBJ= $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.cpp=.o)))

# /!\ Pas de gestion des dépendances aux headers

all: $(EXEC)
	@echo "/!\ Si vous avez modifié uniquement les headers (.h), effectuez un : make -B"

analyseur: $(OBJ)
	$(COMP) -o $@ $^ $(LDFLAGS) 

$(BUILD_DIR)/%.o: src/%.cpp
	$(COMP) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/*/%.cpp src/*/%.h
	$(COMP) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/*/*/%.cpp src/*/*/%.h
	$(COMP) $(CFLAGS) -c -o $@ $<

PHONY: clean test

test:
	@echo "Execution des tests"
	@./test.sh

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)
