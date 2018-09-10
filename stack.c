#include <stdio.h>

#define MAX_LEN 1000
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef enum boolean { false, true }bool;

typedef struct stack {
	char s[MAX_LEN];
	int top;
}stack;

void reset(stack *stk) {
	stk->top = EMPTY;
}

void push(char c, stack *stk) {
	stk->top++;
	stk->s[stk->top] = c;
}

char pop(stack *stk) {
	return (stk->s[stk->top--]);
}

char top(const stack *stk) {
	return (stk->s[stk->top]);
}

bool empty(const stack *stk) {
	return ((bool)(stk->top == EMPTY));
}

bool full(const stack *stk) {
	return ((bool)(stk->top == FULL));
}

int main(void) {
	char str[] = "All the stars are closer";
	int i;
	stack s;
	reset(&s); /* initialize the stack */
	printf("In the string: %s\n", str);
	for(i = 0; str[i] != '\0'; i++)
		if(!full(&s))
			push(str[i], &s);
	printf("From the stack: ");
	while(!empty(&s))
		putchar(pop(&s));
	putchar('\n');				
	return 0;
}