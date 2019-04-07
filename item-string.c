#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"

Item inputItem(){
	
	char *p=malloc(sizeof(char) * 20);
	scanf("%s",p);
	return p;
}

void outputItem(Item item){
	char *p=item;
	printf("%s ", p);
}

int cmpItem(Item item1,Item item2){
	char *p1=item1,*p2=item2;
	
	return strcmp(p1, p2);
	
}