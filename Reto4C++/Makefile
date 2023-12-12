CCFLAGS :=-std=c++2b -Wall -Wpedantic -Wextra -Wconversion
CC      :=clang++
OBJ     :=obj/main.o obj/rendercomponent.o obj/physicscomponent.o obj/entitymanager.o obj/lifecomponent.o
INCLUDE :=-Isrc/

game: $(OBJ)
	$(CC) -o $@ -lraylib  $^

obj/%.o: src/%.cpp | obj
	$(CC) $(CCFLAGS) $(INCLUDE) -g  -c -o $@ $^

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -rf ./obj/