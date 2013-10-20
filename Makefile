# AAFR, 20 de octubre de 2013
#
#

CC= gcc -c

CLINKER= gcc -lm -o 

CFLAGS= -O3 -Wall

LIBS= 


OBJ= main.o \
	
	
	

DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/

all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)bprimo.exe $(OBJ) $(LIBS) $(CFLAGS)

