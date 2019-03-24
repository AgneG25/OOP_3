main: functions.o
	g++ -o main main.cpp functions.o
functions:
	g++ functions.cpp
clean:
	rm *.o main
