/*
rcs.h
(make this look nicer)
Relative coordinate system
*/

#ifndef RCS_H
#define RCS_H

#include"matrix.h"

struct Rcs_stack {
	struct Matrix **stack;	//array of Matrix struct pointers
	int top;		//top index
	int capacity;		//max index
};

//init with size + 1, bottom is used for identity matrix
struct Rcs_stack* new_rcs_stack(int size);

void print_stack(struct Rcs_stack *s);

void free_stack(struct Rcs_stack *s);

//doubles the stack size
void resize_stack(struct Rcs_stack *s);

//gets top (working) coordinate system
struct Matrix *peek();

//pushes a copy of the current top coordinate system
void push_rcs();

//pop off the top coordinate system
//will not do anything if at the bottom identity matrix
void pop_rcs();

#endif

