#include <stdio.h>

char *readFile(char *file_path){
	FILE *file=fopen(file_path,"rb");
	fseek(file,0,SEEK_END);
	long len = ftell(file);
	fseek(file,0,SEEK_SET);
	char *data = (char *)malloc(len+2);
	fread(data,1,len,file);
	data[len]='\0';
	fclose(file);

	return data;

}

int main(){
	char *data = readFile("F:\\cJSON\\test.txt");
	
	printf("content---> %s",data);
	free(data);
	return 0;
}
