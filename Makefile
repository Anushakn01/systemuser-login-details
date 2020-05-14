logoutput: main.o UserLogin.o
	g++ main.o UserLogin.o -o logoutput

main.o: main.cpp
	g++ -c main.cpp
        
UserLogin.o: UserLogin.cpp UserLogin.h
	g++ -c UserLogin.cpp

clean:
	rm *.o logoutput;
