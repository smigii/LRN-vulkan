CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

PROG = bin/voolkan

$(PROG): main.cpp
	g++ $(CFLAGS) -o $(PROG) main.cpp $(LDFLAGS)

.PHONY: test clean

test: $(PROG)
	./$(PROG)

clean:
	rm -f VulkanTest
