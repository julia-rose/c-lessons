typedef struct Order {
  char* name;
  int numPizzas;
} Order;

typedef struct OrderNode {
  Order order;
  struct OrderNode* next;
} OrderNode;


int length(OrderNode* head) {
  /* return the length of the stack or queue */
}

void cleanup(OrderNode* head) {
  /* free all memory associated with the stack or queue */
}

/* 
 * Queue: FIFO
 *
 *  we add to the end of the queue
 *  we remove from the front
 *
 *  OPPOSITE SIDES ... but we want it O(1)
 */
void queue_add(OrderNode* head, OrderNode *newOrder) {
  /* add newOrder to the list, will be last to be processed
   * head ptr is changed in place as needed
   * newOrder is *GUARANTEED* to be not null
   */
}

void queue_pop(OrderNode** head, OrderNode *poppedVal) {
  /* remove oldest order from list
   * head ptr is changed in place as needed
   * poppedVal is *GUARANTEED* to be not null, and will be populated with removed value
   */
}


/* Stack: LIFO
 *
 * we add to the top of the stack
 * we remove from the top 
 *
 * we want it O(1)
 */
void stack_add(OrderNode** head, OrderNode *newOrder) {
  /* add newOrder to stack in position that will be next to be popped off
   *  head ptr is changed in place as needed
   * newOrder is *GUARANTEED* to be not null
   * */
}

void stack_pop(OrderNode** head, OrderNode *poppedVal) {
  /* remove most recently added order from list
   * head ptr is changed in place as needed
   * poppedVal is *GUARANTEED* to be not null, and will be populated with removed value
   */
}
