#include <stdio.h>
#include <stdlib.h>

#define SUCCESS     0
#define ERROR      -1

//swap two number
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp; 
}

//print Array
void printArray(int *data,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d  ",data[i]);
	}//end for i
	printf("\n");
}

//quick sort
void quickSort(int *data,int start,int end)
{
	if(end > start)
	{
		int midIndex = findMidIndex(data,start,end);
		quickSort(data,start,midIndex-1);
		quickSort(data,midIndex+1,end);
	}//end if
}

// 发现中位数 返回中位数index
int findMidIndex(int *data,int start,int end)
{
	int i = start-1;
	int j = start;

	for(j = start;j<end;j++)
	{
		if(data[end] > data[j])
		{
			i++;
			swap(&data[i],&data[j]);
		}
	}//end for j

	swap(&data[i+1],&data[end]);
	return i+1;
}

void play2()
{
	int data[]={10,7,3,5,6,1,4,9,100,94,69,23,34,0,11,13,101};
	int len = sizeof(data)/sizeof(int);
	printArray(data,len);

	//int midIndex = findMidIndex(data,0,len-1);
	//printf("mid Index is %d\n",midIndex);
	quickSort(data,0,len-1);

	printArray(data,len);
}

void play()
{
	int data[]={10,7,3,5,6,1,4,9,100,94,69,23,34};
	int len = sizeof(data)/sizeof(int);
	//printArray(data,len);

	//int a[]={1,3,11,12,2,4};
	//int lenA = sizeof(a)/sizeof(int);
	printArray(data,len);
	quickSort(data,0,len-1);
	printArray(data,len);
}


int main()
{
	play2();
	
	//printf("midIndex is %d\n",midIndex);

	system("pause");
	return SUCCESS;
}
