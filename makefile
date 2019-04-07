int: list.o utils.o item-int.o main.o
	gcc list.o utils.o item-int.o main.o -o list_int.exe
	
string: list.o utils.o item-string.o main.o
	gcc list.o utils.o item-string.o main.o -o list_str.exe
	
point: list.o utils.o item-point.o point.o main.o
	gcc utils.o list.o main.o item-point.o point.o -o list_point.exe -lm
	
list.o: 
	gcc -c list.c
	
utils.o:
	gcc -c utils.c
	
point.o:
	gcc -c point.c
	
main.o:
	gcc -c main.c
	
item-int.o:
	gcc -c item-int.c
	
item-string:
	gcc -c item-string.c

item-point:
	gcc -c item-point.c
	
clean:
	rm -f list.o utils.o point.o main.o item-int.o item-string.o item-point.o list_int.exe list_str.exe list_point.exe
	

