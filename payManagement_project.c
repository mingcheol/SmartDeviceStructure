/* �� ������Ʈ �䱸���� 

 - �̸�, ��ȭ��ȣ, �ٹ��ð�, �ð��� �ӱ��� Ű����� �Է� �޽��ϴ�.

  (�ּ��� 5�� �̻� �Է°���, �̸��� ���鹮���Է°���, ����ü�迭���)

 - �Է¹��� �����͸� �ӱ�(�ٹ��ð�X�ð����ӱ�)�� �������� �������������Ͽ�

  ���Ͽ� ���(����)�ϵ��� �ۼ��մϴ�. (���ϸ�: output.txt)

 - ȭ�鿡�� �ð����ӱ��� ���� ���� �޴� ������ ȸ�翡�� �����ؾ� ��

  ������ӱ��հ谡 ������ ����մϴ�.

	<�Է� ����>
	# �����͸� �Է��ϼ���.
	 �̸� : �ڹ�ö
	 ��ȭ��ȣ : 010-7565-3529
	 �ٹ��ð� : 12
	 �ð��� �ӱ� : 2500

	<���� ��� ����>

	Name		Phone		Working hour	pay/hour	Total Pay
	==============================================================================================
	����		010-7565-3213	     9		4000		36000
	���		010-4265-6879	     10		3000		30000
	��ö		010-6665-9789	     12		2500		30000
	����		010-5465-1277	     8		3300		26400
	�¿�		010-9765-9219	     3		2000		26000
	==============================================================================================


	<ȭ�� ��� ����>
	# �Էµ� ���� ���� ��� 5���Դϴ�.
	# �ð����ӱ��� ���� ���� ������ 4000���� �޴� Minsu �Դϴ�.
	# ���� �����ؾ� �� ������ӱ��հ�� 148000�� �Դϴ�.
*/

//*****************************************************************
//	�޿� ���� ���� ���α׷�
//	Made by  Min-Choel
//	E-Mail: smilemc96@naver.com
//*****************************************************************

#include <stdio.h>

#define MAX_INPUT 100		//�ִ� �Է¹����� �ִ� �����ͼ�

struct person{
	char name[50];
	char phone[20];
	int pay_hour;
	int work_hour;
	int total_pay;
};

int input_data(struct person data[]);	//�Է��� �޴� �Լ� ���ϰ��� �� �Է¹��� �����
int calc_pay(struct person data[],int total_person);		//�ӱ��� ����ϴ� �Լ� ���ϰ��� �� ����� �ӱ� �հ�
int sort_data(struct person data[],int total_person);		//�ӱ��� �������� �����ϴ� �Լ� 
int find_exp_person(struct person data[],int total_person);
int output_file(struct person data[],int total_person);

int main()
{
	int total_person;
	int total_person_pay;
	int exp_person;						//�ñ��� ���� ��ΰ� �޴� ���
	struct person data[MAX_INPUT];		//�����Ͱ� ����Ǵ� ����ü �迭
	

	total_person = input_data(data);
	total_person_pay = calc_pay(data,total_person);
	sort_data(data,total_person);
	exp_person = find_exp_person(data,total_person);
	output_file(data,total_person);
	
	printf("\n#�Էµ� ������ ���� ��� %d�� �Դϴ�.",total_person);
	printf("\n#�ð��� �ӱ��� ���� ���� ������ %d���� �޴� %s �Դϴ�.",data[exp_person].pay_hour,&data[exp_person].name);
	printf("\n#���� �����ؾ��� �� ������ӱ��� �հ�� %d�� �Դϴ�.\n",total_person_pay);

	getch();		//���α׷��� ������ ȭ���� �ٷ� �����°��� ����
	return 0;
}

int input_data(struct person data[])
{
	int i;
	printf("\n#�����͸� �Է��ϼ���(�̸��� q�� �Է��ϸ� �Է��� �����մϴ�.)");
	printf("\n#�ִ� %d���� �����͸� �Է��Ҽ� �ֽ��ϴ�.",MAX_INPUT);
	for(i=0;i<MAX_INPUT;i++)
	{
		fflush(stdin);		//�Է� ��Ʈ���� ����ش�.
		printf("\n�̸�:");
		gets(data[i].name);
		if((data[i].name[0]=='q') && ((char)data[i].name[1]=='\0'))	//�̸��� q�� �Է��������
			break;
		printf("��ȭ��ȣ:");
		gets(data[i].phone);
		printf("�ٹ��ð�:");
		scanf("%d",&data[i].work_hour);
		printf("�ð��� �ӱ�:");
		scanf("%d",&data[i].pay_hour);
	}
	printf("\n#�Է��� ���� �մϴ�.");
	
	return i;
}

int calc_pay(struct person data[],int total_person)
{
	int i;
	int total_person_pay=0;
	for(i=0;i<total_person;i++)
	{
		data[i].total_pay = data[i].work_hour * data[i].pay_hour;
		total_person_pay += data[i].total_pay;		//�����ؾ��� �� �ӱ��� ���Ѵ�.
	}
	return total_person_pay;
}

int sort_data(struct person data[],int total_person)
{
	int i,j;
	struct person temp;					//���Ľ� ����ϴ� �ӽ� ����ü
	for(i=0;i<total_person-1;i++)
	{
		for(j=i;j<total_person;j++)
		{
			if(data[i].total_pay < data[j].total_pay)	//�������� ��������
			{
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
			}
		}
		
	}
	return 0;
}

int find_exp_person(struct person data[],int total_person)
{
	int i;
	int exp_person=0,exp_person_pay=0;
	for(i=0;i<total_person;i++)
	{
		if(data[i].pay_hour > exp_person_pay)		//�ñ��� ���� ���� �޴»���� ���
		{
			exp_person_pay = data[i].pay_hour;
			exp_person = i;
		}
	}
	return exp_person;
}

int output_file(struct person data[],int total_person)
{
	FILE *f_out;
	int i;
	f_out = fopen("output.txt","wt");
	fprintf(f_out,"Name\tPhone\t\tWorking Hour\tpay/hour\tTotal pay\n");
	fprintf(f_out,"=========================================================================\n");
	for(i=0;i<total_person;i++)
	{
		fprintf(f_out,"%s\t%s\t%d\t\t%d\t\t%d\n",&data[i].name,&data[i].phone,data[i].work_hour,data[i].pay_hour,data[i].total_pay);
	}
	fprintf(f_out,"=========================================================================\n");
	fclose(f_out);
	return 0;
}