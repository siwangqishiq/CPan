#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print
void printArray(int *data,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d  ",data[i]);
	}//end for i
	printf("\n");
}

//切割数组  返回数组中位数下标
int partion(int *data,int start,int end)
{
	int midValue = data[end];
	int len = end - start +1;
	int left = 0;
	int right = len-1;
	int *tempArray = (int *)malloc(len*sizeof(int));
	int i,j;
	if(len<=1) return 1;

	for(i=start;i<end;i++)
	{
		if(data[i] < midValue)
		{
			// --- mid
			tempArray[left++] = data[i];
		}
		else
		{
			// mid ---
			tempArray[right--] = data[i];
		}//end if
	}//end for i
	tempArray[left+1] = midValue;

	for(i=start,j=0;i<=end;i++,j++)
	{
		data[i] = tempArray[j];
	}//end for i

	free(tempArray);

	return left+1;
}

int main()
{
	int data[]={4,6,2,8,5,6,7,0,12,34,39,56,33,11,1,13};
	int data_len = sizeof(data)/sizeof(int);
	printArray(data,data_len);
	int midIndex = partion(data,0,data_len-1);
	printArray(data,data_len);
	printf("midIndex = %d\n",midIndex);
	system("pause");
	return 0;
}
