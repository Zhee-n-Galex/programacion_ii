CC = gcc -Wall
LIBS = -L ./ -lvectordinamico
HEADER_FILES_DIR = .
INCLUDES = -I $(HEADER_FILES_DIR)

MAIN = vdinamico

SRCS = main.c

DEPS = $(HEADER_FILES_DIR)/vectordinamico.h

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c $< $(INCLUDES)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o *~