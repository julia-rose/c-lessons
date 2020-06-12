#include <stdio.h>

unsigned int strlen(const char * str) {
  unsigned int counter = 0;
  while (str[counter] != 0) {
    counter++;
  }
  return counter;
}

char* strcpy1(char * destination, const char * source) {
  for (int i = 0; i < strlen(source); i++) {
    destination[i] = source[i];
  }
  return destination;
}

char* strcpy2(char * destination, const char * source) {
  unsigned int i = 0;
  while(source[i] != 0) {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
  return destination;
}

char* strcpy(char * destination, const char * source) {
  while(*source != 0) {
    *destination++ = *source++;
  }
  *destination = '\0';
  return destination;
}

int main() {
  const char *mystr = "something";
  char newstr[100];

  strcpy(newstr, mystr);


  printf("%s is the same as %s\n", mystr, newstr);
  printf("%d is the length of %s\n", strlen(mystr), mystr);
}