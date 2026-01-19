all: main.c src/physics.c src/drawing.c src/particle.c
	gcc -o rpart main.c src/drawing.c src/physics.c src/particle.c -lraylib -lm -ldl -pthread

clean: rpart
	rm rpart

run: rpart
	./rpart

valgrind: rpart
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./rpart
