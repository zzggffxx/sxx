#include <stdio.h>
#include<stdlib.h>
#include "linklist.h"

linkTable * CreateLinkTable()
{
	linkTable *p = (linkTable*)malloc(sizeof(linkTable));
	p->head = p->tail = NULL;
	p->sum = 0;
	return p;
}

int DeleteLinkTable(linkTable *pLinkTable) 
{
	linkTable * p = pLinkTable;
	pLinkTable = NULL;
	free(p);
	return 1;
}

int AddLinkNode(linkTable *pLinkTable, linkNode *pLinkNode) 
{
	if (pLinkTable->sum == 0) {
		pLinkTable->head = pLinkTable->tail = pLinkNode;
		pLinkTable->sum = 1;
	}
	else
	{
		pLinkTable->tail->next = pLinkNode;
		pLinkTable->tail = pLinkNode;
		++(pLinkTable->sum);
	}

}

int DeleteLinkNode(linkTable * pLinkTable, linkNode *pLinkNode)
{
	linkNode *p = pLinkTable->head;
	while (p != pLinkTable->tail) 
	{
		if (p->next == pLinkNode) 
		{
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}

	}
}

/*
* get LinkTable head
*/
linkNode * GetLinkTableHead(linkTable * pLinkTable)
{
	return pLinkTable->head;
}

/*
* get Next LinkNode
*/
linkNode * GetNextLinkNode(linkTable * pLinkTable, linkNode *pLinkNode)
{
	if (pLinkNode != pLinkTable->tail)
	{
		return	pLinkNode->next;
	}
	else
	{
		return NULL;
	}
}
