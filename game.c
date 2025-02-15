#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//版本1（列数受限制，不方便）
//void display_board(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0;i < row;i++)
//	{
//		printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

//版本2(列数不受限制)
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		//分成两个循环，分别打印空格和分割符（两者打印方式相似）
		//1.打印内容（初始化时是空格）
		for (j = 0;j < col;j++)
		{
			//法1（更简洁）
			printf(" %c ", board[i][j]);
			if (j < col - 1)//防止右侧边界多出'|'
				printf("|");
			//法2
			//if (j < col - 1)
			//	printf(" %c |", board[i][j]);
			////防止右侧边界多出'|'
			//else
			//	printf(" %c \n", board[i][j]);
		}
		printf("\n");//打印完一行就换行

		//2.打印分割符
		if (i < row - 1)//防止底部边界多出'---'
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)//防止右侧边界多出'|'
					printf("|");
			}
			printf("\n");
		}
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	//a表示行，b表示列
	int a = 0;
	int b = 0;
	while (1)//考虑到可能需要重新输入的情况，设置一个死循环
	{
		printf("玩家下棋\n");//要分清是玩家下还是电脑下
		printf("请输入坐标：");
		scanf("%d %d", &a, &b);
		//检查坐标是否合法
		if (a >= 1 && a <= row && b >= 1 && b <= col)//坐标范围
		{
			//检查坐标是否被占用
			if (board[a - 1][b - 1] != ' ')
				printf("坐标被占用，请重新输入！\n");
			else
			{
				board[a - 1][b - 1] = '*';//减1是因为我们习惯是从1开始数，而数组的下标是从0开始的
				break;
			}
		}
		else
			printf("坐标非法，请重新输入！\n");
	}
}

//版本1（电脑太笨）
//void computer_move(char board[ROW][COL], int row, int col)
//{
//	//a表示行，b表示列
//	printf("电脑下棋\n");//要分清是玩家下还是电脑下，而且不要将其写入循环里，因为有可能需要重新输入，导致这句话多次打印
//	while (1)//考虑到可能需要重新输入的情况，设置一个死循环
//	{
//		int a = rand() % row;
//		int b = rand() % col;
//		//检查坐标是否被占用
//		if (board[a][b] == ' ')
//		{
//			board[a][b] = '#';//减1是因为我们习惯是从1开始数，而数组的下标是从0开始的
//			break;
//		}
//	}
//}

//版本2（电脑聪明）
void computer_move(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑下棋\n");
	//优先级1.下一步电脑是否能赢
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = '#';//找到空格，先模拟电脑一步一步试着下棋
				if ('#' == judge_game(board, ROW, COL))//判断上一步下的棋是否能让电脑赢
					return;//直接结束程序，return后面无需加其他符号，因为是void类型的函数，不能用break，因为break只能跳出当前循环，而我们的目的是要跳出整个函数（下面的break同理）
				else
					board[i][j] = ' ';//不可以赢就撤销上一步下的棋，继续循环找位置
			}
		}
	}
	//优先级2.下一步玩家是否能赢，阻止玩家
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = '*';//找到空格，先模拟玩家一步一步试着下棋
				if ('*' == judge_game(board, ROW, COL))//判断上一步下的棋是否能让玩家赢
				{
					board[i][j] = '#';//玩家可以赢时，电脑下到这个位置
					return;
				}
				else
					board[i][j] = ' ';//玩家不可以赢就撤销上一步下的棋，继续循环找位置
			}
		}
	}
	//优先级3.占领中心位置（易连成三子）
	if (board[row / 2][col / 2] == ' ')
	{
		board[row / 2][col / 2] = '#';
		return;
	}
	//优先级4.占领四个角落（易形成对角线）
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (i == j == 0 || i == j == row - 1 || (i == 0 && j == col - 1) || (j == 0 && i == row - 1))
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					return;//找到一个角落后直接跳出循环即可，无需再找下一个角落
				}
		}
	}
	//优先级5.随机下（保底策略）
	while (1)//考虑到可能需要重新输入的情况，设置一个死循环
	{
		i = rand() % row;
		j = rand() % col;
		//下标已在合法范围内，且刷新的是随机值，无需遍历
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';//有空格直接下
			break;//下完直接跳走即可
		}
	}
}


//版本1（格式固定，输入麻烦）
////判断棋盘是否满了的函数
////满了返回1
////不满返回0
//int is_full(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0;i < row;i++)
//	{
//		for (j = 0;j < col;j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;
//		}
//	}
//	return 1;
//}
//
//char judge_game(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	//判断输赢有三种情况
//	//1.对角线
//	for (j = 0;j < col;j++)
//	{
//		if (board[0][0]==board[1][1]&& board[1][1]== board[2][2]&& board[1][1]!=' ')// i == j
//		{
//			return board[1][1];
//		}
//		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')// i+j==2
//		{
//			return board[1][1];
//		}
//	}
//	//2.横线
//	for (i = 0;i < row;i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//		{
//			return board[i][1];
//		}
//	}
//	//3.竖线
//	for (j = 0;j < col;j++)
//	{
//		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
//		{
//			return board[0][j];
//		}
//	}
//	//暂时没人赢，判断是平局还是继续
//	//判断棋盘是否满了
//	if (1 == is_full(board, ROW, COL))
//	{
//		return 'Q';
//	}
//	else
//		return 'C';
//}

//版本2（格式灵活，代码简洁）
char judge_game(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int flag = 0;//判断三个棋子是否相同的一个标志变量
	//判断分3种情况
	//行
	for (i = 0;i < row;i++)
	{
		for (j = 0,flag=1;j < col - 1;j++)//flag初始化为1
		{
			if (board[i][j] != board[i][j + 1] || board[i][j] == ' ')//逆向思维判断对角线三个棋子是否相同且不为空格（正难则反）(下面类似的判断同理)
			{
				flag = 0;//表明有棋子不同或为空格
				break;//只要有一对棋子不同或为空格，就无需重复判断，直接跳出循环即可，这条语句可以i避免重复判断，提高效率
			}
		}
		//判断完某一行后再进行下一步判断，否则return的值也会不同
		if (flag)//对于逻辑变量(flag)取1和0有妙用
			return board[i][j];//返回'*'/'#'，对应自己设计的玩家/电脑赢的返回值（巧妙）
	}
	//列
	for (j = 0;j < col;j++)
	{
		for (i = 0, flag = 1;i < row - 1;i++)
		{
			if (board[i][j] != board[i + 1][j] || board[i][j] == ' ')
			{
				flag = 0;//(与下面的break有异曲同工之妙)
				break;
			}
		}
		//判断完某一列后再进行下一步判断（同上理）
		if (flag)
			return board[i][j];
	}
	//对角线(两种情况)（画图好理解）
	//1.斜向下类型（i==j）
	for (i = 0, j = 0;i < row - 1;i++, j++)//没必要再加上j<col-1,它俩的限制范围一样，且初始值又一样，一个变量就能限制住
	{
		if (board[i][j] != board[i + 1][j + 1] || board[i][j] == ' ')
			break;
		//这条语句不可放在循环外，因为在循环外有两种情况
		//1.i==row
		//2.i<=row,其中i==row的情况是三个棋子不同，显然不符合需求
		if (i == row - 2)//按顺序下来上面的语句已经帮我们判断了棋子是否符合需求，一不符合便会跳出去，所以这条语句放在循环内是符合逻辑的
			return board[i][j];
	}

	//2.斜向上类型（i+j==row-1）
	for (i = 0, j = col - 1;i < row - 1;i++, j--)//画图理解
	{
		if (board[i][j] != board[i + 1][j - 1] || board[i][j] == ' ')
			break;
		if (i == row - 2)
			return board[i][j];
	}

	//程序到这个位置时表明两者暂时未分出胜负，通过遍历整个数组来判断棋盘是否为满的，来判断对局状态是继续还是平局
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')//判断是否为满的，逆向思维找空的即空格
				return 'C';//有空格，便继续
		}
	}
	return 'Q';
}