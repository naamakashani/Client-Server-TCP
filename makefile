all: clean server client
server: Server.cpp
	g++ -std=c++11 -pthread -o server.out Server.cpp Server.h Distance.h EuclideanDistance.cpp EuclideanDistance.h ManhattanDistance.cpp ManhattanDistance.h ChebyshevDistance.cpp ChebyshevDistance.h CanberraDistance.cpp CanberraDistance.h MinkowskiDistance.cpp MinkowskiDistance.h DefaultIO.cpp Distance.h StandardIO.cpp StandardIO.h Data.cpp Data.h Command.h Command.cpp chooseOne.cpp chooseOne.h chooseTwo.cpp chooseTwo.h knn.cpp knn.h chooseThree.h chooseThree.cpp chooseFour.cpp chooseFour.h chooseFive.cpp chooseFive.h CLI.cpp CLI.h SocketIO.cpp SocketIO.h

client: Client.cpp
	g++ -std=c++11 -pthread -o client.out Client.cpp Client.h
clean:
	if [ -f client.out ]; then rm client.out; fi
	if [ -f server.out ]; then rm server.out; fi

