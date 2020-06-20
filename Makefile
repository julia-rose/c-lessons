strings: strings.c
	gcc -o strings strings.c

linkedlist: linkedlist.c
	gcc -g -o linkedlist linkedlist.c

stack_queue: stack_queue.c common.c
	gcc -o stack_queue stack_queue.c common.c

.PHONY: clean run
clean:
	rm strings linkedlist

run: linkedlist
	./linkedlist
