game: obj/main.o
	clang++ -o game -lraylib obj/main.o

obj/main.o: obj src/main.cpp
	clang++ -Wall -Wpedantic -Wextra -Wconversion -c -o obj/main.o -std=c++2b src/main.cpp

obj:
	mkdir obj

.PHONY: clean
clean:
	rm -r ./obj/