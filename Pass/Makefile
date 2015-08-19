all: g1.o m1.o

g1.o: getImage.c
	gcc -o g1 getImage.c -lm `pkg-config --cflags --libs opencv`

m1.o: measureChange.c
	gcc measureChange.c -o m1

clean:
	rm *.png
