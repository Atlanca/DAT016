#include "queue.h"
#include <stdlib.h>

/* Implementera interface från queue.h här */

QueuePtr new_queue(){
	struct QueueElement *head;
	head = createElement();
	head->next = NULL;
	head->prio = 100;
	head->data = NULL;
	return head;
}
void deleteQueue(QueuePtr q){
	while(q->next != NULL{
		struct QueueElement *tmp;
		tmp = q;
		q = q->next;
		free(tmp);
	}
		free(q);
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
		if((q->next)->prio >= prio)){
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