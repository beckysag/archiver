CC = gcc
CFLAGS = -Wall $(DEBUG) $(OPTIMIZE)
DEBUG =-g
EXE = myar
OPTIMIZE = -Os
SRC =	myar.c main.c
OBJ = $(SRC:.c=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(CFLAGS) $(OBJ)

$(OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f $(EXE)
	@rm -f ar*.ar myar*.ar
	@echo Done cleaning
