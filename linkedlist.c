#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

static int bytes_allocated = 0;
static int bytes_freed = 0;

void* checked_malloc(size_t bytes) {
  bytes_allocated += bytes;
  return malloc(bytes);
}

void checked_free(void* ptr) {
  bytes_freed += malloc_size(ptr);
  free(ptr);
}

void check_memory(int reset) {
  if(bytes_allocated != bytes_freed) {
    printf("\033[0;31m"); // RED
    printf("MEMORY LEAK: %d bytes allocated, %d bytes freed\n", bytes_allocated, bytes_freed);
    printf("\033[0m"); 
  } else {
    printf("\033[0;32m"); // GREEN
    printf("no memory leak :)\n");
    printf("\033[0m"); 
  }
  if(reset) {
    bytes_allocated = 0;
    bytes_freed = 0;
  }
}

void banner(const char *str) {
  printf("\033[1;35m"); // bold magenta
  printf("\n\n%s\n", str);
  printf("\033[0m"); 
}



typedef struct Node {
  int value;
  struct Node* next;
} Node;


Node* new_node(int value) {
  Node* new = checked_malloc(sizeof(Node));
  new->value = value;
  new->next = NULL;
  return new;
}


void append(Node* head, int value) {
  Node* new = new_node(value);
  while (head->next) {
    head = head->next;
  }
  head->next = new;
}

Node* insert(Node* head, int value) {
}

void print_list(Node* head) {
  while (head) {
    printf("%d\n", head->value);
    head = head->next;
  }
}

void free_list(Node* head) {
  Node* nextUp = head->next;
  while (nextUp) {
    checked_free(head);
    head = nextUp;
    nextUp = head->next;
  }
  checked_free(head);
}

Node* reverse(Node* head) {
}

void demo_print() {
  banner("Demo Print");
  Node c = { 1, NULL };
  Node b = { 2, &c };
  Node a = { 3, &b };
  print_list(&a);
}

void demo_append() {
  banner("Demo Append");
  Node *head = new_node(1);
  append(head, 2);
  append(head, 3);
  append(head, 4);
  append(head, 5);
  append(head, 6);
  print_list(head);
  free_list(head);
  check_memory(TRUE);
}

void demo_insert_part1() {
  banner("Demo Insert (Part 1)");
  Node *head = new_node(5);

  // create first node
  insert(head, 1);
  insert(head, 3);
  insert(head, 4);
  insert(head, 2);
  insert(head, 6);
  print_list(head);
  free_list(head);
  check_memory(TRUE);
}

void demo_insert_part2() {
  banner("Demo Insert (Part 2)");
  Node *head = new_node(1);

  // create first node
  head = insert(head, 5);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 2);
  head = insert(head, 6);
  print_list(head);
  free_list(head);
  check_memory(TRUE);
}


void demo_reverse() {
  banner("Demo Reverse");
  Node *head = new_node(5);
  head = insert(head, 1);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 2);
  head = insert(head, 6);
  Node* reversed = reverse(head);
  print_list(reversed);
  free_list(reversed);
  check_memory(TRUE);
}


int main() {
  demo_print();
  demo_append();
  // demo_insert_part1();
  // demo_insert_part2();
  // demo_reverse();
}
