CC=g++

main: main.cpp sbase.o
	$(CC) -o $@ $^

sbase: sbase.h sbase.cpp
	$(CC) -c $@ sbase.cpp

clean:
	rm *.o
