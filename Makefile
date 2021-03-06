# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 13:12:27 by hdezier           #+#    #+#              #
#    Updated: 2016/04/23 19:44:28 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
TARGET = factrace

#Directories
BIN_DIR =
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

#Options
CC = clang
SRC_EXT = .c
RM = rm -rf

#List classes here
CLASS = main\
		read_input\
		find_prime\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

#Flags
CFLAGS = -Wall -Wextra -Werror -O3
LFLAGS =

#Libs
LIB_LOCAL = \
			lib/gmp

LIB_GLOBAL = \

LIB_OTHER = \
			-lgmp\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)

re : fclean all

.PHONY: all clean fclean re

.SILENT: dirlib dirbuild dirbin

#Build rule
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLINK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCOMPILE:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
