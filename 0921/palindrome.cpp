#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
struct stack_node{
	char data;
	struct stack_node*link;
};
stack_node*top = NULL;
void push(char data){
	struct stack_node *new_node;
	new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
	new_node -> data=data;
	new_node -> link = top;
	top=new_node;
}
char pop(void){
	struct stack_node*temp;
	char data;
	data = top->data;
	temp = top;
	top = top->link;
	free(temp);
	return data;
}

int main(void){
	int count = 0;
	char key[100];
	scanf("%s",key);
	for(int i=0;i<(int)strlen(key);i++){
		push(key[i]);
	}
	for(int i=0;i<(int)strlen(key);i++){
		if(key[i]!=pop()){
			printf("회문이 아닙니다");
			return 0;
		} 
	}
	printf("회문입니다.");
	return 0;
}

