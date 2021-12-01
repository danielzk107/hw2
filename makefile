start: main.o my_mat.o
	make my_mat.o
	make main.o
my_mat.o: my_mat.c
	#ifndef _my_mat_o
	gcc -c my_mat.c my_mat.h
	#endif
main.o: main.c
	#ifndef _main_o
	gcc -c main.c my_mat.h
	#endif
my_mat.a:
	#ifndef _my_mat_a
	ar rc my_mat.a main.o my_mat.o my_mat.h
	#endif
all:
	make my_mat.o
	make main.o
	make my_mat.a
	ranlib my_mat.a
	gcc main.o my_mat.o my_mat.h -o connections
clean:
	rm *.o 
	rm -f *.a
	rm -f *.h.gch
	rm -f connections
