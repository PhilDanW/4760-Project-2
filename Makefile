CC = gcc
CFLAGS = -Wall -g

HEADER = shared.h

MASTER_SRC = master.c
MASTER_OBJ = $(MASTER_SRC:.c=.o)
MASTER = master

OBJ = shared.o

OUTPUT = $(MASTER)

all: $(OUTPUT)

$(MASTER): $(MASTER_OBJ) $(OBJ)
      $(CC) $(CFLAGS) $(MASTER_OBJ) $(OBJ) -o $(MASTER)

%.o: %.c $(HEADER)
      $(CC) $(CFLAGS) -c $*.c -o $*.o
clean:
      $(RM) $(OUTOUT)
