CXXFLAGS = -std=c++11
PATH_INC = include

bin/main: build/main.o build/shape.o
	$(CXX) $(CXXFLAGS) -o $@ $^

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -I $(PATH_INC) -c $< -o $@

build/shape.o: src/shape.cpp
	$(CXX) $(CXXFLAGS) -I $(PATH_INC) -c $< -o $@

clean:
	$(RM) build/* bin/*
