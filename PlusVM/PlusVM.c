/*
 * Main.c
 *
 *  Created on: 2015年5月19日
 *      Author: panyi
 *		虚拟机  仅支持两条指令 POP  ADD
 *
 *		POP A   将A元素入栈
 *		ADD pop a    pop b   a+b=c  并将相加结果push c
  *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100000
#define BUFFER_SIZE 100
#define SUCCESS 1
#define ERROR -1
#define ZERO 0


typedef int DATA_TYPE;

struct entry
{
	DATA_TYPE data;
	struct entry *next; 	 
};

typedef struct entry Entry;
typedef Entry* Stack;

struct file_content
{
	char data[BUFFER_SIZE][BUFFER_SIZE];//文件内容
	int lines;//指令行数
};
typedef struct file_content File;


/**
*创建一个运行栈
*返回栈底元素指针
*
*/
Stack createStack(){
	Stack p = (Stack)malloc(sizeof(Entry));	
	p->data = ZERO;
	p->next = NULL;
	return p;
}

/**
*向指定栈中push进一个元素
*/
int stackPush(Stack *stack,DATA_TYPE add_data){
	if(stack==NULL){
		return ERROR;
	}

	Entry* add = (Entry *)malloc(sizeof(Entry));
	add->data = add_data;
	add->next=(*stack);
	(*stack) = add;

	return SUCCESS;
}

void showLinkList(Entry *head);

/**
* 出栈操作
* 返回元素
*
*/
DATA_TYPE stackPop(Stack *stack){
	if((*stack)==NULL){
		return ZERO;
	}
	
	Stack p = (*stack);
	(*stack)=p->next;
	
	Entry* popNode = p;
	popNode->next = NULL;
	DATA_TYPE ret = popNode ->data;
	popNode->next = NULL;
	free(popNode);
	
	return ret;
}

/**
* 展示链表
* head 链表头指针
*/
void showLinkList(Entry *head){
	Entry *p = head;
	while(p!=NULL){
		printf("%d  ",p->data);	
		p=p->next;
	}//end while

	printf("\n");
}

/**
*读取文本文件
*
*返回内容二维数组
* 指令行数
*/
int readFile(char *file_name,File** file){
	//(*file)->data = NULL;
	FILE *fp;

	char line[BUFFER_SIZE];
	fp = fopen (file_name, "rt");

	int read_index = 0;
	char** content = (char**)(*file)->data;

	printf("*** read file content: ***\n");
	while(fgets(line,80,fp) != NULL){
		printf("%s",line);	
		*(content+read_index) = (char *)malloc(BUFFER_SIZE*sizeof(char));
		strcpy(*(content+read_index),line);//拷贝字符串
		
		read_index++;
	}//end while
	(*file)->lines = read_index;
	
	//printf("\nfile lines ---> %d",(*file)->lines);

	printf("\n*** content end ***\n");
	fclose(fp);  
	
	return SUCCESS;
}

 int main(){
	printf("-----------------------PlusVM will start----------------------\n\n");
	
	//Entry *pEntry = (Entry *)malloc(sizeof(Entry));
	
	//pEntry->data = 13;
	//pEntry->next = NULL;
	//printf("data--->%d \n",pEntry->data);
	//printf("size=%d \n",sizeof(pEntry));

	//free(pEntry);

	//printf("realloc memory--->%d \n",reallocInt);
	Stack stack;
	stack = createStack();

	//printf("realloc memory--->%d \n",stack->data);
	//stackPush(&stack,100);
	//printf("%d \n",stack->data);

	//stackPush(&stack,200);
	//printf("%d \n",stack->data);

	//stackPush(&stack,301);
	//printf("%d \n",stack->data);

	
	//printf("e1 -- %d \n",stackPop(&stack));
	//printf("e2 -- %d \n",stackPop(&stack));
	//printf("e3 -- %d \n",stackPop(&stack));

	//char str[4][100]={"nihao","shijie","woshigeass"};

	//int i;
	//for(i=0;i<3;i++){
	//	printf("--->%s  \n",str[i]);
	//}//end for i
	
	char path[100];
	printf("Please input code path: \n");
	//scanf("%s",path);
	//printf("path: %s\n", "D:\\test.txt");
	
	char content[100][100];
	int contentNums=0;

	File* file = (File *)malloc(sizeof(File));

	if(readFile("D:\\test.txt",&file)!=SUCCESS){
		printf("Read file Error!\n");
		return 1;
	}

	char** fileContents = (char **)file->data;
	int len = file->lines;
	int i;
	for(i=0;i<len;i++){
		printf("%s",*(fileContents+i));
	}//end for i

	
	free(file);

	printf("----------------------PlusVM has closed ----------------------\n \n");

	return 0;
 }//end main 
