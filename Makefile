CPP_FILES = $(shell find src/ -type f -name '*.cpp')
OBJ_FILES = $(CPP_FILES:src/%.cpp=obj/%.o)
CXX_FLAGS = -g -Wall -std=c++11 -I./include
RM_RF := rm -rf
RM_F := rm -f

# all also makes the game
.PHONY: all
all: static
	$(MAKE) -C game

lib:
	@mkdir $@

obj/%.o: src/%.cpp
	@-mkdir -p $(dir $@)
	$(CXX) -c -fPIC $(CXX_FLAGS) -o $@ $<

.PHONY: static
static: lib lib/libveil.a
lib/libveil.a: $(OBJ_FILES)
	$(AR) rcs $@ $^

.PHONY: shared
shared: lib lib/libveil.so
lib/libveil.so: $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -shared -o $@ $^

.PHONY: clean
clean:
	@-$(RM_RF) bin lib obj
	$(MAKE) -C game clean

# Test run build task
.PHONY: run
run: clean all
	@cd game/bin && ./game
