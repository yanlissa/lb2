all: Main.o Vector.o Matrix.o
	g++ $^ -o all

Main.o: Main.cpp Matrix.h Vector.h Exception.h
	g++ -c $< -o $@

Vector.o: Vector.cpp Vector.h
	g++ -c $< -o $@

Matrix.o: Matrix.cpp Matrix.h
	g++ -c $< -o $@

clean:
	rm -f Main.o Vector.o Matrix.o all
