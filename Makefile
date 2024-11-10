# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror

# Source and library files
LIB_SRC = catoi.c
OBJ = catoi.o
LIB_OUT_NAME = catoi

# Check if running on Windows or Linux
ifeq ($(OS),Windows_NT)
    RM = del
    LIB_EXT = .lib  # If using MinGW, you might want to use .a instead of .lib
else
    RM = rm
    LIB_EXT = .a
endif

# based on compliation platform --> molding static lib name (.a or .lib)
LIB_OUT = $(LIB_OUT_NAME)$(LIB_EXT)

# Build the static library
$(LIB_OUT): $(OBJ)
# creating an object file
	$(CC) $(CFLAGS) -c $(LIB_SRC) 
# creating the static lib
	ar rcs $(LIB_OUT) $(OBJ) 
# removing the object file after static lib creation
	$(RM) $(OBJ) 

# Clean target to remove compiled files
clean:
	$(RM) $(LIB_OUT)
