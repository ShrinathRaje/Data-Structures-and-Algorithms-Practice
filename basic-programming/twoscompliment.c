#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,j,length;
	char binary[16];
	
	printf("Enter a binary number\n");
	scanf("%s",binary);
	
	for(i=0; binary[i] != '\0'; ++i)
	{
		if(binary[i] != '1' && binary[i] != '0')
		{	
			printf("Invalid binary format\n");
			exit(0);
		}
	}
	
	length = strlen(binary);
	
	for(i=length-1; binary[i] != '1'; --i)
		;
	
	for(j=i-1; j>=0; --j)
	{
		if(binary[j] == '0')
			binary[j] = '1';
		else
			binary[j] = '0';
	}
	
	printf("2's compliment: %s\n",binary);
}
