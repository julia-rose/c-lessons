#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

static int times_allocated = 0;
static int times_freed = 0;

void* checked_malloc(size_t bytes) {
  times_allocated += 1;
  return malloc(bytes);
}

void checked_free(void* ptr) {
  times_freed += 1;
  free(ptr);
}

void check_memory(int reset) {
  if(times_allocated != times_freed) {
    printf("\033[0;31m"); // RED
    printf("MEMORY LEAK: %d allocated, %d freed\n", times_allocated, times_freed);
    printf("\033[0m"); 
  } else {
    printf("\033[0;32m"); // GREEN
    printf("no memory leak :)\n");
    printf("\033[0m"); 
  }
  if(reset) {
    times_allocated = 0;
    times_freed = 0;
  }
}

void banner(const char *str) {
  printf("\033[1;35m"); // bold magenta
  printf("\n\n%s\n", str);
  printf("\033[0m"); 
}
