#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */

struct QueueElement *createElement(){
 return (struct QueueElement*)malloc(sizeof(struct QueueElement));
}

QueuePtr new_queue(){
	struct QueueElement *head;
	head = createElement();
	head->next = NULL;
	head->prio = 100;
	head->data = NULL;
	return head;
}

void delete_queue(QueuePtr q){
	while(q->next != NULL){
		struct QueueElement *tmp;
		tmp = q;
		q = q->next;
		free(tmp);
	}
		free(q);
}

void clear(QueuePtr q){
 struct QueueElement *next = q->next;
 q->next = NULL;
 delete_queue(next);
}

int size(QueuePtr q){
	int i;
	for(i=1 ; q->next != NULL ; i++){
		q = q->next;
	}
	return i;
}

void add(QueuePtr q, int prio, DataPtr d){
	struct QueueElement *newElem;
	
	while(q->next != NULL){
		if((q->next)->prio >= prio){
			q = q->next;
			
		}else{
			q = q->next;
			newElem = createElement();
			newElem->prio = prio;
			newElem->data = d;
			newElem->next = (q->next)->next;
			q->next = newElem;
			break;
		}
	
	}
}
DataPtr get_first(QueuePtr q){ // avläser första dataelementet 
	return q->data;
}

void remove_first(QueuePtr q){ // tar bort första köelementet
	if(q->next != NULL){
		struct QueueElement *first;
		first = q->next;
		q->next = q->next->next;
		free(first);
	}
}
