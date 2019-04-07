#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "point.h"

int main() {
	List A = newList(), B;
	int n=5, i, pos, *search;
	Item s, rem;
	printf("Inserire la lista ");
	for (i=0; i<n; i++)
		addHead(A, inputItem());
	bubbleSortList(A);
	printList(A);
	printf("\n");
	B= cloneList(A);
	printList(B);
	printf("\n");
	/*scanf("%d", &pos);
	addListItem(A, inputItem(), pos);
	printList(A);
	printf("\n");
	/*printf("Nodo da rimuovere: ");
	scanf("%d", &pos);
	rem= removeListItemPos(A, pos);
	free(rem);
	bubbleSortList(A);
	printList(A);
	printf("\n");
	printf("Inserire l'elemento da eliminare: ");
	s= inputItem();
	rem= removeListItem(A, s);
	free(rem);
	bubbleSortList(A);
	printList(A);
	printf("\n");
	printf("Inserire l'elemento da cercare: ");
	s= inputItem();
	s= searchList(A, s, search);
	printf("Elemento trovato in posizione %d ", *search);
	printf("\n");*/
	return 0;	
}

/* 	List A = newList();
	int n=5, i, pos;
	Item s;
	printf("Inserire la lista ");
	for (i=0; i<n; i++)
		addHead(A, inputItem());

	printf("Inserire l'item da cercare: ");
	s=inputItem();
	searchList(A, s, &pos);
	printf("%d\n", pos); */
