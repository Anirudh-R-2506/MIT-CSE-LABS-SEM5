#include <stdio.h>

int def(int a) {
	return a+10;
}

int main(int argc) {
	int a = 12;
	int b = 14;
	char e = 'h';
	int c = a * b;
	int d = a / b;
	printf("hi");
	if (a == 12 && b == 14){
		printf("12");
	}
	if (b != 12){
		printf("14");
	}
}
