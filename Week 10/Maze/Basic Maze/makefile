CXX = g++ #name of the g++ compiler
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g #debugging information
SRCS =  myRoom.cpp mazeLink.cpp
HEADERS = myRoom.h
Maze: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o maze
${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp) 

