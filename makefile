# if you want to dive into makefiles have a look at:
#	https://makefiletutorial.com/
#	http://www.gnu.org/software/make/manual/make.html

CXX=g++
CPPFLAGS=--std=c++17

DEPS=list.hpp lib/catch.hpp
OBJ=main.o list.o tests.o

all: clean test

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

exercise4: $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS)

test: exercise4
	# executes all tests
	./exercise4

clean:
	rm -f exercise4
