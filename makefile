CXX = cc

build: 
	$(CXX) ./Chapter$(chapter)/$(chapter)-$(exercise).c ./Shared/*.c -o ./bin/$(chapter)-$(exercise).out
	./bin/$(chapter)-$(exercise).out