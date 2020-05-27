cc = g++
prom = main
deps = $(shell find . -name "*.h")
src = $(shell find . -name "*.cpp")
obj = $(src:%.cpp=%.o) 
 
$(prom): $(obj)
	g++ -g -o $(prom) $(obj)
 
%.o: %.cpp $(deps)
	g++ -g -c $< -o $@
 
clean:
	rm -rf $(obj) $(prom) $(shell find . -name "*.dSYM")