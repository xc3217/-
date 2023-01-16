#include<stdio.h>
int fun(int x, int y) {
	int temp=10;
	int result = x > y ? x : y;
	result += temp;
	return result;
}
int main(int argc, char** argv) {
	printf("fun(10, 20) = % d\n", fun(10, 20));
}
