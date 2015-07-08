#include <stdio.h>
#include <stdlib.h>


#define SUCCESS     0;
#define ERROR      -1;

int mergeSort(int *data,int start,int end)
{
	if(end <= start){
		return SUCCESS;
	}
	else
	{
		int mid = (end - start)/2;
		printf("mid = %d \n",mid);
		//切割数组
		mergeSort(data,start,start + mid);
		mergeSort(data + start + mid+1,start + mid +1,end);

		mergeArray(data,start,start + mid,
			data+start + mid+1,start+mid +1,end);//合并操作
	}//end if
}

int mergeArray(int *data,int start1,int end1,int start2,int end2)
{
	int len1 = end1-start1+1;
	int len2 = end2-start2+1;

	int len = len1 + len2;
	int *tempArray = NULL;
	printf("merge:start1 = %d    len1 = %d    start2 = %d    len2 = %d\n",
		start1,len1,start2,len2);
	merge(sub1,start1,len1,sub2,start2,len2,&tempArray);
	int i=0;
	for(i=0;i<len;i++)
	{
		data[i] = tempArray[i];
		printf("a[%d] = %d \n",i,sub1[i]);
	}//end for i
	free(tempArray);

	return SUCCESS;
}


int merge(int *sub1,int start1,int len1,int *sub2,int start2,int len2,int **out)
{
	int p1_index=0;
	int p2_index= 0;
	int index=0;
	int *tempArray = (int *)malloc((len1+len2)*sizeof(int));
	while(p1_index < len1 && p2_index < len2)
	{
		printf("-->  %d  compare %d\n",sub1[p1_index],sub2[p2_index]);
		if(sub1[p1_index]<sub2[p2_index])
		{
			tempArray[index++] = sub1[p1_index++];
		}
		else
		{
			tempArray[index++] = sub2[p2_index++];
		}//end if
	}//end while

	while(p1_index < len1)
	{
		tempArray[index++] = sub1[p1_index++];
	}//end while

	while(p2_index < len2)
	{
		tempArray[index++] = sub2[p2_index++];
	}//end while

	*out = tempArray;
}



void showArray(const int *data,int len)
{
	int i=0;

	for(i=0;i<len;i++)
	{
		printf("%d ",data[i]);
	}//end for i
	printf("\n");
}

int main()
{
	int a[] = {2,4,6,8,100,200};
	int len_a = sizeof(a)/sizeof(int);
	int b[]={1,3,5,6,7,10,11,12};
	int len_b = sizeof(b)/sizeof(int);
	
	//int data[]={100,23,12,11,9,23,44,9,1,2,3,3,101,222,333,121};
	int data[]={5,4,3,2,1};
	//int data[]={100,23,12,11};
	int len = sizeof(data)/sizeof(int);


	int testData[]={2,1,3};
	
	showArray(data,len);
	mergeSort(data,0,len-1);
	showArray(data,len);

	system("pause");
	return 0;
}
