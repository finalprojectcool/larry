#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct _book
{
	int date;  //日期
	int amount; //數量
	char note[20]; //備註
}book;



typedef struct _file	//file1收入 file2支出
{
	FILE *stream1; //
}files;

files myfile;

//-----------------------------------副程式宣告區
void searchdata(int keydate);
void printdata(char in ,char out);
//-----------------------------------主程式區
int main(void)
{
	book mybook;
	int choice;		//選擇功能
	int choice1 = 0;
	int keydate;
	char in[8] = "收入";
	char out[8] = "支出";

	if ((myfile.stream1 = fopen("../income.txt", "a+")) != NULL) 
	{
		printf("請選擇功能(1.輸入資料 2.查帳 3.列印全資料):");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: //輸入資料
		{
				while (choice1 != 3)
				  {
					  printf("1.收入 2.支出 3.離開:");
					  scanf("%d", &choice1);

					  if (choice1 != 3)
					  {
							printf("輸入日期:");
							 scanf("%d", &mybook.date);

						  printf("輸入金額:");
						  scanf("%d", &mybook.amount);

						  printf("輸入備註:");
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
						 printf("資料儲存完畢\n");
				};
		}
			fclose(myfile.stream1);
			break;
		case 2: //查帳
			printf("請輸入日期:");
			scanf("%d", &keydate);
			searchdata(keydate);
			break;
		case 3: //列印所有資料
			printdata(in , out);
			break;
		}

		
	}
	else
	{
		printf("檔案讀取失敗");//如果沒有讀到東西，顯示檔案讀取失敗
	}

	system("pause");
	return 0;
}

void searchdata(int keydate) //副程式:印出所查詢的帳
{
	myfile.stream1 = fopen("../income.txt", "r");
	int date, amount;
	char inout[8];
	char note[20];

	printf("  日期	      收支  	   金額	          備註\n");
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

void printdata(char in, char out) //副程式:印出帳本全部內容
{
	myfile.stream1 = fopen("../income.txt", "r");
	int date, amount;
	char inout[8]; 
	char note[20];

	printf("  日期	      收支  	   金額	          備註\n");
	printf("------------------------------------------------------\n");
	while ((fscanf(myfile.stream1, "%d%s%d%s", &date, &inout, &amount, &note)) != EOF)
	{	
		printf("%6d %9s %12d %14s\n", date, inout, amount, note);
	}
	fclose(myfile.stream1);
}