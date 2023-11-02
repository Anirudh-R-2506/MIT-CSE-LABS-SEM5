#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];

void S();
void T();
void TPrime();

void invalid()
{
	printf("-----------------ERROR!----------------\n");
	exit(0);
}

void valid()
{
	printf("----------------SUCCESS!---------------\n");
	exit(0);
}

void S(){
	if (str[curr] == 'a'){
		curr++;
		return;
	}
	else if(str[curr] == '>'){
		curr++;
		return;
	}
	else if(str[curr] == '('){
		curr++;
		T();
		if(str[curr] == ')'){
			curr++;
			return;
		}
	}
}

void TPrime(){
	if (str[curr] == ','){
		curr++;
		S();
		TPrime();
	}
}

void T(){
	TPrime();
	S();
}

int main()
{
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[curr] == '$')
		valid();
	else
		invalid();
}