all: r2.o d1.o c1.o

r2.o: record2.c
	gcc -o MMMr2 record2.c -lm `pkg-config --cflags --libs opencv` 

d1.o: device.cpp
	g++ -o MMMd1 device.cpp -lm `pkg-config --cflags --libs opencv` -fpermissive

c1.o: copy.c
	gcc -o MMMc1 copy.c

clean:
	rm MMM*

