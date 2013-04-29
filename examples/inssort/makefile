test_inssort:test_inssort.o inssort.o
	gcc -o $@ $^
test_inssort.o:test_inssort.c inssort.h
	gcc -c $<
inssort.o:inssort.c inssort.h
	gcc -c $<
