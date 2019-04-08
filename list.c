#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "utils.h"



struct list {
	int size;
	struct node *head;
};

struct node {
	Item item;
	struct node *next;
};

struct node *minimo (struct node *p);

List newList(){
	
	List list = malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	
	return list;
}

int isEmpty(List list){
	return list->head == NULL;
}

void addHead(List list, Item item){
	struct node *x = malloc(sizeof(struct node));
	x->next = list->head;
	x->item = item;
	list->head = x;
	list->size++;
}

Item removeHead(List list){
	Item app;
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}	
	struct node *temp = list->head;
	list->head = temp->next;
	app=temp->item;
	free(temp);
	list->size--;
	return app;
}

Item getHead(List list){
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
		
	return list->head->item;
}

int sizeList(List list){
	return list->size;
}

void printList(List list){
	struct node *p;
	for(p = list->head; p != NULL; p = p->next)
		outputItem(p->item);
} 

void bubbleSortList(List list){ 
	struct node *p,*s;
	int size= list->size-1, count;
	
	for(p=list->head->next;p!=NULL;p=p->next, size--){
		count= size;
		for(s= list->head;count != 0; count--, s= s->next){
			if(cmpItem(s->item, s->next->item)>0){
				swap(&(s->item),&(s->next->item));
			}
		}	
	}
		
}

void selectionSortList(List list){
	struct node *p, *pos_minimo;
	for (p=list->head; p != NULL; p = p-> next){
		pos_minimo = minimo(p);
		swap(&(pos_minimo->item), &(p->item));
	}
}

struct node * minimo (struct node *p){
	struct node *i, *min = p;
	for (i = p->next; i != NULL; i = i->next){
		if ((cmpItem(min->item, i->item)) > 0)
			min = i;
	}
	return min;
}


Item searchList(List list, Item item, int *pos){
	struct node *p;
	*pos=0;
    for (p=list->head; p != NULL; p = p-> next){
		if(cmpItem(item,p->item) == 0)
			return p->item;
		++*pos;
	}
	*pos=-1;
	return NULL;
}


Item removeListItem(List list, Item item){
	struct node *p, *s;
	Item i;
	
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
		
	for(p= list->head, s= p; p != NULL; p= p->next){
		if(p == list->head)
			return removeHead(list);
		if(cmpItem(item, p->item) == 0){
			i= p->item;
			s->next=p->next;
			list->size--;
			free(p);
			return i;
		}
		s= p;
	}
	return NULL;
}

Item removeListItemPos(List list, int pos){
	struct node *p, *s;
	int j=1;
	Item i;
	
	if(isEmpty(list)==1){
		fprintf(stderr,"Lista vuota");
		return NULL;
	}
		
	for(p= list->head, s= p; p != NULL; p= p->next, j++){
		if(j == pos){
			if(j == 1)
				return removeHead(list);
			i= p->item;
			s->next=p->next;
			list->size--;
			free(p);
			return i;
		}
		s= p;
	}
	return NULL;	
}

int addListItem(List list, Item item, int i){
	struct node *p, *n;
	int pos=0;
	if(i > list->size|| i < 0){
		fprintf(stderr, "Posizione errata\n");
		return 0;
	}
	else if(i == 0){
		addHead(list, item);
		return 1;
	}
	
	for(p=list->head; p != NULL; p=p->next, pos++)
		if(pos == i-1){
			n= malloc(sizeof(struct node));
			n->item= item;
			n->next= p->next;
			p->next= n;
			list->size++;
			return 1;
		}
}

void addListTail(List list, Item item){
	struct node *p;
	
	for(p= list->head; p->next != NULL; p= p->next);
	
	p->next= malloc(sizeof(struct node));
	p->next->item= item;
	p->next->next= NULL;
	list->size++;
}

void reverseList(List list){
	struct node *p, *temp, *prev;
	
	prev=list->head;
	p= prev->next;
	
	for(prev->next=NULL; p != NULL; p= temp){
		if(p->next == NULL)
			temp= NULL;
		else
			temp= p->next;
		p->next=prev;
		prev= p;
	}
	list->head= prev;
}
		
List cloneList(List list){
	if(isEmpty(list)){
		fprintf(stderr,"Lista vuota\n");
		return NULL;
	}
	
	List clone= newList();
	struct node *source, *target;
	
	clone->head= malloc(sizeof(struct node));
	target= clone->head;
	
	for(source= list->head; source != NULL; source= source->next, target= target->next){
		target->item = cloneItem(source->item);
		if (source->next == NULL)
			target->next= NULL;
		else
			target->next= malloc(sizeof(struct node));
	}
	
	return clone;
}	
		
		
	
	
		


