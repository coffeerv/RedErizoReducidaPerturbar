
CC = clang
FILES = main.c discreteFunction.c networkEvolve.c
OUT_EXE = robustaCLI

debug: $(FILES)
	$(CC) -o $(OUT_EXE) -g $(FILES)

release: $(FILES)
	$(CC) -o $(OUT_EXE) -O2s $(FILES)

clean:
	rm -f *.o core

rebuild: clean debug

rebuildRelease: clean release

