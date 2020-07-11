CXX = g++
CXXFLAGS = -std=c++14 -g -Werror=vla -MMD
EXEC = crossroad
OBJECTS = main.o player.o game.o lane.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
		rm ${OBJECTS} ${EXEC} ${DEPENDS}

