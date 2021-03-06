#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*sort of like a class in java. creates a structure for stacks of doubles*/
struct double_stack{
  int top, size;
  double *items;
}; /*end of structure*/

/*create new empty double_stack called result i think*/
struct double_stack *double_stack_new(){
  const int max_size = 10;
  struct double_stack *result;
  result = malloc(sizeof(struct double_stack)); /*allocated the memory required for a stack of the size 10*/
  result->top = 0; /*changes the position of the stack to 0*/
  result->size = max_size; /*sets the size of the double_stack*/
  result->items = malloc(sizeof(double) * max_size); /*allocates the memory required for a stack of DOUBLES of th specified size*/
};

/*free double double_stack IMPORTANT*/
void double_stack_free(struct double_stack *this){
  free(this-> items); /*frees the memory used by the items in the stack*/
  free(this); /*frees the address of the stack*/
}

/*push item onto double stack*/
void double_stack_push(struct double_stack *this, double item){
  assert(this->top < this->size); /*checks that it wont try putting an item over the limit of a stack*/
  this -> items[this->top] = item; /*pushes the item to the stack*/
  this -> top++; /*changes the "top" of the stack to the next position*/
}

//pop item from stack
double double_stack_pop(struct double_stack * this) {
  assert(this -> top > 0);
  this -> top--;
  return this -> items[this -> top];
}

/*pushes items on to stack, then pops them off, printing the output and then frees the stack*/
int main(){
  struct double_stack *result = double_stack_new(); /*creates new stack of size 10 called result*/
  for(int i = 0; i < result->size; i++){ /*pushes numbers 1-10 onto the stack*/
    double_stack_push(result, i+1);
  }
  for(int i = 0; i < result->size; i++){ /*pops off the doubles from the stack and prints them without a decimal*/
    printf("%.0lf\n", double_stack_pop(result));
  }
  double_stack_free(result);
  return 0;
}
