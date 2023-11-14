CCFLAGS := -std=c++2b -Wall -Wpedantic -Wextra -Wconversion
CC :=clang++

game: obj/main.o
	clang++ -o game -lraylib obj/main.o

obj/main.o: obj src/main.cpp
	clang++ $(CCFLAGS) -c -o obj/main.o src/main.cpp

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -r ./obj/