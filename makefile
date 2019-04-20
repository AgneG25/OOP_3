main: functions.o console.o
	g++ -o main main.cpp functions.o console.o
functions:
	g++ functions.cpp
console:
	g++ console.cpp
clean:
	rm *.o main
