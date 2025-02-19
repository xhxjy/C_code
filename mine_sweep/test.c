#define _CRT_SECURE_NO_WARNINGS 1
//题目要求：做一个9*9的扫雷游戏

#include "game.h"
void menu()
{
	printf("*************************\n");
	printf("**********1.play*********\n");
	printf("**********0.exit*********\n");
	printf("*************************\n");
}

void game()
{
	//定义两个数组，分别存放布置雷和排查雷的信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化两个数组，没布置雷时，全为'0';没排查雷时,全为'*'

	//注意：不可在定义时将它们全部初始化，因为会很麻烦；若写为"char mine[ROWS][COLS] = { '0' }",
	//则只初始化了一个，是部分初始化
	//法1
	/*for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < COLS;j++)
		{
			mine[i][j] = '0';
			show[i][j] = '*';
		}
	}*/
	//法2（最好用函数来写，因为本文件是用来梳理游戏逻辑的；而此条语句与游戏内容有关，应写在其他文件中）
	//同一个函数通过添加一个参数来传入不同的内容
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//设置雷
	set_mine(mine, ROW, COL);

	//打印地图
	//display_board(mine, ROW, COL);//一般不打印雷的地图；当测试功能时可以打印，便于测试
	display_board(show, ROW, COL);

	//排查雷
	check_mine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点，srand函数在一次运行的程序中只要调用一次，无需多次调用，所以一般放在主函数的第一条语句即可
	int choice = 0;//别放循环内部会导致重复定义
	do
	{
		menu();
		printf("请输入你的选项:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重新输入！\n");
			break;//别省略，更保险
		}
	} while (choice);
	return 0;
}