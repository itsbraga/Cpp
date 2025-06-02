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

NAME		=	Replace
CPP			=	c++
CPPFLAG		=	-Wall -Wextra -Werror -std=c++98 -g3
DFLAGS		=	-MMD -MP

#******************************************************************************#
#	SOURCES
#******************************************************************************#

SRCS		=	openAndReplace.cpp main.cpp

OBJS_DIR	=	objs/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.d))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: %.cpp
				@mkdir -p $(OBJS_DIR)
				$(CPP) $(CPPFLAG) $(DFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			$(CPP) $(CPPFLAG) $(OBJS) -o $(NAME)
			@printf "\n\n$(BOLD)===========$(shell bash ../rbw.sh " Sed is for losers ")"
			@printf "$(BOLD)===========\n\n$(BLINK)$(PURPLE)\t\t READY!$(RESET)\n\n"
			@printf "$(BOLD)==========================================\n\n$(RESET)"

clean:
		rm -rf $(OBJS_DIR)
		@printf "$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n\n"

fclean:	clean
			rm -rf $(NAME)
			find . -name "*.replace" -type f -delete
			find . -name "*.txt" -type f -delete
			@printf "$(BOLD)$(CYAN)[execs]: $(RESET)Removed executable & all .replace files!\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

.PHONY: all clean fclean re