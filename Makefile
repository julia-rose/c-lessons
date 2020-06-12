strings: strings.c
	gcc -o strings strings.c

linkedlist: linkedlist.c
	gcc -o linkedlist linkedlist.c

.PHONY: clean run
clean:
	rm strings

run: linkedlist
	./linkedlist
