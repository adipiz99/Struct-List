#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "point.h"

Item inputItem(){
	
	float x, y;
	scanf("%f %f", &x, &y);
	return createPoint(x, y);
}

void outputItem(Item item){
	Point p=item;
	printf("(%.1f, %.1f) ", ascissa(p), ordinata(p));
}

int cmpItem(Item item1,Item item2){
	Point p1=item1, p2=item2;
	Point origine = createPoint(0,0);
	float d1 = distanza(p1, origine);
	float d2 = distanza(p2, origine);

	free(origine);
	if(d1<d2)
		return -1;
	else if(d1 == d2)
		return 0;
	else
		return 1;
}
