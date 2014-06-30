BASEDIR = ..
BUILD_DIR = bin
CXX_FILES = $(wildcard *.cpp)
CXX_FLAGS = -g -Wall -std=c++11 -I/usr/local/include/ -L/usr/local/lib -I../include -L../lib
LIBS = -lveil -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -luv
RM_RF := rm -rf
CP_R := cp -r

.PHONY: all
all: bin bin/assets
	$(CXX) $(CXX_FLAGS) $(CXX_FILES) $(LIBS) -o bin/game

bin/assets:
	@$(CP_R) assets bin

bin:
	@mkdir bin

.PHONY: clean
clean:
	-$(RM_RF) $(BUILD_DIR)
