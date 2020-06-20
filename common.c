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
