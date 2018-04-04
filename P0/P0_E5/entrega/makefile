$CC = gcc -Wall
LIBS = -lm

MAIN = ex5

SRCS = main.c potencia.c

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS) $(LIBS)

cleanall: clean
	rm -f $(MAIN)

clean:
	rm -f *.o *~