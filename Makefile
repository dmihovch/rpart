all: main.c src/rpart.c
	gcc -o rpart main.c src/rpart.c

clean: rpart
	rm rpart

run: rpart
	./rpart

valgrind: rpart
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./rpart
