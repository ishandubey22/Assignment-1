hanoi: a1-5.cpp
	# write the command for compiling a1-5.cpp to a1-5.out
	
median: a1-4.cpp
	# this the default target to compile the C++ program, which would be executed if you just run `make` without any arguments

default: a1-4.cpp
	median: a1-4.cpp
	g++ a1-4.cpp -o a1-4.out

 
clean:
	del *.out 
