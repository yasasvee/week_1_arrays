#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void read(int *arrayn,int size)
{
	if(size+1)
	{
		scanf("%d",arrayn);
		read(++arrayn,--size);
	}
	else return;
}
void compute(int *input1,int *input2,int *output,int size)

{
	if(size+1)
	{
		*(output)=*(input1)+*(input2);
		 compute(++input1,++input2,++output,--size);
	}
	else return;
}
void display(int *output,int size)
{
	printf("The resultant Array of integers is\n");
	while(size>=0)
	{
		printf("%d\t",*output);
		output++;
		size--;
	}
}
	
int main(void)
{
	int *array1,*array2,*output,index;
	printf("Enter the number of elements\n");
	scanf("%d",&index);
	--index;
	array1=(int*)malloc(sizeof(int)*index);
	array2=(int*)malloc(sizeof(int)*index);
	output=(int*)malloc(sizeof(int)*index);
	printf("enter your array elements\n");
    read(array1,index);
	printf("enter your array elements\n");
	read(array2,index);
	compute(array1,array2,output,index);
    display(output,index);
	getch();
	return 0;
}

