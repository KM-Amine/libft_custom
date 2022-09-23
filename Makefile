###################
NAME = libft.a
LIB_DIR = libs
MAIN = main
####################
SRCS_ROOT = srcs
OBJS_ROOT = objs
SUB_DIRS = $(shell ls $(SRCS_ROOT))

SRCS_DIRS = $(foreach dir,$(SUB_DIRS),$(addprefix $(SRCS_ROOT)/, $(dir)))
OBJS_DIRS = $(foreach dir, $(SUB_DIRS), $(addprefix $(OBJS_ROOT)/, $(dir)))

SRCS = $(foreach dir,$(SRCS_DIRS),$(wildcard $(dir)/*))
OBJS = $(SRCS:$(SRCS_ROOT)/%.c=$(OBJS_ROOT)/%.o)
###################
INC_DIR = includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
DEPFLAGS = -MP -MD -MF
AR = ar rcs
RM = rm -rf
MKDIR = mkdir
###################
HEADER = $(wildcard $(INC_DIR)/*.h)

DEP_ROOT = deps
DEP_DIRS = $(foreach dir, $(SUB_DIRS), $(addprefix $(DEP_ROOT)/, $(dir)))
DEPS = $(SRCS:$(SRCS_ROOT)/%.c=$(DEP_ROOT)/%.d)

###################
all : $(OBJS_ROOT) $(DEP_ROOT) $(LIB_DIR) $(LIB_DIR)/$(NAME) $(MAIN)

$(DEP_ROOT) :
	@$(MKDIR) $(DEP_ROOT)
	@$(MKDIR) $(DEP_DIRS)
$(LIB_DIR) :
	@$(MKDIR) $(LIB_DIR)
$(OBJS_ROOT) :
	@$(MKDIR) $(OBJS_ROOT)
	@$(MKDIR) $(OBJS_DIRS)
#make a bins folder for the main executable
$(MAIN) : main.c
	@$(CC) $(CFLAGS) -c main.c -o main.o
	@$(CC) $(CFLAGS) main.o -o main -L $(LIB_DIR) -lft
	@echo main made succesfuly

#bonus : all $(BOBJS)
#	$(AR) $(NAME) $(BOBJS)
#	@echo bonus made

#are we forced to write $(NAME) or can we write $(LIB_DIR)/$(NAME)?
$(LIB_DIR)/$(NAME) : $(OBJS)
	@$(AR) $@ $^
	@echo library made succesfuly

$(OBJS_ROOT)/%.o : $(SRCS_ROOT)/%.c
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(@:$(OBJS_ROOT)/%.o=$(DEP_ROOT)/%.d) -c $< -o $@

################
clean :
	@$(RM) $(OBJS_ROOT) main.o
	@echo "clean completed";
fclean : clean
	@$(RM) $(LIB_DIR) main
	@echo "full clean completed"
re : fclean all

.PHONY : all clean fclean re


-include $(DEPS)
