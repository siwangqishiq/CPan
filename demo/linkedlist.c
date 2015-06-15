#include <stdio.h>

#define SUCCESS 0;
#define ERROR   -1;

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

//��������
int createLinkedList(Node **head)
{
    if(head == NULL) return ERROR;
    
    Node *pNode = (Node *)malloc(sizeof(Node));
	pNode->data = "nihao  shijie";
	pNode->next = NULL;
	
	*head = pNode;
	
	Node *p=pNode;
	
	pNode = (Node *)malloc(sizeof(Node));
	pNode->data = "�ҵ�����";
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

//��ӡ���� 
void printLinkedList(const Node *list){
	if(list==NULL) return;
	
	Node *p=NULL;
	p = list;
	printf("   ��������:   \n");
	
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
	
	inserElement(headList,"�ҵ�����222");
	inserElement(headList,"�ҵ�����333");
	inserElement(headList,"�ҵ�����444");
	//inserElement(headList,"�ҵ�����2");
	printLinkedList(headList);
	
	
	headList = addHeadList(headList,"�����µ�ͷ!");
	
	printLinkedList(headList);
	
    //printf("Hello World\n ��� ���� \n");
    return 0;
}
