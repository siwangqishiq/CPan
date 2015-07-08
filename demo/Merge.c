#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define     SUCCESS       0
#define     ERROR        -1;

//归并排序
void mergeSort(int *data,int start,int end)
{
	int i=0;
	/*printf("start = %d   end = %d\n",start,end);
	printf("{");
	for(i=start;i<=end;i++)
	{
		printf("  %d",data[i]);
	}//end for i
	printf(" }\n");*/

	if(end > start)
	{
		int mid = (end -start)/2;
		mergeSort(data,start,start+mid);
		mergeSort(data,start+mid+1,end);
		
		merge(data,start,start+mid,start+mid+1,end);
	}
}

//合并两有序数列
int merge(int *data,int start1,int end1,int start2,int end2){
	int i=0;
	int len1 = end1 - start1 + 1;
	int len2 = end2 - start2 + 1;
	int *p1 = data+start1;
	int *p2 = data+start2;
	int index1 = 0;
	int index2 = 0;

	int len = len1+len2;
	int *tempArray = (int *)malloc(len*sizeof(int));
	int index = 0;
	if(tempArray==NULL)
	{
		printf("int *tempArray = (int *)malloc(len*sizeof(int)); error\n");
		return ERROR;
	}
	memset(tempArray,0,sizeof(int)*len);
	
	while(index1<len1 && index2<len2)
	{
		if(p1[index1] > p2[index2])
		{
			tempArray[index++] = p2[index2++];
		}
		else
		{
			tempArray[index++] = p1[index1++];
		}//end if
	}//end while

	while(index1<len1){
		tempArray[index++] = p1[index1++];
	}//end while

	while(index2<len2){
		tempArray[index++] = p2[index2++];
	}//end while

	
	/*printf("{ ");
	for(i=0;i<len1;i++)
	{
		printf("%d ",p1[i]);
	}//end for i
	printf("} merge with{ ");
	for(i=0;i<len2;i++)
	{
		printf("%d ",p2[i]);
	}//end for i
	printf("}\n");*/

	for(index=0;index<len;index++)
	{
		data[start1 + index] = tempArray[index];
	}//end for index

	/*printf("after merge { ");
	for(index=0;index<len;index++)
	{
		printf("%d ",data[start1 + index]);		
	}//end for index
	printf("}\n");*/
	

	if(tempArray!=NULL)
	{
		free(tempArray);
		tempArray = NULL;
	}
	
}

//冒泡排序
void bubbleSort(int *data,int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		for(j=len-1;j>i;j--)
		{
			if(data[j-1] > data[j])
			{
				int temp = data[j-1];
				data[j-1] = data[j];
				data[j] = temp;
			}//end if
		}//end for j
	}//end for i
}

void printArray(int data[],int len)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		printf("%d  ",data[i]);
	}//end for i
	printf("\n");
}

int main()
{
	int data[]={4,2,6,5,11,8,7,5,22,1,23,9,100,6,3};

	int data2[]={4,2,6,5,11,8,7,5,22,1,23,9,100,6,3};
	//int data[]={11,23,1};
	int dataLen = sizeof(data)/sizeof(int);
	printArray(data,dataLen);
	mergeSort(data,0,dataLen-1);//归并排序
	printArray(data,dataLen);


	printArray(data2,dataLen);
	bubbleSort(data2,dataLen);//冒泡排序验证
	printArray(data2,dataLen);

	system("pause");
	return SUCCESS;
}




