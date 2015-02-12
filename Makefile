CC=g++
CFLAGS=-std=c++11

CPP_FILES=Cache.cpp Set.cpp StructReader.cpp fully_cache_example.cpp
H_FILES=Cache.h Set.h StructReader.h tracestruct.h

all: txt2struct.out fully_cache_example.out

fully_cache_example.out: $(CPP_FILES) $(H_FILES)
	$(CC) $(CFLAGS) -I. $(CPP_FILES) -o $@

txt2struct.out: txt2struct.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f fully_cache_example.out txt2struct.out
