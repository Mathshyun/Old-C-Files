/*
	Factor
	by Mathshyun!
	자연수가 입력되면 그 수의 약수를 모두 구하는 프로그램 
*/

#include <stdio.h>
 
int main() {
	int ent = 0;
	printf("자연수를 입력하세요 : ");
	while (ent <= 0) {
		scanf("%d", &ent);
		if (ent > 0) break;
		printf("자연수가 아닙니다! 다시 입력하세요 : ");
	}
	for (int i = 1; i <= ent; i++)
		if (ent % i == 0) printf("%d\n", i);
	return 0;
}
