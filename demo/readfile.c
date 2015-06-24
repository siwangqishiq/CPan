#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main(){
	const char *file_path = "F:/hello/show.txt";

	FILE *fp = fopen(file_path,"r");
	if(fp == NULL){
		printf("open file error\n");
		return -1;
	}
	printf("open file success\n");
	
	//TODO 读文件
	char read_buffer[MAX_SIZE];
	//int read_size = fread(read_buffer,sizeof(char),MAX_SIZE,fp);
	//printf("read char num = %d\n",read_size);
	//printf("content : %s\n",read_buffer);
	


	while(!feof(fp)){
		char *content = fgets(read_buffer,MAX_SIZE,fp);
		if(content != NULL){
			printf("content : %s\n",content);
			free(content);
		}//end if
	}//end while
	
END:
	if(fp != NULL){
		fclose(fp);
	}
	system("pause");
	return 0;
}
