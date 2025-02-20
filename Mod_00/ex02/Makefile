#******************************************************************************#
#	FEATURES
#******************************************************************************#

RESET		:=	\e[0m
BOLD		:=	\e[1m
BLINK		:=	\e[5m
GREEN		:= 	\e[38;2;173;235;179m
YELLOW		:=	\e[38;2;255;234;150m
BLUE		:=	\e[34m
BLUE2		:=	\e[38;2;179;235;242m
CYAN		:=	\e[36m

#******************************************************************************#
#	COMPILATION
#******************************************************************************#

NAME		=	GBU
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
DFLAGS		=	-MMD -MP

#******************************************************************************#
#	SOURCES
#******************************************************************************#

SRCS		=	Account.cpp tests.cpp
OBJS_DIR	=	objs/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.d))

#******************************************************************************#
#	RULES
#******************************************************************************#

all: $(NAME)

$(OBJS_DIR)%.o: %.cpp
				@mkdir -p $(OBJS_DIR)
				$(CPP) $(CPPFLAGS) $(DFLAGS) -c $< -o $@
-include $(DEPS)

$(NAME): $(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@printf "\n\n============$(BLUE2) GlobalBanksters United $(RESET)"
			@printf "============\n\n$(BLINK)$(GREEN)\t\t   READY!$(RESET)\n\n"
			@printf "$(BOLD)================================================\n\n$(RESET)"

clean:
		rm -rf $(OBJS_DIR)
		@printf "$(BOLD)$(BLUE)[objs]:\t $(RESET)Clean completed\n\n"

fclean:	clean
			rm -rf $(NAME)
			@printf "$(BOLD)$(CYAN)[execs]: $(RESET)Full clean completed!\n\n"

re:	fclean all
		@printf "\n$(BOLD)$(YELLOW)make re: $(RESET)All files have been rebuilt! ✨\n\n"

.PHONY:	all clean fclean re