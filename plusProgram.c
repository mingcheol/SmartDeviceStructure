#include <stdio.h>

int first_value = 0, second_value = 0, sum_result = 0;
int value[2] = { 0 };

void input_value() 
{
	printf("ù��° �� >> ");
	first_value = scanf("%d", &value[0]);
	printf("�ι�° �� >> ");
	second_value = scanf("%d", &value[1]);
}

int sum(int first_value, int second_value)
{
	int result = first_value + second_value;

	return result;
}

int main()
{
	printf("���� ���ڸ� �Է��ϼ���.\n");
	input_value();
	sum_result = sum(first_value, second_value);
	printf("%d + %d = %d �Դϴ�.", first_value, second_value, sum_result);

	getchar();
	getchar();

	return 0;
}