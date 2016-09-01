DIR_OBJ=.
DIR_SRC=.
DIR_BIN=.

SRC=$(wildcard ${DIR_SRC}/*.cpp)
OBJ=$(patsubst %.cpp,${DIR_OBJ}/%.o,$(notdir ${SRC})) 

TARGET=main

BIN_TARGET=${DIR_BIN}/${TARGET}

CC=g++
CFLAGS=-g -Wall

${BIN_TARGET}:${OBJ}
	$(CC) $(OBJ) -o $@
${DIR_OBJ}/%.o:${DIR_SRC}/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	find ${DIR_OBJ} -name "*.o" -exec rm {} \;
