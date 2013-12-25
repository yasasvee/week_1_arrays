#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void read(char *input)
{
	printf("enter your string\n");
	scanf("%s",input);
}
int power(int base,int exponent)
{
	int product=1;
	while(exponent--)
		product=product*base;
	return product;
}
int convert(char *input,int size)
{
	int exponent=0,result=0;
	while((input+size)>=(input))
	{
		result=result+((*(input+size)-'0')*power(2,exponent));
		--size;
		++exponent;
	}
	return result;
}
void display(char *input)
{
	printf("\nthe string is\n");
	while(*input)
		printf("%c\t",*input++);
}
int reverse(int digit)
{
	int reverse=0;
	while(digit)
	{
		reverse=reverse*10;
		reverse=reverse+digit%10;
		digit=digit/10;
	}
	return reverse;
}
void print_number_decimal(int number)
{
	int number_str,temp=0;
	if(number<=9)
		printf("the resultant decimal is %c\n",(number+'0'));
	else
	{
		printf("the resultant decimal is\n");
		number_str=reverse(number);
		while(number_str)
		{
			temp=number_str%10;
			printf("%c",(temp+'0'));
			number_str=number_str/10;
		}
	}
}
void print_number_octal(int decimal)
{
	int i=1,octal=0,octal_str,temp=0;
	while(decimal!=0)
	{ 
		octal=octal+(decimal%8)*i;
		decimal=decimal/8;
		i=i*10;
	}
	if(octal<=9)
		printf("\nthe resultant octal is %c\n",(octal+'0'));
	else
	{
		printf("\nthe resultant octal is\n");
		octal_str=reverse(octal);
		while(octal_str)
		{
			temp=octal_str%10;
			printf("%c",(temp+'0'));
			octal_str=octal_str/10;
		}
	}
}
void print_number_hex(int decimal,int size)
{
	int count=0;
	size=(size/4)+2;
	int hex=0;
	char *hex_str;
	hex_str=(char*)malloc(size);
	printf("\nthe resultant hex is \n");
	while(decimal!=0)
	{ 
		hex=hex+(decimal%16);
		if(hex<=9)
			*(hex_str+count)=(hex+'0');
		else
		{
			switch(hex)
			{
			case 10:
				*(hex_str+count)='A';
				break;
			case 11:
				*(hex_str+count)='B';
				break;
			case 12:
				*(hex_str+count)='C';
				break;
			case 13:
				*(hex_str+count)='D';
				break;
			case 14:
				*(hex_str+count)='E';
				break;
			case 15:
				*(hex_str+count)='F';
				break;
			}
		}
		++count;
		decimal=decimal/16;
		hex=0;
	}
	count=size-2;
	while((hex_str+count)>=hex_str)
	{
		printf("%c",*(hex_str+count));
		count--;
	}
}
int main(void)
{
	char index,*binary;
	int decimal;
	printf("Enter the length of your binary numbers\n");
	scanf("%d",&index);
	binary=(char*)malloc(sizeof(char)*index);
	read(binary);
	decimal=convert(binary,--index);
	print_number_decimal(decimal);
	print_number_octal(decimal);
	print_number_hex(decimal,index);
	display(binary);
	getch();
	return 0;
}
