#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char cmd[128];
	int result;

	while(1)
	{
		scanf("%s",cmd);
		
		if(!strcmp("add",cmd))
		{
			result = add();
			printf("%d\n",result);
		}
		if(!strcmp("minus",cmd))
		{
			result = minus();
			printf("%d\n",result);
		}
		if(!strcmp("help",cmd))
		{
			printf("this is a cmd\n");
		}
		if(!strcmp("save",cmd))
		{
			printf("it is saved\n");
		}
		if(!strcmp("hello",cmd))
		{
			printf("hello,welcome to cmd\n");
		}
		if(!strcmp("thanks",cmd))
		{
			printf("you are welcome\n");
		}
		if(!strcmp("bye",cmd))
		{
			printf("bye\n");
		}
		if(!strcmp("quit",cmd))
		{
			exit(0);
		}	
	}
}   

int add()
{
	return (4+2);
}  
int minus()
{
	return (4-2);
}
