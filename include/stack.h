#ifndef STACK_H
#define STACK_H
#include "common.h"

/*======= Stack  =======*/
void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);
int peek(Stack* S);
int isEmpty(Stack* S);


#endif