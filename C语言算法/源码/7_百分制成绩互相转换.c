#include <stdio.h>
#include <stdlib.h>

int main() {
	int grade;
	scanf("%d", &grade);
	if (grade >= 90)
	{
		printf("A\n");
	}
	else if (grade < 90 && grade >= 80)
	{
		printf("B\n");
	}
	else if (grade >= 70 && grade < 80)
	{
		printf("C\n");
	}
	else if (grade >= 60 && grade < 70)
	{
		printf("D\n");
	}
	else
	{
		printf("E\n");
	}
	return 0;
}

