#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
  Node* node = (Node*) malloc(sizeof(Node));
  if(!node) return false;
  node -> item = item;
  node -> next = s -> top;
  s -> top = node;
  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  if(stack_empty(s)) return false;
  output -> value = s -> top -> item.value;
  output -> type = s -> top -> item.type;
  Node* prev = s -> top;
  s -> top = s -> top -> next;
  free(prev);
  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
  return (!(s->top));
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  while(!stack_empty(*s)){
    Node* prev = (*s) -> top;
    (*s) -> top = (*s) -> top -> next;
    free(prev);
  }
  free(*s);
  *s = NULL;
  s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here
  CalculatorItem val1 = {NUMBER, 0};
  CalculatorItem val2 = {NUMBER, 0};

  if(item.type == NUMBER){
    stack_push(s,item);
    return true;
  }
  else{
    if(!stack_pop(s,&val2)) return false; //if stack is empty then returns false
    if(!stack_pop(s,&val1)) return false;
    if(val1.type != NUMBER || val2.type != NUMBER) return false;
  }
  CalculatorItem res = {NUMBER, 0};
  switch(item.type){
    case ADD:;
      res.value = val1.value + val2.value;
      stack_push(s,res);
      break;
    case SUBTRACT:;
      res.value = val1.value - val2.value;
      stack_push(s,res);
      break;
    case MULTIPLY:;
      res.value = val1.value * val2.value;
      stack_push(s,res);
      break;
    default:;
      if(val2.value == 0) return false;
      res.value = (val1.value) / (val2.value);
      stack_push(s,res);
      break;
  }
  if(stack_empty(s)) stack_delete(&s);
  return true;
}
