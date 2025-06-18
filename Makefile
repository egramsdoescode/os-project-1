project1: main.c
	gcc -o project1 main.c

run: project1
	./project1

clean:
	rm -f project1
