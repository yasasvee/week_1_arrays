#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void sort(int*,int);
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
void split(int *first,int *last)
{
	int count=0,swap=0;
	while((first+count)!=last)
	{
		count++;
	}
	if(count==1 && (*first)>*(first+1))
	{
		swap=*first;
		*first=*(first+1);
		*(first+1)=swap;
	}
	if(count>1)
		sort(first,count);
}

void sort(int *input,int size)
{
 	int *pivot,*greatest,*smallest,swap=0;
	pivot=input;
	greatest=input+1;
	smallest=input+size;
	if(greatest<smallest)
	{
	while(greatest<smallest)
	{
		while(greatest<(input+size))
		{
			if(*greatest>=*pivot)
				break;
			else
				++greatest;
		}
		while(smallest>pivot )
		{
			if(*smallest<*pivot)
				break;
			else
				--smallest;
		}
			if(greatest<smallest )
			{
				swap=*greatest;
				*greatest=*smallest;
				*smallest=swap;
			}
	}
				swap=*pivot;
				*pivot=*smallest;
				*smallest=swap;
				split(pivot,smallest);
				split(greatest,(input+size));
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
