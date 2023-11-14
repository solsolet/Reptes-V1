CCFLAGS := -std=c++2b -Wall -Wpedantic -Wextra -Wconversion
CC :=clang++

game: obj/main.o
	$(CC) -o game -lraylib obj/main.o

obj/main.o: obj src/main.cpp
	$(CC) $(CCFLAGS) -c -o obj/main.o src/main.cpp

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -r ./obj/