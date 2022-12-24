CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=vpl_execution

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${TARGET}: ${BUILD_DIR}/Heroi.o ${BUILD_DIR}/Vilao.o ${BUILD_DIR}/Personagem.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${TARGET}

${BUILD_DIR}/Heroi.o: ${INCLUDE_DIR}/Personagem.hpp ${INCLUDE_DIR}/Heroi.hpp ${SRC_DIR}/entidades/Heroi.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Heroi.cpp -o ${BUILD_DIR}/Heroi.o
	
${BUILD_DIR}/Personagem.o: ${INCLUDE_DIR}/Personagem.hpp ${SRC_DIR}/entidades/Personagem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Personagem.cpp -o ${BUILD_DIR}/Personagem.o

${BUILD_DIR}/Vilao.o: ${INCLUDE_DIR}/Personagem.hpp ${INCLUDE_DIR}/Vilao.hpp ${SRC_DIR}/entidades/Vilao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/entidades/Vilao.cpp -o ${BUILD_DIR}/Vilao.o


${BUILD_DIR}/main.o: ${INCLUDE_DIR}/Personagem.hpp ${INCLUDE_DIR}/Heroi.hpp ${INCLUDE_DIR}/Vilao.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it

clean:
	rm -f ${BUILD_DIR}/*
