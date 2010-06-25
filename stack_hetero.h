#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct hetero_stack{
	char *type;
	void *data;
	struct hetero_stack *next;
};

void push_by_type(char *, void *, struct hetero_stack **, struct hetero_stack **);
void push(char *, void *, struct hetero_stack **, struct hetero_stack **);
struct hetero_stack * pop_by_type(char *, struct hetero_stack **);
struct hetero_stack * pop(struct hetero_stack **);
int print_by_type(char *, struct hetero_stack *);
int print(struct hetero_stack *);
int count_by_type(char *, struct hetero_stack *);
int count(struct hetero_stack *);
