CXX = g++ 
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g 
SRCS =  myRoom.cpp trackMoveMaze.cpp
HEADERS = myRoom.h
Maze: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o trackMaze
${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp) 

