CXX = cc

build: 
	$(CXX) ./Chapter$(chapter)/$(chapter)-$(lesson).c ./Shared/*.c -o ./bin/$(chapter)-$(lesson).out
	./bin/$(chapter)-$(lesson).out