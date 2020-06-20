strings: strings.c
	gcc -o strings strings.c

linkedlist: linkedlist.c
	gcc -g -o linkedlist linkedlist.c

.PHONY: clean run
clean:
	rm strings linkedlist

run: linkedlist
	./linkedlist
