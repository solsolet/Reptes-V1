CCFLAGS := -std=c++2b -Wall -Wpedantic -Wextra -Wconversion
CC 		:=clang++
OBJ		:=obj/main.o obj/rendercomponent.o obj/physicscomponent.o
INCLUDE :=-Isrc/

game: $(OBJ)
	$(CC) -o $@ -lraylib -fsanitize=address $^

obj/main.o: src/main.cpp | obj
	$(CC) $(CCFLAGS) $(INCLUDE) -g -fsanitize=address -c -o $@ $^

obj/rendercomponent.o: src/rendercomponent.cpp | obj
	$(CC) $(CCFLAGS) $(INCLUDE) -g -fsanitize=address -c -o $@ $^

obj/physicscomponent.o: src/physicscomponent.cpp | obj
	$(CC) $(CCFLAGS) $(INCLUDE) -g -fsanitize=address -c -o $@ $^

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -rf ./obj/