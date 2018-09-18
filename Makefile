all: benchmark  

benchmark: benchmark.c
	gcc -o benchmark -std=c99 -O3 -Wall smaz/smaz.c shoco/shoco.c shoco-urlmodel/shoco-urlmodel.c benchmark.c

clean:
	rm -rf benchmark
