CC = gcc

CFLAGS = -Wall -Wno-comment -W -std=c17
LFLAGS = $(libG3X) $(DBG_LIB)
INCLUDE = $(incG3X)
SOURCE = src/

NAME = scene

$(NAME): scene.o cube.o sphere.o cylinder.o torus.o cone.o shape.o node.o
	$(CC) -o $(NAME) $^ $(LFLAGS)
	rm *.o

cube.o: $(SOURCE)cube.c $(SOURCE)shape.h	
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)cube.c

cone.o: $(SOURCE)cone.c $(SOURCE)shape.h	
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)cone.c

cylinder.o: $(SOURCE)cylinder.c	$(SOURCE)shape.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)cylinder.c

scene.o: $(SOURCE)scene.c $(SOURCE)shape.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)scene.c

sphere.o: $(SOURCE)sphere.c	$(SOURCE)shape.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)sphere.c

torus.o: $(SOURCE)torus.c	$(SOURCE)shape.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)torus.c

shape.o: $(SOURCE)shape.c $(SOURCE)shape.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)shape.c

node.o: $(SOURCE)node.c $(SOURCE)node.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)node.c

clean:
	rm *.o
	rm $(NAME)