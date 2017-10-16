#pragma once
/*
*LinkTable Node Type
*/
typedef struct Node
{
	struct Node * next;
}linkNode;

/*
* LinkTable
*/
typedef struct Table
{
	linkNode * head;
	linkNode * tail;
	int sum;
}linkTable;

/*
* Create a LinkTable
*/
linkTable * CreateLinkTable();

/*
* Delete a LinkTable
*/
int DeleteLinkTable(linkTable * pLinkTable);

/*
* Add a LinkNode to LinkTable
*/
int AddLinkNode(linkTable * pLinkTable, linkNode * pLinkNode);

/*
* Delete a LinkNode from LinkTable
*/
int DeleteLinkNode(linkTable *pLinkTable, linkNode *pLinkNode);

/*
* get LinkTable head
*/
linkNode * GetLinkTableHead(linkTable * pLinkTable);

/*
* get Next LinkNode
*/
linkNode * GetNextLinkNode(linkTable * pLinkTable, linkNode *pLinkNode);

