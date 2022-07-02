CC=gcc
FLAGS=-Wall -Wextra -c
OBJ=net.o file.o tfp.o

all: server


server : server.o $(OBJ)
	$(CC) server.o $(OBJ) -o server
	
server.o : server.c
	$(CC) $(FLAGS) server.c	
	
tfp.o : tfp.c
	$(CC) $(FLAGS) tfp.c
	
net.o : net.c
	$(CC) $(FLAGS) net.c
	
file.o : file.c
	$(CC) $(FLAGS) file.c


clean:
	rm *.o
	rm server
