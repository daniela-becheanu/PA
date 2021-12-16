CC = g++
CFLAGS = -g


# nume necesar (build)
build: poduri adrese lego

poduri: poduri.cpp
	$(CC) $(CFLAGS) $^ -o $@

adrese: adrese.cpp
	$(CC) $(CFLAGS) $^ -o $@

lego: lego.cpp
	$(CC) $(CFLAGS) $^ -o $@

# ridge: ridge.cpp
# 	$(CC) $(CFLAGS) $^ -o $@

# trigigel: trigigel.cpp
# 	$(CC) $(CFLAGS) $^ -o $@

run-p1:      
	./poduri

run-p2:      
	./adrese

run-p3:      
	./lego

# run-p4:      
# 	./ridge

# run-p5:
# 	./trigigel

clean:		 
	rm poduri adrese lego
