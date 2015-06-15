#include <stdio.h>
#include <stdlib.h>

#define SUCCESS   0
#define ERROR    -1

struct Node
{
    char *data;
    struct Node *next;
    struct Node *prior;
};

typedef struct Node Node;

int createList(Node **list_head)
{
	Node *addItem = (Node *)malloc(sizeof(Node));
	addItem->data = "head";
	addItem->next = NULL;
	addItem->prior = NULL;
	
	*list_head = addItem;
    return SUCCESS;
}

int addItem(Node *list,char *add_data)
{
	Node *p=list;
	while(p->next!=NULL)
	{
		p=p->next;
	}//end while
	
	Node *addItem = (Node *)malloc(sizeof(Node));
	addItem->data = add_data;
	addItem->next = NULL;
	addItem->prior = p;
	
	p->next = addItem;
	
	return SUCCESS;
}

int removeHead(Node **pList)
{
	Node *list = *pList;
	Node *p = list;
	Node *pNext = p->next;
	if(pNext!=NULL)
	{
		*pList = pNext;	
	 	p->prior = NULL;
		p->next = NULL;
		
		free(p);
	}
		
	return SUCCESS;
}

void printList(Node *list)
{
    printf("list data is :\n");
    Node *p=list;
    while(p!=NULL)
    {
        printf("%s\n",p->data);
        p=p->next;
    }//end while
    printf("\n");
}

void reorderPrint(Node *list)
{
	Node *p=list;
	while(p->next!=NULL)
	{
		p=p->next;
	}//end while
	
	int i=0;
	while(p->prior!=NULL)
	{
		i++;
		printf("%d %s\n",i,p->data);
		p=p->prior;
	}
	printf("\n\n");
}

int main()
{
    Node *list=NULL;
	createList(&list);
	//printList(list);
	
	addItem(list,"1111");
	addItem(list,"2222");	
	addItem(list,"3333");
	printList(list);
	
	removeHead(&list);
	printList(list);
	reorderPrint(list);
	
	removeHead(&list);
	printList(list);
	reorderPrint(list);
	
//	reorderPrint(list);
	
    return SUCCESS;
}
