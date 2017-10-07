#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int help();
int num();

#define CMD_MAX 128

static linkNode head[] =
{
    {"help", "this is a cmd!", help, &head[1]},
    {"num", "the number of cmd: ", num, &head[2]},
    {"ver", "version v1.0", NULL, NULL}
};

int main()
{
    while(1)
    {
	char cmd[CMD_MAX];
	printf("please input a cmd:  ");
	scanf("%s",cmd);
	linkNode * p = findCmd(head,cmd);

	if(p == NULL)
	{
	    printf("this is a wrong cmd \n");
	}else{
	    printf("%s :    %s",p->cmd, p->describe);
	}

	if(p->function != NULL)
	{
	    p->function();
	}	
    }
    return 0;
}

int help()
{
    showAllCmd(head);
    return 0;
}

int num()
{
    showNum(head);
    return 0;
}



