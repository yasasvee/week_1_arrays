#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void read(int *input,int size)
{
	printf("Enter your elements\n");
	while(size+1)
	{
		scanf("%d",input);
		++input;
		--size;
	}
}
void sort(int *input,int size)
{
	int loop1=0,loop2=0,swap;
	for (loop1=0;loop1<size;loop1++)
	{
		for(loop2=0;loop2<size-loop1;loop2++)
		{
			if (input[loop2]<input[loop2+1])
			{
				swap= input[loop2];
				input[loop2]=input[loop2+1];
				input[loop2+1]=swap;
			}
		}
	}
 }
void display(int *input,int size)
{
	printf("the sorted elements are\n");
	while(size+1)
	{
		printf("%d\t",*input);
		++input;
		--size;
	}
}
int main(void)
{
  int *elements,index;
  printf("Enter the total number of elements\n");
  scanf("%d", &index);
  --index;
  elements=(int*)malloc(sizeof(int)*index); 
  read(elements,index);
  sort(elements,index);
  display(elements,index);
  getch();
  return 0;
}
