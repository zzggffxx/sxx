typedef struct Node
{
    char * cmd;
    char * describe;
    int (*function)();
    struct Node * next;
}linkNode;

linkNode * findCmd(linkNode * head, char * cmd);

int showCmd(linkNode * head);

int showNum(linkNode * head);
