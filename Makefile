all: nn

nn: nn.c

	$(CC) -o nn nn.c -Wall -W -pedantic -std=c99 -lm
	@echo Compilation completed successfully!

clean:

	rm nn
	@echo NearestNeighbor removed