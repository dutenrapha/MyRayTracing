SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib
INC_PATH = -I ./include

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB_NAME = libvectors.a
MAIN = main.c
EXEC = exec.x
TESTER = Unity/unity.c


MAIN_O = $(MAIN:.c=.o)
LIB = $(LIB_PATH)/$(LIB_NAME)
SRC = $(notdir $(wildcard ./src/*.c))
OBJ=$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all:	$(OBJ) $(LIB)

run:	$(EXEC)
	@./$<

clean:
	@rm -f $(OBJ_PATH)/*.o

fclean:	clean
	@rm -f $(LIB_PATH)/*.a
	@rm -f *.x
	@rm -f *.o

re: fclean all

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -c $< -o $@  		

$(LIB_PATH)/%.a:
	@ar rcs $(LIB) $(OBJ) 

%.x:
	@$(CC) $(INC_PATH) -c $(MAIN)
	@$(CC) -o $@ $(MAIN_O) $(LIB_PATH)/$(LIB_NAME)
	@rm -f *.o

tester = Unity/unity.c 

test:	fclean all test.x

test.x:	chapter1.c
	@$(CC) $^ $(TESTER) $(LIB_PATH)/$(LIB_NAME)  -o $@
	@./$@
	@rm -fR $@
