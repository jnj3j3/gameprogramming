#include<stdio.h>
int main(){
	char string[20];
	char c;
	printf("���ڿ� �Է�>");
	scanf("%s",string);
	prntf("���� �Է�>"); 
	scanf(" %c",&c);
	
	printf("%s\n",string);
	printf("!!%c!!\n",c);
	
	return 0;
}