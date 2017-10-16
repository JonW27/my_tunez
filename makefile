all: work06.o main.o
	gcc -o work06 work06.o main.o

work06.o: work06.c work06.h
	gcc -c work06.c

main.o: main.c work06.h
	gcc -c main.c

clean:
	rm *.o
	rm *~

run: all
	./work06
