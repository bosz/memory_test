all: libmem.a test_main.o
	gcc -Wall -O2 -o memgame test_main.o libmem.a
	@echo
	@echo Finished building  memgame
	@echo You can run it with  ./memgame

libmem.a: functions_memory.o
	@echo
	@echo Creating libmem.a
	ar crv libmem.a functions_memory.o
	ranlib libmem.a

functions_memory.o: functions_memory.c  functions_memory.h
	@echo
	@echo Compiling functions_memory.c
	gcc -Wall -I .  -c functions_memory.c

test_main.o: test_main.c
	@echo
	@echo Compiling test_main.c
	gcc -Wall -c test_main.c

clean: 
			-rm -rf  *.o *.a memgame