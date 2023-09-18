CC=g++
CFLAGS=-c -Wall

start_main:
	$(CC) lab_1_main.cpp lab_1_separation.cpp  && ./a.out && rm -rf *.out

start_test: 
	$(CC) lab_1_separation.cpp lab_1_test.cpp -lgtest && ./a.out && rm -rf *.out
