CXX = cc

build:
	$(CXX) ./Chapter$(chapter)/$(chapter)-$(lesson).c
	./a.out