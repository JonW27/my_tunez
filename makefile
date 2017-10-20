all: linked_list.o main.o arr.o
	gcc -o linked_list linked_list.o main.o

work06.o: linked_list.c linked_list.h
	gcc -c linked_list.c

main.o: main.c linked_list.h
	gcc -c main.c

clean:
	rm *.o
	rm *~

run: all
	./linked_list
