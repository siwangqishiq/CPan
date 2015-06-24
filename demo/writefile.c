#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	const char *file_path = "F:/hello/show.txt";

	FILE *fp = fopen(file_path,"a+");//已追加模式打开文件
	if(fp == NULL){
		printf("open file error\n");
		return -1;
	}

	printf("open file success\n");
	char data[1024]="My name is xinlan,I am fine And You?\n";

	int ret_write_file = fwrite(data,strlen(data),1,fp);
	if(ret_write_file == 1){
		printf("write file success\n");
	}else{
		printf("write file ERROR!~\n");
	}//end if

END:
	if(fp != NULL){
		fclose(fp);
	}
	system("pause");
	return 0;
}
