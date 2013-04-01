
CC = clang
FILES = main.c discrete_function.c network_evolve.c
EXEC_TARGET = robusta

debug: $(FILES)
	$(CC) -o $(EXEC_TARGET) -g $(FILES)

release: $(FILES)
	$(CC) -o $(EXEC_TARGET) -O2s $(FILES)

clean:
	rm -f *.o core

rebuild: clean debug

rebuild_release: clean release

