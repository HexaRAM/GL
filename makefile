COMP=g++
CFLAGS=-std=c++11
CFLAGS_BOOST=-lboost_regex $(CFLAGS)
LDFLAGS=-lboost_regex 
EXEC=analyseur
SRC= $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
HEADER= $(wildcard src/*.h src/*/*.h src/*/*/*.h)
BUILD_DIR=object
OBJ= $(addprefix $(BUILD_DIR)/,$(notdir $(SRC:.cpp=.o)))
TEST_FOLDER=Tests
TEST_EXEC=lut

# /!\ Pas de gestion des dépendances aux headers

all: $(EXEC)
	@echo "/!\ Si vous avez modifié uniquement les headers (.h), effectuez un : make -B"
	cp $(EXEC) $(TEST_EXEC)

analyseur: $(OBJ)
	$(COMP) -o $@ $^ $(LDFLAGS) 

$(BUILD_DIR)/lexer.o : src/automate/lexer.cpp src/automate/lexer.h src/config.h
	$(COMP) $(CFLAGS_BOOST) -c -o $@ $<

$(BUILD_DIR)/%.o: src/%.cpp
	$(COMP) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/*/%.cpp src/*/%.h
	$(COMP) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/*/*/%.cpp src/*/*/%.h
	$(COMP) $(CFLAGS) -c -o $@ $<

PHONY: clean test

test:
	@echo "Execution des tests"
	./test.sh

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)
