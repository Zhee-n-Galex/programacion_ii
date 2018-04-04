CC = gcc -Wall
LIBS = -lm
HEADER_FILES_DIR = ./
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN = ex

SRCS = main.c seleccion.c burbuja.c quicksort.c vectordinamico.c

DEPS = $(HEADER_FILES_DIR)/seleccion.h $(HEADER_FILES_DIR)/burbuja.h $(HEADER_FILES_DIR)/quicksort.h $(HEADER_FILES_DIR)/vectordinamico.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o *~