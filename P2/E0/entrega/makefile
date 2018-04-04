CC = gcc -Wall
LIBS = -lm
HEADER_FILES_DIR = ./TAD
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN = ex

SRCS = main.c $(HEADER_FILES_DIR)/cola.c $(HEADER_FILES_DIR)/listas.c

DEPS = $(HEADER_FILES_DIR)/cola.h $(HEADER_FILES_DIR)/listas.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES) -o $@

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o *~
	rm -f TAD/*.o