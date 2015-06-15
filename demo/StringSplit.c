//
//  StringSplit.c
//  CPan
//
//  Created by  潘易  on 15-6-13.
//  Copyright (c) 2015年 xinlan. All rights reserved.
// 有一个字符串符合以下特征 ("abcdefg,acccf,eeee,aaaa,e3eeee,sssss,")
// 要求写一个函数输出以下结果:
// 以逗号分割的字符串 形成二位数组 并把结果传出
// 把二维数组行数运算结果也传出
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0;
#define ERROR   -1;

int findCharIndex(const char *str,char c){
    int index = -1;
    if(str==NULL) return index;
    int indicator=0;
    while(*(str+indicator)!='\0'){
        if(*(str+indicator)!=c){
        }else{
            index = indicator;
            break;
        }
        indicator++;
    }//end while
    return index;
}

int split(const char *src,char ***data,int *num){
    const char *p=src;
    //char **result = *data;
    int sum=0;
    while(*p!='\0'){
        if(*p==','){
            sum++;
        }//end if
        p++;
    }//end while
    *num=sum;//总行数
    char **result = (char **)malloc(sizeof(char *)*sum);
    
    const char *start=src;
    //printf("start-->%s\n",start);
    for(int i=0;i<sum;i++){
        int charPos = findCharIndex(start, ',');
        if(charPos < 0) break;
        
        char *strData = (char *)malloc(sizeof(char));
        
        strncpy(strData, start, charPos);
        charPos++;
        strData[charPos]='\0';
        
        result[i]=strData;
        //printf("分割的字符串-->%s  长度:%d\n",strData,charPos);
        start+=charPos;
        //printf("剩余字符串 %s \n",start);
    }//end for i
    
    *data=result;
    
    return SUCCESS;
}

int split_free(char **data,const int colNum){
    if(data==NULL) return ERROR;
    
    for(int i=0;i<colNum;i++){
        if(data[i]!=NULL){
            free(data[i]);
            data[i] = NULL;
        }
    }//end for i
    if(data!=NULL){
        free(data);
        data=NULL;
    }
    return SUCCESS;
}



int main(){
    char str[100]="abcdefg,acccf,eeee,aaaa,e3eeee,sssss,";
    char **data;
    int colNum=0;
    split(str,&data,&colNum);
    
    //int s = findCharIndex(str,',');
    //printf("%d \n",s);
    printf("%s \n",str);
    
    printf("col num is %d \n",colNum);
    
    printf("the data is: \n");
    //打印二维数组
    for(int i=0;i<colNum;i++){
        printf("%s\n",*(data+i));
    }
    
    
    //释放内存
    split_free(data,colNum);
    return SUCCESS;
}//end main
