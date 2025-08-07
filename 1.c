#include <stdio.h> 
#include <stdlib.h> 

void swapChar()
{
	char a, b; 
	printf("\na, b: ");
	scanf("%c%c", &a, &b);
	
	printf("\na: %c\nb: %c\n", a, b);
	
	char temp = a; 
	a = b; 
	b = temp; 
	
	
	printf("After swap: \na: %d\nb: %d", a, b);
	
}

void swapInt()
{
	int x, y; 
	printf("\nx, y: ");
	scanf("%d%d", &x, &y);
	printf("x: %d\ny: %d\n", x, y);
	
	x = (x + y) - (y = x); 
	printf("After swap: \nx: %d\ny: %d", x, y);
}

void swap(int *x, int *y){
	int temp = *x; 
	*x = *y;
	*y = temp; 
}

void swapWithPointer(){
	int x, y; 
	printf("\nx, y: ");
	scanf("%d%d", &x, &y);
	printf("x: %d\ny: %d\n", x, y);
	
	swap(&x, &y);
	printf("After swap: \nx: %d\ny: %d", x, y);
}

int main(){
	while(1){
	
		printf("Choose one:\n1. Swap Two numbers \n2. Swap two chars \n3. Swap using pointer.");
		int c; 
		scanf("%d", &c);
		printf("\n");
		switch(c)
		{
			case 1:
			swapInt(); 
			break; 
			case 2: 
			swapChar();
			break; 
			case 3: 
			swapWithPointer();
			break; 
			default:
			printf("Wrong choice");
			break; 
		}
		printf("\n\n");
	}
	
}
