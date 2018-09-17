all: smaz_test  

smaz_test: smaz_test.c smaz.c
	gcc -o smaz_test -O2 -Wall -W -ansi -pedantic smaz.c smaz_test.c

benchmark: benchmark.c smaz.c
	gcc -o benchmark -O2 -Wall -Wdeclaration-after-statement -W -ansi -pedantic smaz.c benchmark.c


clean:
	rm -rf smaz_test benchmark
