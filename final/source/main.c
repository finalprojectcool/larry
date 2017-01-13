#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _book
{
	int date;  //���
	int amount; //�ƶq
	char note[20]; //�Ƶ�
}book;



typedef struct _file	//file1���J file2��X
{
	FILE *stream1; //
}files;

files myfile;

//-----------------------------------�Ƶ{���ŧi��
void searchdata(int keydate);
void printdata(char in ,char out);
//-----------------------------------�D�{����
int main(void)
{
	book mybook;
	int choice;		//��ܥ\��
	int choice1 = 0;
	int keydate;
	char in[8] = "���J";
	char out[8] = "��X";

	if ((myfile.stream1 = fopen("../income.txt", "a+")) != NULL) 
	{
		printf("�п�ܥ\��(1.��J��� 2.�d�b 3.�C�L�����):");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: //��J���
		{
				while (choice1 != 3)
				  {
					  printf("1.���J 2.��X 3.���}:");
					  scanf("%d", &choice1);

					  if (choice1 != 3)
					  {
							printf("��J���:");
							 scanf("%d", &mybook.date);

						  printf("��J���B:");
						  scanf("%d", &mybook.amount);

						  printf("��J�Ƶ�:");
						  scanf("%s", &mybook.note);

						  if (choice1 == 1)
						  {
							  fprintf(myfile.stream1, "%8d %5s %12d %-20s\n", mybook.date, in, mybook.amount, mybook.note);
						  }
						  else if (choice1 == 2)
						  {
							  fprintf(myfile.stream1, "%8d %5s %12d %-20s\n", mybook.date, out, mybook.amount, mybook.note);
						  }
					  }
					  else
						 printf("����x�s����\n");
				};
		}
			fclose(myfile.stream1);
			break;
		case 2: //�d�b
			printf("�п�J���:");
			scanf("%d", &keydate);
			searchdata(keydate);
			break;
		case 3: //�C�L�Ҧ����
			printdata(in , out);
			break;
		}

		
	}
	else
	{
		printf("�ɮ�Ū������");//�p�G�S��Ū��F��A����ɮ�Ū������
	}

	system("pause");
	return 0;
}

void searchdata(int keydate) //�Ƶ{��:�L�X�Ҭd�ߪ��b
{
	myfile.stream1 = fopen("../income.txt", "r");
	int date, amount;
	char inout[8];
	char note[20];

	printf("  ���	      ����  	   ���B	          �Ƶ�\n");
	printf("------------------------------------------------------\n");

	while ((fscanf(myfile.stream1, "%d%s%d%s", &date, &inout, &amount, &note)) != EOF)
	{
		if (keydate == date)

		{
			printf("%6d %9s %12d %14s\n", date, inout, amount, note);
		}
	}
	fclose(myfile.stream1);
}

void printdata(char in, char out) //�Ƶ{��:�L�X�b���������e
{
	myfile.stream1 = fopen("../income.txt", "r");
	int date, amount;
	char inout[8]; 
	char note[20];

	printf("  ���	      ����  	   ���B	          �Ƶ�\n");
	printf("------------------------------------------------------\n");
	while ((fscanf(myfile.stream1, "%d%s%d%s", &date, &inout, &amount, &note)) != EOF)
	{	
		printf("%6d %9s %12d %14s\n", date, inout, amount, note);
	}
	fclose(myfile.stream1);
}