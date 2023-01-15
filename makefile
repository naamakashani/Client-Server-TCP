all: server client
server: server.cpp
	g++ -std=c++11 -pthread -o server.out Server.cpp Server.h Distance.h EuclideanDistance.cpp EuclideanDistance.h ManhattanDistance.cpp ManhattanDistance.h ChebyshevDistance.cpp ChebyshevDistance.h CanberraDistance.cpp CanberraDistance.h MinkowskiDistance.cpp MinkowskiDistance.h DefaultIO.cpp Distance.h StandardIO.cpp StandardIO.h Data.cpp Data.h Command.h Command.cpp chooseOne.cpp chooseOne.h chooseTwo.cpp chooseTwo.h knn.cpp knn.h chooseThree.h chooseThree.cpp chooseFour.cpp chooseFour.h chooseFive.cpp chooseFive.h CLI.cpp CLI.h SocketIO.cpp SocketIO.h

client: client.cpp
	g++ -std=c++11 -pthread -o client.out client.cpp client.h
clean:
	rm client server


