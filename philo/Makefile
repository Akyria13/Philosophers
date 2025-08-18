########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR			:=		jowagner
NAME			:= 		philo

CC				:= 		cc
CFLAGS			:= 		-Wall -Wextra -Werror -MD -MP -Iinc/ -g3 -pthread

SRC				:=		src/main.c \
						src/parsing.c

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

INC_PATH		:=		inc/
SRC_PATH		:=		src/
OBJ_DIR			:= 		obj/

OBJ             := 		$(SRC:$(SRC_PATH)%.c=$(OBJ_DIR)%.o)

DEP				:=		$(OBJ:%.o=%.d)
override DIRS	:=		$(sort $(dir $(NAME) $(OBJ) $(DEP)))

########################################################################################################################
#                                                      TARGETS                                                         #
########################################################################################################################

all : 					.print_header $(NAME)

clean :					.print_header
							@printf "%-50b%b" "$(YELLOW)[philo/$(OBJ_DIR)] :$(RESET)" "\n"
							rm -rf $(OBJ_DIR)
							@printf "%-50b%b" "=> $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							@printf "\n"

fclean : 				clean
							@printf "%-50b%b" "$(YELLOW)[$(NAME)] :$(RESET)" "\n"
							rm -f $(NAME)
							@printf "%-50b%b" "=> $(BOLD_RED)Clean$(RESET)" $(call PROGRESS_BAR) "$(BOLD_GREEN)[✓]$(RESET)\n"
							$(call SEPARATOR)

re : 					.print_header fclean all $(NAME)

.print_header :
							$(call TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)


########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME) 			: 	$(OBJ)
							$(CC) -o $(NAME) $(OBJ)

$(OBJ)				:	| $(DIRS)

$(DIRS):
							mkdir -p $@

$(OBJ_DIR)%.o		:	 $(SRC_PATH)%.c $(INC_PATH)philo.h
							$(CC) $(CFLAGS) -c -o $@ $<

-include $(DEP)

########################################################################################################################
#                                                      DISPLAY                                                         #
########################################################################################################################

MAGENTA			:=		\033[0;95m
YELLOW			:=		\033[1;93m
GREEN 			:=		\033[0;32m
BLUE			:=		\033[0;94m
RED 			:=		\033[0;31m

BOLD_YELLOW 	:=		\e[1;33m
BOLD_PURPLE		:=		\e[1;35m
BOLD_GREEN		:= 		\e[1;32m
BOLD_WHITE		:=		\e[1;37m
BOLD_CYAN 		:= 		\e[1;36m
BOLD_BLUE 		:= 		\e[1;34m
BOLD_RED 		:=		\e[1;31m

RESET 			:=		\033[0m

define	TITLE
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@echo "$(BOLD_YELLOW)  _____  _     $(BOLD_GREEN)_$(BOLD_YELLOW) _                       _                   "
						@echo "$(BOLD_YELLOW) |  __ \| |   $(BOLD_GREEN)(_)$(BOLD_YELLOW) |                     | |                  "
						@echo "$(BOLD_YELLOW) | |__) | |__  _| | ___  ___  ___  _ __ | |__   ___ _ __ ___ "
						@echo "$(BOLD_YELLOW) |  ___/| '_ \| | |/ _ \/ __|/ _ \| '_ \| '_ \ / _ \ '__/ __|"
						@echo "$(BOLD_YELLOW) | |    | | | | | | (_) \__ \ (_) | |_) | | | |  __/ |  \__ \ "
						@echo "$(BOLD_YELLOW) |_|    |_| |_|_|_|\___/|___/\___/| .__/|_| |_|\___|_|  |___/"
						@echo "$(BOLD_GREEN) ________________________________ $(BOLD_YELLOW)| | $(BOLD_GREEN)_______________________"
						@echo "$(BOLD_YELLOW)                                  |_|                        "
endef

define PROGRESS_BAR

						@echo -n "$(BOLD_YELLOW)["
						@i=1; while [ $$i -le 3 ]; do echo -n "$(BOLD_WHITE)."; sleep 0.2; i=$$((i + 1)); done
						@echo -n "$(BOLD_YELLOW)]"
endef


define	BUILD
						@printf "%-32b%b" "  $(BOLD_CYAN)AUTHOR :$(RESET)" "$(BOLD_WHITE)$(AUTHOR)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)NAME   :$(RESET)" "$(BOLD_WHITE)$(NAME)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)CC     :$(RESET)" "$(BOLD_WHITE)$(CC)$(RESET)\n";
						@printf "%-32b%b" "  $(BOLD_CYAN)FLAGS  :$(RESET)" "$(BOLD_WHITE)$(CFLAGS)$(RESET)\n";
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(MAGENTA)---------------------------------------------------$(RESET)";
						@printf "\n"
endef

########################################################################################################################
#                                                       PHONY TARGETS                                                  #
########################################################################################################################

.PHONY : 				all clean fclean re .print_header