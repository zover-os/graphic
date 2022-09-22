objects=$(patsubst %.cpp,%.o,$(wildcard src/*.cpp))

all: dist/rad

dist:
	mkdir dist

%.o: %.cpp
	g++ -c $< -I include -o $@

dist/rad: dist $(objects)
	g++ $(objects) -o dist/rad