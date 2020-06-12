strings: strings.c
	gcc -o strings strings.c

.PHONY: clean run
clean:
	rm strings

run: strings
	./strings