CC = gcc
FLAGS = -Wall -g

all: app1 app2 app3 app4

app1: app1.o
	$(CC) $(FLAGS) app1.o -o app1

app2: app2.o
	$(CC) $(FLAGS) app2.o -o app2

app3: app3.o
	$(CC) $(FLAGS) app3.o -o app3
	
app4: app4.o app1 app2 app3
	$(CC) $(FLAGS) app4.o -o app4

app1.o: app1.c
	$(CC) $(FLAGS) -c app1.c

app2.o: app2.c
	$(CC) $(FLAGS) -c app2.c

app3.o: app3.c
	$(CC) $(FLAGS) -c app3.c

app4.o: app4.c app1.o app2.o app3.o
	$(CC) $(FLAGS) -c app4.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so app1 app2 app3 app4
