#include <stdio.h>

#define SUCCESS 0;
#define ERROR   -1;

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

//创建链表
int createLinkedList(Node **head)
{
    if(head == NULL) return ERROR;
    
    Node *pNode = (Node *)malloc(sizeof(Node));
	pNode->data = "nihao  shijie";
	pNode->next = NULL;
	
	*head = pNode;
	
	Node *p=pNode;
	
	pNode = (Node *)malloc(sizeof(Node));
	pNode->data = "我的世界";
	pNode->next = NULL;
	
	p->next = pNode;
	
	return SUCCESS;
}


int inserElement(Node *list,char *data)
{
	if(list==NULL) return ERROR;
	
	Node *p=list;
	while(p->next != NULL)
	{
		//printf("cur-->%s\n",p->data);
		p=p->next;
	}	
	
	//printf("ss %s\n",p->data);
	//
	Node *addNode = (Node *)malloc(sizeof(Node));
	addNode->data = data;
	addNode->next = NULL;
	
	p->next = addNode;
	
	return SUCCESS;
}

Node* addHeadList(Node *list_head,char *data)
{
	Node *p=list_head;
	
	Node *addNode = (Node *)malloc(sizeof(Node));
	addNode->data = data;
	addNode->next = list_head;
	
	return addNode;
}

//打印链表 
void printLinkedList(const Node *list){
	if(list==NULL) return;
	
	Node *p=NULL;
	p = list;
	printf("   链表数据:   \n");
	
	while(p!=NULL)
	{
		printf("%s\n",p->data);
		p=p->next;
	}//end while
	printf("\n\n");
}


int main()
{
	Node *headList;
	createLinkedList(&headList);
	
	printLinkedList(headList);
	
	inserElement(headList,"我的世界222");
	inserElement(headList,"我的世界333");
	inserElement(headList,"我的世界444");
	//inserElement(headList,"我的世界2");
	printLinkedList(headList);
	
	
	headList = addHeadList(headList,"我是新的头!");
	
	printLinkedList(headList);
	
    //printf("Hello World\n 你好 世界 \n");
    return 0;
}
