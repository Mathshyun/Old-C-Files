/*
	Prime
	by Mathshyun!
	입력된 숫자까지의 모든 소수를 구하는 프로그램 
*/

#include <stdio.h>

int prime[100000000];
int cnt = 0;

int isPrime(int x) {
	for (int i = 0; i < cnt; i++)
		if (x % prime[i] == 0) return 0;
	return 1;
}

int main() {
	int num;
	printf("숫자를 입력해 주세요 : ");
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		if (isPrime(i)) {
			prime[cnt++] = i;
			printf("%d\n", i);
		}
	}
	return 0;
}
