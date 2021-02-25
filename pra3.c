#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=0;a<=4;a++){
		for(b=0;b<=3-a;b++)
			printf(" ");
		for(c=0;c<=2*a;c++)
			printf("#");
		printf("\n");
	}
	for(a=0;a<=4;a++){
		for(b=0;b<=a;b++)
			printf(" ");
		for(c=0;c<=6-2*a;c++)
			printf("#");
		printf("\n");
	}
	printf("\n");
	return 0;
}
