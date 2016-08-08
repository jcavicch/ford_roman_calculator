all:	main check_roman

clean:  
	rm -f obj/*.o
	rm -f lib/*.a
	rm -f exe/main*
	rm -f main
	rm -f exe/check_roman*
	rm -f check_main

main: obj/main.o obj/roman.o lib/libroman.a
	gcc obj/main.o lib/libroman.a -o exe/main
	chmod +x exe/main
	touch main

check_roman: obj/check_roman.o lib/libroman.a
ifeq ("$(OS)","Windows_NT")
	gcc -g obj/check_roman.o lib/libroman.a -lcheck -lrt -lpthread -lm -o exe/check_roman
else
	gcc -g obj/check_roman.o lib/libroman.a -lcheck -lcheck_pic -lrt -lpthread -lm -o exe/check_roman
endif
	chmod +x exe/check_roman
	touch check_main

lib/libroman.a:	obj/roman.o
	rm -f lib/libroman.a
	ar cr lib/libroman.a obj/roman.o

obj/main.o:	src/main.c
	gcc -g -c src/main.c -o obj/main.o

obj/roman.o:	src/roman.c
	gcc -g -c src/roman.c -o obj/roman.o

obj/check_roman.o:	tests/check_roman.c
	gcc -g -c tests/check_roman.c -o obj/check_roman.o

