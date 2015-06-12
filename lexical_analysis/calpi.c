#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SUCCESS    0
#define ERROR     -1

float random(float a) {
	return ((float)rand()/(float)(RAND_MAX)) * a;
}

int calPi(float *result){
	float x,y;
	int i,j;
	long radius = 2000000;
	long area=0;
	srand((unsigned int)time(NULL));//随机数生成初始化

	for(i=0;i < radius;i++){
		x = random(1.0f);
		y = random(1.0f);
		if(x*x + y*y <= 1){
			area++;
			//printf("%d  ",area);
		}
	}//end for i
	(*result) = 4*((float)area/radius);

	return SUCCESS;
}

int main(){
	float piValue;
	calPi(&piValue);

	printf("calculate PI value is %2.2f \n",piValue);

	system("pause");
	return 0;
}