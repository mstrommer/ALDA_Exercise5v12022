# if you want to dive into makefiles have a look at:
#	https://makefiletutorial.com/
#	http://www.gnu.org/software/make/manual/make.html

CXX=g++
CPPFLAGS=--std=c++17

DEPS=list.hpp hashtable.hpp lib/catch.hpp
OBJ=main.o list.o hashtable.o tests.o

all: clean test

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

exercise5: $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS)

test: exercise5
	# executes all tests
	./exercise5

clean:
	rm -f exercise5
