#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linkNode * findCmd(linkNode * head, char * cmd)
{
	if(head == NULL || cmd == NULL)
	{
		return NULL;
	}    
	linkNode * p = head;
	while(p != NULL)
	{
		if(strcmp(p->cmd,cmd) == 0)
		{
			return p;
		}
		p = p->next;
	}
}

int showAllCmd(linkNode * head)
{
	linkNode * p = head;
	while(p != NULL)
	{
		printf("%s :    %s\n",p->cmd, p->describe);
		p = p->next;
	}
	return 0;
}


int showNum(linkNode * head)
{
	linkNode * p = head;
	int num = 0;
	while(p != NULL)
	{
		++num;
		p = p->next;
	}
	printf("%d\n",num);
	return 0;
}



