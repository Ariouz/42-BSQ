.SILENT:
.DEFAULT_GOAL: compile

COMPILE_FLAGS= -Wall -Wextra -Werror

## Colors
RESTORE=\033[0m

RED=\033[00;31m
GREEN=\033[00;32m
YELLOW=\033[00;33m
BLUE=\033[00;34m
PURPLE=\033[00;35m
CYAN=\033[00;36m
LIGHTGRAY=\033[00;37m

LRED=\033[01;31m
LGREEN=\033[01;32m
LYELLOW=\033[01;33m
LBLUE=\033[01;34m
LPURPLE=\033[01;35m
LCYAN=\033[01;36m
WHITE=\033[01;37m

compile:
	echo "$(LBLUE) Compilation des fichiers...$(RESTORE)"
	gcc $(COMPILE_FLAGS) srcs/*.c -o bsq.out
	echo "$(LGREEN) Compilation terminee.$(RESTORE)"

test: compile
	echo "$(CYAN) Lancement de l'executable...$(RESTORE)"
	./bsq.out
	echo "$(LYELLOW) Tests termines"


