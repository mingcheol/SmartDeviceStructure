/* ※ 프로젝트 요구사항 

 - 이름, 전화번호, 근무시간, 시간당 임금을 키보드로 입력 받습니다.

  (최소한 5건 이상 입력가능, 이름에 공백문자입력가능, 구조체배열사용)

 - 입력받은 데이터를 임금(근무시간X시간당임금)을 기준으로 내림차순정렬하여

  파일에 출력(저장)하도록 작성합니다. (파일명: output.txt)

 - 화면에는 시간당임금을 가장 많이 받는 직원과 회사에서 지불해야 할

  고용자임금합계가 얼마인지 출력합니다.

	<입력 예시>
	# 데이터를 입력하세요.
	 이름 : 박민철
	 전화번호 : 010-7565-3529
	 근무시간 : 12
	 시간당 임금 : 2500

	<파일 출력 예시>

	Name		Phone		Working hour	pay/hour	Total Pay
	==============================================================================================
	수민		010-7565-3213	     9		4000		36000
	경미		010-4265-6879	     10		3000		30000
	민철		010-6665-9789	     12		2500		30000
	민지		010-5465-1277	     8		3300		26400
	승용		010-9765-9219	     3		2000		26000
	==============================================================================================


	<화면 출력 예시>
	# 입력된 직원 수는 모두 5명입니다.
	# 시간당임금이 가장 높은 직원은 4000원을 받는 Minsu 입니다.
	# 현재 지불해야 할 고용자임금합계는 148000원 입니다.
*/

//*****************************************************************
//	급여 지급 관리 프로그램
//	Made by  Min-Choel
//	E-Mail: smilemc96@naver.com
//*****************************************************************

#include <stdio.h>

#define MAX_INPUT 100		//최대 입력받을수 있는 데이터수

struct person{
	char name[50];
	char phone[20];
	int pay_hour;
	int work_hour;
	int total_pay;
};

int input_data(struct person data[]);	//입력을 받는 함수 리턴값은 총 입력받은 사람수
int calc_pay(struct person data[],int total_person);		//임금을 계산하는 함수 리턴값은 총 고용자 임금 합계
int sort_data(struct person data[],int total_person);		//임금을 내림차순 정렬하는 함수 
int find_exp_person(struct person data[],int total_person);
int output_file(struct person data[],int total_person);

int main()
{
	int total_person;
	int total_person_pay;
	int exp_person;						//시급을 가장 비싸게 받는 사람
	struct person data[MAX_INPUT];		//데이터가 저장되는 구조체 배열
	

	total_person = input_data(data);
	total_person_pay = calc_pay(data,total_person);
	sort_data(data,total_person);
	exp_person = find_exp_person(data,total_person);
	output_file(data,total_person);
	
	printf("\n#입력된 직원의 수는 모두 %d명 입니다.",total_person);
	printf("\n#시간당 임금이 가장 높은 직원은 %d원을 받는 %s 입니다.",data[exp_person].pay_hour,&data[exp_person].name);
	printf("\n#현재 지불해야할 총 고용자임금의 합계는 %d원 입니다.\n",total_person_pay);

	getch();		//프로그램이 끝나고 화면이 바로 닫히는것을 막음
	return 0;
}

int input_data(struct person data[])
{
	int i;
	printf("\n#데이터를 입력하세요(이름에 q를 입력하면 입력을 종료합니다.)");
	printf("\n#최대 %d개의 데이터를 입력할수 있습니다.",MAX_INPUT);
	for(i=0;i<MAX_INPUT;i++)
	{
		fflush(stdin);		//입력 스트림을 비워준다.
		printf("\n이름:");
		gets(data[i].name);
		if((data[i].name[0]=='q') && ((char)data[i].name[1]=='\0'))	//이름에 q를 입력했을경우
			break;
		printf("전화번호:");
		gets(data[i].phone);
		printf("근무시간:");
		scanf("%d",&data[i].work_hour);
		printf("시간당 임금:");
		scanf("%d",&data[i].pay_hour);
	}
	printf("\n#입력을 종료 합니다.");
	
	return i;
}

int calc_pay(struct person data[],int total_person)
{
	int i;
	int total_person_pay=0;
	for(i=0;i<total_person;i++)
	{
		data[i].total_pay = data[i].work_hour * data[i].pay_hour;
		total_person_pay += data[i].total_pay;		//지불해야할 총 임금을 더한다.
	}
	return total_person_pay;
}

int sort_data(struct person data[],int total_person)
{
	int i,j;
	struct person temp;					//정렬시 사용하는 임시 구조체
	for(i=0;i<total_person-1;i++)
	{
		for(j=i;j<total_person;j++)
		{
			if(data[i].total_pay < data[j].total_pay)	//내림차순 버블정렬
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
		if(data[i].pay_hour > exp_person_pay)		//시급을 가장 많이 받는사람을 골라냄
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