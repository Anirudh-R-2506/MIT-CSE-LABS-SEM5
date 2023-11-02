#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int curr = 0;
char str[100];

void S();
void A();
void B();
void Ap();

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
		A();
		if(str[curr] == 'c'){
			curr++;
			B();
			if(str[curr] == 'e'){
				curr++;
				return;
			}
		}
	}
}

void B(){
	if (str[curr] == 'd'){
		curr++;
		return;
	}
}

void A(){
	if (str[curr] == 'b'){
		curr++;
		Ap();
	}
}

void Ap(){
	if (str[curr] == 'b'){
		curr++;
		Ap();
	}
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