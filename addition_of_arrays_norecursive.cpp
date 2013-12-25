#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void read(int *arrayn,int size)
{
	printf("enter your array elements\n");
	while((size+1))
	{
		scanf("%d",arrayn);
		arrayn++;
		size--;
	}
}
void compute(int *input1,int *input2,int *output,int size)

{
	int pos=0;
	while(pos<=size)
	{
		*(output+pos)=*(input1+pos)+*(input2+pos);
		 pos++;
	}
}
void display(int *output,int size)
{
	printf("the resultant array is\n");
	while(size>=0)
	{
		printf("%d\n",*output);
		output++;
		size--;
	}
}
	
int main(void)
{
	int *array1,*array2,*output,index;
	printf("Enter the array size\n");
	scanf("%d",&index);
	index--;
	array1=(int*)malloc(sizeof(int)*index);
	array2=(int*)malloc(sizeof(int)*index);
	output=(int*)malloc(sizeof(int)*index);
	read(array1,index);
	read(array2,index);
	compute(array1,array2,output,index);
	display(output,index);
	getch();
	return 0;
}

