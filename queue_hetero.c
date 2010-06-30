#include "queue_hetero.h"

void push_by_type(char *type, void *data, struct hetero_queue **base, struct hetero_queue **top){
        struct hetero_queue *temp = *base;
        struct hetero_queue *type_temp = NULL;
        int type_count = 0;
#ifdef __DEBUG__
        if(strcmp(type, "string")==0)
                printf("%s : The passed string is %s\n", __FUNCTION__, (char *)data);
#endif
        if(temp == NULL){
                temp = malloc(sizeof(struct hetero_queue));
                temp->type = type;
                temp->data = data;
                temp->next = NULL;
                *base = temp;
                *top = *base;
        }
        else{
                do{
                        if(strcmp(temp->type, type)==0){
                                type_temp = temp;
                                type_count++;
                        }
                         temp = temp->next;
                }while(temp != NULL);

                if(type_count==0){
                        /*
                         * in case we do not have any elements of the given type we will 
                         * just push on the top
                         */
                        type_temp = *top;
                }
                temp = malloc(sizeof(struct hetero_queue));
                temp->type = type;
                temp->data = data;
                temp->next = type_temp->next;
                type_temp->next=temp;
                if(type_temp == *top)
                        *top = temp;
        }
         
}       
void push(char *type, void *data, struct hetero_queue **base, struct hetero_queue **top){

	struct hetero_queue *temp = *top;
#ifdef __DEBUG__
        if(strcmp(type, "string")==0)
                printf("%s : The passed string is %s\n", __FUNCTION__, (char *)data);
#endif
        if(temp == NULL){
#ifdef __DEBUG__
                printf("%s : null\n",__FUNCTION__);
#endif
                temp = malloc(sizeof(struct hetero_queue));
        	temp -> type = type ;
	        temp -> data = data;
        	temp->next = NULL;
                *base = temp;
                *top = *base;
        }
        else{
#ifdef __DEBUG__
                printf("%s : not null\n",__FUNCTION__);
#endif
                temp->next = malloc(sizeof(struct hetero_queue));
                temp->next->type = type;
                temp->next->data = data;
                *top = temp->next;

        }                
}
struct hetero_queue * pop_by_type(char *type, struct hetero_queue **base){
	struct hetero_queue *temp = *base;
	struct hetero_queue *type_temp=NULL;
	struct hetero_queue *prev_temp = temp;
	struct hetero_queue *prev_type_temp = NULL;

	if (temp == NULL){
		printf("%s : You cannot pop an empty queue\n", __FUNCTION__);
		return NULL;
	}
	do{
		if(strcmp(temp->type, type)==0){
			prev_type_temp = prev_temp;
			type_temp = temp;
		}
		prev_temp = temp;
		temp = temp->next;
	}while(temp!=NULL);

	if(type_temp == NULL){
		printf("%s : The queue does not contain elements of type : %s\n",__FUNCTION__, type);
		return NULL;
	}
        if(type_temp == prev_type_temp){
                /*
                 * the case when the base element is the only element of specified type
                 */
                temp = *base;
                *base = type_temp->next;
                return temp;
        }
	/*
	 * now lets remove the queue element for all other cases
	 */
	prev_type_temp->next = type_temp->next;
	return type_temp;
}
struct hetero_queue *pop(struct hetero_queue **base){
        struct hetero_queue *temp = *base;
        struct hetero_queue *prev_temp = temp;
       while(temp->next != NULL){
               temp=temp->next;
       }
       if(temp == prev_temp){
               /*
                * when there is only one element in the queue
                */
               temp = *base;
               *base = NULL;
               return temp;
       }
       prev_temp->next = temp->next;
       return temp;
}
int print_by_type(char *type, struct hetero_queue *base){
        struct hetero_queue *temp = base;
        int print_count=0, queue_count=0;
        printf("________________________________________________\n");
        if(temp == NULL){
                printf("%s : The queue is empty\n", __FUNCTION__);
                printf("________________________________________________\n");
                return -1;
        }
        do{
                queue_count++;
                if(strcmp(temp->type, type)==0){
                        if(strcmp(type,"int")==0)
                                printf("<%3d> <%6s> %d \n",queue_count, temp->type, *(int *)(temp->data));
                        else if (strcmp(type, "string")==0)
                                printf("<%3d> <%6s> %s \n",queue_count, temp->type, (char *)temp->data);
                        else if (strcmp(type, "double")==0)
                                printf("<%3d> <%6s> %lf \n",queue_count, temp->type, *(double *)(temp->data));
                        else 
                                printf("<%3d> <%6s> %s \n",queue_count, temp->type, (char *)(temp->data));
                        print_count++;
                }
                temp=temp->next;
        }while(temp != NULL);

        if (print_count == 0){
                printf("%s : The queue does not conatin elements of type : %s\n",__FUNCTION__, type);
                printf("________________________________________________\n");
                return 0;
        }
        else{
                printf("________________________________________________\n");
                return print_count;
        }
}
int print(struct hetero_queue *base){
        struct hetero_queue *temp = base;
        int queue_count=0;
        printf("________________________________________________\n");
        if(temp == NULL){
                printf("%s : The queue is empty\n", __FUNCTION__);
                printf("________________________________________________\n");
                return -1;
        }
        do{
                queue_count++;
                        if(strcmp(temp->type,"int")==0)
                                printf("<%3d> <%6s> %d \n",queue_count, temp->type, *(int *)temp->data);
                        else if (strcmp(temp->type, "string")==0)
                                printf("<%3d> <%6s> %s \n",queue_count, temp->type, (char *)temp->data);
                        else if (strcmp(temp->type, "double")==0)
                                printf("<%3d> <%6s> %lf \n",queue_count, temp->type, *(double *)temp->data);
                temp=temp->next;
        }while(temp != NULL);
        printf("________________________________________________\n");
        return queue_count;
}
int count_by_type(char *type, struct hetero_queue *base){
        struct hetero_queue *temp = base;
        int print_count=0, queue_count=0;
        if(temp == NULL){
                printf("%s : The queue is empty\n", __FUNCTION__);
                return -1;
        }
        do{
                queue_count++;
                if(strcmp(temp->type, type)==0){
                        print_count++;
                }
                temp=temp->next;
        }while(temp != NULL);

        if (print_count == 0){
                printf("%s : The queue does not conatin elements of type : %s\n",__FUNCTION__, type);
                return 0;
        }
        else
                return print_count;
}
int count(struct hetero_queue *base){
        struct hetero_queue *temp = base;
        int queue_count=0;
        if(temp == NULL){
                printf("%s : The queue is empty\n", __FUNCTION__);
                return -1;
        }
        do{
                queue_count++;
                temp=temp->next;
        }while(temp != NULL);

        return queue_count;
}
