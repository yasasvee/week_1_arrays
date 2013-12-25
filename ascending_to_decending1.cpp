#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void read(int *input,int size)
{
	printf("Enter Your elements in Ascending order\n");
	while(size+1)
	{
		scanf("%d",input);
		input++;
		size--;
	}
}
void sort(int *sorted,int size)
{
	int temp,pos=0;
	while(pos<size)
	{
		temp=*(sorted+pos);
		*(sorted+pos)=*(sorted+size);
		*(sorted+size)=temp;
		--size;
		++pos;
	}
}
void display(int *output,int size)
{
	printf("Sorted elements are\n");
	while(size+1)
	{
		printf("%d\t",*output);
		output++;
		size--;
	}
}
int main(void)
{
	int *elements,index;
	printf("enter the number of elements in the array\n");
	scanf("%d",&index);
	--index;
	elements=(int*)malloc(sizeof(int)*index);
	read(elements,index);
	sort(elements,index);
	display(elements,index);
	getch();
	return 0;
}
