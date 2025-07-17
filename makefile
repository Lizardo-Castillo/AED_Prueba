all: main.o 
	g++ main.o -o aed -lfreeglut -lopengl32 -lglu32

main.o: src/main.cpp
	g++ -c src/main.cpp

test:
	./aed

clean:
	rm *.o aed