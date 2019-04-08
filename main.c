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
	return 0;	
}

