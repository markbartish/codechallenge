test:
	g++ -o pointtest pointtest.cpp -lgtest -lgmock -L/usr/local/lib
	g++ -o edgetest edgetest.cpp -lgtest -lgmock -L/usr/local/lib

app:
	g++ -o airport airport.cpp -std=c++17

run: app
	./airport < 1.in
	./airport < 2.in

clean:
	rm *.exe *~
