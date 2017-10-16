#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "linklist.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESCRIBE_MAX_LEN 1024
#define CMD_NUM 50

typedef struct mNode
{
	linkNode * next;
	char* cmd;
	char* desc;
	int (*handler)();
}menuNode;

/*find a cmd */
menuNode* FindCmd(linkTable* table, char* cmd)
{
	menuNode * mNode = (menuNode*)GetLinkTableHead(table);
	while (mNode != NULL)
	{
		if (strcmp(mNode->cmd, cmd) == 0) 
		{
			return mNode;
		}
		mNode = (menuNode*)GetNextLinkNode(table, (linkNode*)mNode);
	}
	return NULL;
}

/*show all cmd */
int ShowAllCmd(linkTable* table)
{
	menuNode * mNode = (menuNode*)GetLinkTableHead(table);
	while (mNode != NULL)
	{
		printf("%s - %s\n", mNode->cmd, mNode->desc);
		mNode = (menuNode*)GetNextLinkNode(table, (linkNode*)mNode);
	}
	return 0;
}

int InitMenuData(linkTable** table)
{
	*table = CreateLinkTable();
	menuNode* mNode = (menuNode*)malloc(sizeof(menuNode));
	mNode->cmd = "help";
	mNode->desc = "This is a cmd \n Menu List:";
	mNode->handler = Help;
	AddLinkNode(*table, (linkNode*)mNode);

	mNode = (menuNode*)malloc(sizeof(menuNode));
	mNode->cmd = "version";
	mNode->desc = "CMD Program V1.1";
	mNode->handler = NULL;
	AddLinkNode(*table, (linkNode*)mNode);


	mNode = (menuNode*)malloc(sizeof(menuNode));
	mNode->cmd = "version";
	mNode->desc = "CMD Program V1.1";
	mNode->handler = NULL;
	AddLinkNode(*table, (linkNode*)mNode);

	mNode = (menuNode*)malloc(sizeof(menuNode));
	mNode->cmd = "quit";
	mNode->desc = "Quit From CMD";
	mNode->handler = Quit;
	AddLinkNode(*table, (linkNode*)mNode);

	return 0;
}


linkTable* table = NULL;
/* menu program */

int main()
{
	InitMenuData(&table);

	/* cmd line */
	while (1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd:");
		scanf("%s", cmd);
		menuNode* mNode = FindCmd(table,cmd);

		if (mNode == NULL)
		{
			printf("It is a wrong cmd!\n");
			continue;
		}

		printf("%s  -  %s\n", mNode->cmd, mNode->desc);
		if (mNode->handler != NULL)
		{
			mNode->handler();
		}
	}


}

int Help()
{
	ShowAllCmd(table);
	return 0;
}

int Quit()
{
	exit(0);
}

