
EXE = myar
CC = gcc
DEBUG =-g
OPTIMIZE = -Os
CFLAGS = -Wall $(DEBUG) $(OPTIMIZE)
SRC =	myar.c main.c
OBJ = $(SRC:.c=.o)
FILE1 = 1-s.txt 
FILE2 = 2-s.txt 
FILE3 = 3-s.txt 
FILE4 = 4-s.txt 
FILE5 = 5-s.txt
FILEARGS = $(FILE1) $(FILE2) $(FILE3) $(FILE4) $(FILE5)
FILE135 = $(FILE1) $(FILE3) $(FILE5)
FILE24 = $(FILE2) $(FILE4)

all: $(EXE) tests

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(CFLAGS) $(OBJ)

$(OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f $(EXE)
	@rm -f ar-ctoc.txt ar-vtoc.txt myar-ctoc.txt myar-vtoc.txt
	@rm -f ar*.ar myar*.ar
	@echo Done cleaning
#############################################################################################
testq12345: $(EXE)
	@rm -f ar12345.ar
	@rm -f myar12345.ar
	@ar q ar12345.ar $(FILEARGS)
	@./$(EXE) -q myar12345.ar $(FILEARGS)
	diff ar12345.ar myar12345.ar

testq135: $(EXE)
	@rm -f ar135.ar
	@rm -f myar135.ar
	@ar q ar135.ar 1-s.txt 3-s.txt 5-s.txt
	@./$(EXE) -q myar135.ar 1-s.txt 3-s.txt 5-s.txt
	diff ar135.ar myar135.ar

testq24: $(EXE)
	@rm -f ar24.ar
	@rm -f myar24.ar
	@ar q ar24.ar 2-s.txt 4-s.txt
	@./$(EXE) -q myar24.ar 2-s.txt 4-s.txt
	diff ar24.ar myar24.ar

testq:	testq12345 testq135 testq24
#############################################################################################
testt12345:
	@rm -f ar12345.ar
	@ar q ar12345.ar $(FILEARGS)
	@ar t ar12345.ar > ar-ctoc.txt
	@./$(EXE) -t ar12345.ar > myar-ctoc.txt
	diff ar-ctoc.txt myar-ctoc.txt

testt135:
	@rm -f ar135.ar
	@ar q ar135.ar $(FILE135)
	@ar t ar135.ar > ar-ctoc.txt
	@./$(EXE) -t ar135.ar > myar-ctoc.txt
	diff ar-ctoc.txt myar-ctoc.txt

testt24:
	@rm -f ar24.ar
	@ar q ar24.ar $(FILE24)
	@ar t ar24.ar > ar-ctoc.txt
	@./$(EXE) -t ar24.ar > myar-ctoc.txt
	diff ar-ctoc.txt myar-ctoc.txt

testt: testt12345 testt135 testt24

#############################################################################################
testv12345:
	@rm -f ar12345.ar
	@ar q ar12345.ar $(FILEARGS)
	@ar tv ar12345.ar > ar-vtoc.txt
	@./$(EXE) -v ar12345.ar > myar-vtoc.txt
	diff ar-vtoc.txt myar-vtoc.txt

testv135:
	@rm -f ar135.ar
	@ar q ar135.ar $(FILE135)
	@ar tv ar135.ar > ar-vtoc.txt
	@./$(EXE) -v ar135.ar > myar-vtoc.txt
	diff ar-vtoc.txt myar-vtoc.txt

testv24:
	@rm -f ar24.ar
	@ar q ar24.ar $(FILE24)
	@ar tv ar24.ar > ar-vtoc.txt
	@./$(EXE) -v ar24.ar > myar-vtoc.txt
	diff ar-vtoc.txt myar-vtoc.txt

testv: testv12345 testv135 testv24

#############################################################################################
tests: testq testt testv
