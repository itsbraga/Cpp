#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
BLINK		:=	\e[5m
YELLOW		:=	\e[38;2;255;234;150m
BLUE		:=	\e[34m
CYAN		:=	\e[36m
PURPLE		:=	\e[38;2;224;176;255m

#******************************************************************************#
#	COMPILATION
#******************************************************************************#

NAME		=	convert
CPP			=	c++
CPPFLAG		=	-Wall -Wextra -Werror -std=c++98 -g3
MULT_HERIT	=	-Wshadow
DFLAGS		=	-MMD -MP

#******************************************************************************#
#	SOURCES
#******************************************************************************#

SRCS		=	main.cpp ScalarConverter.cpp helpers.cpp

OBJS_DIR	=	objs/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.d))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: %.cpp
				@mkdir -p $(OBJS_DIR)
				$(CPP) $(CPPFLAG) $(MULT_HERIT) $(DFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			$(CPP) $(CPPFLAG) $(MULT_HERIT) $(OBJS) -o $(NAME)
			@printf "\n\n$(BOLD)========$(shell bash ../rbw.sh " ScalarConverter ")"
			@printf "$(BOLD)========\n\n$(BLINK)$(PURPLE)\t     READY!$(RESET)\n\n"
			@printf "$(BOLD)=================================\n\n$(RESET)"

clean:
		rm -rf $(OBJS_DIR)
		@printf "$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n\n"

fclean:	clean
			rm -rf $(NAME)
			@printf "$(BOLD)$(CYAN)[execs]: $(RESET)Full clean completed!\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

.PHONY: all clean fclean re