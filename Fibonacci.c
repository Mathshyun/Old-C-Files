/*
	Fibonacci
	by Mathshyun
	입력된 수 이하의 피보나치 수열을 출력 
*/

#include <stdio.h>

int main() {
	int fib[100000] = {1, 1, };
	int num;
	printf("자연수를 입력하세요 : ");
	scanf("%d", &num);
	printf("1\n1\n");
	if (num < 1) return 0;
	for (int i = 1;;) {
		int a = fib[i - 1] + fib[i];
		if (a > num) break;
		fib[++i] = a;
		printf("%d\n", a);
	}
	return 0;
}
