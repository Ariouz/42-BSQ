.DEFAULT_GOAL: compile

COMPILE_FLAGS= -Wall -Wextra -Werror
MAPS= maps/map1 maps/map2 maps/map3

compile:
	clang $(COMPILE_FLAGS) srcs/*.c -o bsq.out

test: compile
	./bsq.out $(MAPS)
