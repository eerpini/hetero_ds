#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct hetero_queue{
	char *type;
	void *data;
	struct hetero_queue *next;
};

void push_by_type(char *, void *, struct hetero_queue **, struct hetero_queue **);
void push(char *, void *, struct hetero_queue **, struct hetero_queue **);
struct hetero_queue * pop_by_type(char *, struct hetero_queue **);
struct hetero_queue * pop(struct hetero_queue **);
int print_by_type(char *, struct hetero_queue *);
int print(struct hetero_queue *);
int count_by_type(char *, struct hetero_queue *);
int count(struct hetero_queue *);
