CCFLAGS := -std=c++2b -Wall -Wpedantic -Wextra -Wconversion
CC :=clang++

game: obj/main.o obj/rendercomponent.o
	$(CC) -o game -lraylib -fsanitize=address obj/main.o

obj/main.o: obj src/main.cpp
	$(CC) $(CCFLAGS) -Isrc/ -g -fsanitize=address -c -o obj/main.o src/main.cpp

obj/rendercomponent.o: obj src/rendercomponent.cpp
	$(CC) $(CCFLAGS) -Isrc/ -g -fsanitize=address -c -o obj/rendercomponent.o src/rendercomponent.cpp

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -r ./obj/