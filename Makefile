# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kosadchu <kosadchu@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 16:24:43 by kosadchu          #+#    #+#              #
#    Updated: 2019/02/15 19:15:03 by kosadchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		fillit

SRCDIR :=	src/
INCDIR :=	includes/
LIBDIR :=	libft/
OBJDIR :=	.obj/

CC :=		clang
CFLAGS :=	-Wall -Wextra -Werror
IFLAGS :=	-I $(INCDIR)
LFLAGS :=	-lft -L $(LIBDIR)

LIB :=		$(LIBDIR)libft.a
INC :=		fillit
SRC :=		validator main tet_coord tetro_save_list map solve
#liba lib

INCS :=		$(addprefix $(INCDIR), $(addsuffix .h, $(INC)))
SRCS :=		$(addprefix $(SRCDIR), $(addsuffix .c, $(SRC)))
OBJS :=		$(addprefix $(OBJDIR), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME):	$(LIB) $(OBJDIR) $(OBJS)
	@ $(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)
$(LIB):
	@ make -C $(LIBDIR) libft.a

$(OBJDIR):
	mkdir -p $(OBJDIR)$(SRCDIR)
$(OBJDIR)%.o:		%.c $(INCS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

mclean:
	rm -rf $(OBJDIR)
mfclean: mclean
	rm -rf $(NAME)
mre: mfclean all

clean: mclean
	make clean -C $(LIBDIR)
fclean: clean mfclean
	make fclean -C $(LIBDIR)
re: fclean all

.PHONY: $(LIB) all clean fclean re

