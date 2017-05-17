/*
	PrimeFactor
	by Mathshyun!
	입력된 자연수의 소인수를 모두 구하는 프로그램 
*/
#include <stdio.h>

int isPrime(long long x) {
	for (long long i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

int main() {
	long long ent = 0, tmp;
	printf("자연수를 입력하세요 : ");
	while (ent <= 0) {
		scanf("%lld", &ent);
		if (ent > 0) break;
		printf("자연수가 아닙니다! 다시 입력하세요 : ");
	}
	for (long long i = 2; i <= ent; i++) {
		if (!isPrime(i)) continue;
		while (ent % i == 0) {
			printf("%d\n", i);
			ent /= i;
		}
	}
	return 0;
}
