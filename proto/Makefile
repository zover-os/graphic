source=$(wildcard src/*.cpp)

all: mkdist dist/rad

mkdist:
	rm -rf dist || true
	mkdir dist

dist/rad: $(source)
	g++ $(source) -I include -o dist/rad