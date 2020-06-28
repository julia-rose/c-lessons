#include <stdio.h>
#include <stdlib.h>
#include "common.h"

typedef struct Order {
  char* name;
  int numPizzas;
} Order;

typedef struct OrderNode {
  Order order;
  struct OrderNode* next;
} OrderNode;

typedef struct Queue {
  OrderNode *head;
  OrderNode *tail;
  int length;
}

typedef struct Stack {
  OrderNode *head;
  int length;
}

int length(OrderNode* head) {
  /* return the length of the stack or queue */
  int counter = 0;
  while (head) {
    counter++;
    head = head->next;
  }
  return counter;
}

void cleanup(OrderNode* head) {
  /* free all memory associated with the stack or queue */
  OrderNode* nextUp;
  while (head) {
    nextUp = head->next;
    checked_free(head);
    head = nextUp;
  }
}

/* 
 * Queue: FIFO
 *
 *  we add to the end of the queue
 *  we remove from the front
 *
 *  OPPOSITE SIDES ... but we want it O(1)
 */
void queue_add(OrderNode** head, Order* newOrder) {
  /* add newOrder to the list, will be last to be processed
   * head ptr is changed in place as needed
   * newOrder is *GUARANTEED* to be not null
   */
  OrderNode* new = checked_malloc(sizeof(OrderNode));
  new->order = *newOrder;
  new->next = NULL;
  OrderNode* cur = *head;

  if (!(*head)) {
    *head = new;
  } else {
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = new;
  }
}


/* Stack: LIFO
 *
 * we add to the top of the stack
 * we remove from the top 
 *
 * we want it O(1)
 */
void stack_add(OrderNode** head, Order* newOrder) {
  /* add newOrder to stack in position that will be next to be popped off
   * head ptr is changed in place as needed
   * newOrder is *GUARANTEED* to be not null
   * */
  OrderNode* new = checked_malloc(sizeof(OrderNode));
  new->order = *newOrder;
  new->next = *head;
  *head = new;
}

void pop(OrderNode** head, Order* poppedVal) {
  /* remove most recently added order from list
   * head ptr is changed in place as needed
   * poppedVal is *GUARANTEED* to be not null, and will be populated with removed value
   */
  *poppedVal = (*head)->order;
  OrderNode* temp = (*head)->next;
  checked_free(*head); 
  *head = temp;
}

int main() {
  Order one = { "James", 4 };
  Order two = { "Julia", 3 };
  Order three = { "Shiva", 200 };
  Order four = { "Dumbboy X", 0 };
  int totalPizzas = 203;

  OrderNode *list = NULL;

  printf("Welcome to the bad pizza place\n");
  queue_add(&list, &one);
  queue_add(&list, &two);
  queue_add(&list, &three);
  queue_add(&list, &four);
  printf("Looks like we have %d orders to make boys!\n", length(list));

  while(list) {
    Order nextOrder;
    pop(&list, &nextOrder);
    if(nextOrder.numPizzas > totalPizzas) {
      printf("We are out of pizza!\n");
      break;
    }
    printf("Now serving: %s -- %d pizzas coming up!\n", nextOrder.name, nextOrder.numPizzas);
    totalPizzas -= nextOrder.numPizzas;
  }
  cleanup(list);
  check_memory(1);
}
