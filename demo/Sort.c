#include <stdio.h>
#include <stdlib.h>

void swipNumber(int *a,int *b){
	int temp=*a;
	*a= (*b);
	*b = temp;
}

//bubble sort
int sortBubble(int *data,const int num){
	int i,j;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(data[j]<data[j-1]){
				swipNumber(data+j,data+j-1);
			}//end if
		}
	}//end for i
	return 0;
}

//insert sort
int sortInsert(int *data,const int num){
	int i,p;
	for(p=1;p<num;p++){
		for(i=p;i>0;i--){
			if(data[i]<data[i-1]){
				swipNumber(data+i,data+i-1);
			}else{
				break;
			}
		}//end for i
		//data[i]=cur;
	}//end for p
}

void printArray(int *data,const int num){
	int i;
	for(i=0;i<num;i++){
		printf("%d ",*(data+i));
	}//end for i
	printf("\n");
}


int main(){
	int data[]={4,6,2,8,5,6,7,0,12,34,39,56,33,11,1,13};
	int data2[]={4,6,2,8,5,6,7,0,12,34,39,56,33,11,1,13};
	int num=sizeof(data)/sizeof(int);
	printArray(data,num);
	sortBubble(data,num);
	printArray(data,num);
	sortInsert(data2,num);
	printArray(data2,num);
	system("pause");
	return 0;
}