udpserv01.out : udpserv01.o util.o
	gcc -std=c99 -o udpserv01.out udpserv01.o util.o
udpserv01.o : udpserv01.c util.c
	gcc -std=c99 -c udpserv01.c
util.o : util.c
	gcc -std=c99 -c util.c
clean :
	rm *.o udpserv01.out
