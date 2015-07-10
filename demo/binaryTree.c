#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode *pParent;
	struct TreeNode *pLeftChild;
	struct TreeNode *pRightChild;
} TreeNode;

//创建一颗二叉树
int createTree(TreeNode **tree,int data)
{
	TreeNode *pTemp = (TreeNode *)malloc(sizeof(TreeNode));
	if(pTemp==NULL)
	{
		return -1;
	}

	pTemp->key = data;
	pTemp->pParent = NULL;
	pTemp->pLeftChild = NULL;
	pTemp->pRightChild = NULL;

	*tree = pTemp;

	return 0;
}

//创建二叉树结点
TreeNode *createTreeNode(int data)
{
	TreeNode *pNode = (TreeNode *)malloc(sizeof(TreeNode));
	pNode->key = data;
	pNode->pParent = NULL;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;

	return pNode;
}

void freeTree(TreeNode *pTree)
{
	if(pTree!=NULL)
	{
		freeTree(pTree->pLeftChild);
		freeTree(pTree->pRightChild);
		printf("free Node :%d\n",pTree->key);
		free(pTree);
	}//end if
}

//给存在的树中插入值
int treeInsert(TreeNode *pRoot,int insertData)
{
	TreeNode *pCur = pRoot;
	TreeNode *pInsertNode = createTreeNode(insertData);

	while(pCur!=NULL)//end while
	{
		if(insertData > pCur->key)//插入右子树中
		{
			if(pCur->pRightChild != NULL)
			{
				pCur = pCur->pRightChild;
			}else{
				pCur->pRightChild = pInsertNode;
				pInsertNode->pParent = pCur;
				break;
			}//end if
		}
		else//插入左子树中
		{
			if(pCur->pLeftChild != NULL)
			{
				pCur = pCur->pLeftChild;
			}else{
				pCur->pLeftChild = pInsertNode;
				pInsertNode->pParent = pCur;
				break;
			}//end if
		}//end if
	}//end while
}

void printTreeInOrder(TreeNode *pTree){
	if(pTree != NULL)
	{
		printTreeInOrder(pTree->pLeftChild);
		printf("%d\n",pTree->key);
		printTreeInOrder(pTree->pRightChild);
	}
}

//前序遍历
void printTreePreOrder(TreeNode *pTree){
	if(pTree != NULL)
	{
		printf("%d\n",pTree->key);
		printTreeInOrder(pTree->pLeftChild);
		printTreeInOrder(pTree->pRightChild);
	}
}

//后序遍历
void printTreePostOrder(TreeNode *pTree){
	if(pTree != NULL)
	{
		printf("%d\n",pTree->key);
		printTreeInOrder(pTree->pLeftChild);
		printTreeInOrder(pTree->pRightChild);
	}
}

int main()
{
	TreeNode *pTree = NULL;
	int i=0;
	createTree(&pTree,100);

	printf("Tree Node root data %d\n",pTree->key);
	/*for(i=0;i<10;i++)
	{
		treeInsert(pTree,i+1);
	}//end for i*/


	treeInsert(pTree,23);
	treeInsert(pTree,22);
	treeInsert(pTree,12);

	printTreeInOrder(pTree);
	//printTreePostOrder(pTree);


	freeTree(pTree);

	system("pause");
	return 0;
}

