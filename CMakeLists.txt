cmake_minimum_required(VERSION 3.23)
project(try)

set(CMAKE_CXX_STANDARD 14)


add_executable(server Server.cpp Server.h Distance.h EuclideanDistance.cpp EuclideanDistance.h ManhattanDistance.cpp ManhattanDistance.h ChebyshevDistance.cpp ChebyshevDistance.h CanberraDistance.cpp CanberraDistance.h MinkowskiDistance.cpp MinkowskiDistance.h DefaultIO.cpp Distance.h StandardIO.cpp StandardIO.h Data.cpp Data.h Command.h Command.cpp chooseOne.cpp chooseOne.h chooseTwo.cpp chooseTwo.h knn.cpp knn.h chooseThree.h chooseThree.cpp chooseFour.cpp chooseFour.h chooseFive.cpp chooseFive.h CLI.cpp CLI.h SocketIO.cpp SocketIO.h)
add_executable(client Client.cpp Client.h)