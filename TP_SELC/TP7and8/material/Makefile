## Definifion of variables

CC=gcc
LD=gcc
AR=ar
RM=rm

SRC_DIR=./src
LIB_DIR=./lib
INCLUDE_DIR=./include

CFLAGS=-Wall -I${INCLUDE_DIR} -c
LDFLAGS=-L${LIB_DIR} -o

LIB_FILES=liblinked-list-utils.a
LIB_NAME=linked-list-utils

EXEC_NAME=linked-list-exe

## Target liblinked-list-utils.a
## archive linked-list.o into library liblinked-list-utils.a
${LIB_DIR}/${LIB_FILES}: linked-list.o
	${AR} -r $@ $^ 


## Target main.o
## compile main.c to produce an object file (main.o)
main.o: ${SRC_DIR}/main.c
	${CC} ${CFLAGS} $<


## Target linked-list.o
## compile linked-list.c to produce an object file (linked-list.o)
linked-list.o: ${SRC_DIR}/linked-list.c
	${CC} ${CFLAGS} $<

## Target $(EXEC_NAME)
## link liblinked-list-utils.a and main.o to produce the executable (linked-list-exe)
$(EXEC_NAME): depend ${LIB_DIR}/${LIB_FILES} main.o
	${LD} main.o -l${LIB_NAME} ${LDFLAGS} $@

## Target all: Useful? Where should be put in the makefile?
all: $(EXEC_NAME)


## Target clean
clean:
	$(RM) -f *.o $(LIB_DIR)/*.a $(EXEC_NAME)

depend:
	${CC} -MM $(SRC_DIR)/*.c -I$(INCLUDE_DIR) > depend

-include depend