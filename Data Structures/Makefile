CPP = g++
CPP_FLAGS = "-std=c++17"

TARGETS = union-find-set

all: ${TARGETS}

%: %.cpp 
	${CPP} ${CPP_FLAGS} $^ -o $@

clean:
	rm ${TARGETS}

run:
	make && ./main && make clean 

.PHONY: all clean run