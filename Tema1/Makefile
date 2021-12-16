CC = g++
CFLAGS = -g


# nume necesar (build)
build: crypto stocks valley ridge trigigel

crypto: crypto.cpp
	$(CC) $(CFLAGS) $^ -o $@

stocks: stocks.cpp
	$(CC) $(CFLAGS) $^ -o $@

valley: valley.cpp
	$(CC) $(CFLAGS) $^ -o $@

ridge: ridge.cpp
	$(CC) $(CFLAGS) $^ -o $@

trigigel: trigigel.cpp
	$(CC) $(CFLAGS) $^ -o $@

run-p1:      
	./crypto

run-p2:      
	./stocks

run-p3:      
	./valley

run-p4:      
	./ridge

run-p5:
	./trigigel

clean:		 
	rm crypto stocks valley ridge trigigel
