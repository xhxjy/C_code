#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("*******************\n");
	printf("******1.play*******\n");
	printf("******0.exit*******\n");
	printf("*******************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//初始化棋盘（初始化数组全部为空格）
	init_board(board, ROW, COL);
	//打印棋盘
	display_board(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		player_move(board, ROW, COL);
		display_board(board, ROW, COL);

		//判断输赢
		ret = judge_game(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		computer_move(board, ROW, COL);
		display_board(board, ROW, COL);

		//判断输赢
		ret = judge_game(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢！\n");
	else if (ret == '#')
		printf("电脑赢！\n");
	else
		printf("平局\n");
}

int main()
{
	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int choice = 0;
	//while的方式
	/*menu();
	printf("请选择:");
	scanf("%d", &choice);
	while (choice)
	{
		switch ()
		{
			...
		}
	}*/
	do //用do...while是因为相较while排版更好看，代码可读性高，且更简洁
	{
		menu();
		printf("请选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");//没必要用exit(0)函数，因为输入0时，会跳出while循环，从而结束程序
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (choice);//将退出游戏的选项设置为0，是有妙用的
	//若设置为其他非0数，如2，则判断条件为choice != 2，更复杂
	return 0;
}