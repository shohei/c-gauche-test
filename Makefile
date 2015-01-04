CFLAGS = `gauche-config -I` \
		 `gauche-config -L` \
		`gauche-config -l` \

all:
	gcc $(CFLAGS) -o main main.c
