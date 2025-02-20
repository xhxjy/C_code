#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;//通过设置传入的set不同，实现两个数组不同内容的初始化
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	system("cls");//实时清理以往的打印记录，防止游戏界面过于冗长
	int i = 0;
	int j = 0;
	printf("-------------扫雷游戏-------------\n");
	for (j = 0;j <= col;j++)
		printf("%d ", j);//标明列数
	printf("\n");
	for (i = 1;i <= row;i++)//注意下标是1~9（下面的列同理）
	{
		printf("%d ", i);//标明行数
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);//打印内容(是行和列下标都为1~9,而不是0~8；因为传的是11*11的数组)（下面布置雷位置的同理）
		}
		printf("\n");
	}
	printf("-------------扫雷游戏-------------\n");
}

void set_mine(char board[ROWS][COLS], int row, int col)
{
	int num = mine_number;
	while(num)
	{
		//布置一个雷
		int i = rand() % row + 1;//下标为1~9，而不是0~8
		int j = rand() % col + 1;
		if (board[i][j] == '0')//检查位置上是否有雷
		{
			board[i][j] = '1';
			num--;
		}
	}
}

//以下函数是排查函数中用到的辅助函数

//1.统计周围周围坐标有几个雷
char get_mine_count(char mine[ROWS][COLS], int i, int j)
{
	//将周围8个逐个加起来
	/*return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8 * '0';*/
		//法2.用for循环遍历整个九宫格（便于理解）
	int a = 0;
	int b = 0;
	int count = 0;
	for (a = i - 1;a <= i + 1;a++)
	{
		for (b = j - 1;b <= j + 1;b++)
		{
			if (mine[a][b] == '1')
			{
				count++;
			}
		}
	}
	return count + '0';//将整型数字转换成数字字符
}

//2.标记函数
void mark_mine(char show[ROWS][COLS], int row, int col)
{
	printf("是否对坐标进行标记(y/n)：");
	//清理缓存区（输入1（play）后有回车，需要将其挡住；否则回车会被下面的ch接收到，从而跳出本函数，直接走到下一条语句）
	int a = 0;
	while ((a = getchar()) != '\n')
	{
		;
	}
	//进行选择
	char ch = 0;
	scanf("%c", &ch);//回车会被字符变量接受，不会被整型变量接受所以下面的scanf(%d)前面无需清理缓冲区
	//标记
	if ('y' == ch)
	{
		while (1)//防止因为失误将空格和数字字符标记为雷而导致出现需要重新标记的情况
		{
			int i = 0;
			int j = 0;
			printf("请输入要标记/取消标记的坐标:");
			scanf("%d%d", &i, &j);
			//取消雷的标记
			if (show[i][j] == '#')
			{
				show[i][j] = '*';
				printf("取消标记成功！\n");
				break;
			}
			//标记为雷
			else if (show[i][j] == '*')
			{
				show[i][j] = '#';
				printf("标记成功！\n");
				break;
			}
			else
				printf("此处不可标记！请重新输入坐标！\n");
		}
		display_board(show, row, col);//标记/取消完需要将结果打印出来
	}
}

//3.展开函数
void expand_board(char show[ROWS][COLS], char mine[ROWS][COLS], int i, int j)
{
	char ret = get_mine_count(mine, i, j);
	if ('0' == ret)
	{
		show[i][j] = ' ';
		int a = 0;
		int b = 0;
		for (a = i - 1;a <= i + 1;a++)
		{
			for (b = j - 1;b <= j + 1;b++)
			{
				if (show[a][b] == '*' && a >= 1 && a <= ROW && b >= 1 && b <= COL)//确保该位置未被展开且坐标在展示范围内
					expand_board(show, mine, a, b);
			}
		}
	}
	else
		show[i][j] = ret;//记录周围雷的个数
}

//4.判断排雷是否成功
int is_end(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = row * col - mine_number;
	for (i = 1;i <= row;i++)
	{
		for (j = 1;j <= col;j++)
		{
			if (mine[i][j] == '0' && show[i][j] != '*')
				count--;//使它结束时返回刚好为0，便于它作为下面判断条件的书写
		}
	}
	return count;
}

void check_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int begin = clock();
	//time_t begin = time(NULL);//记录开始时间（法2）
	int i = 0;
	int j = 0;
	while (is_end(show, mine, row, col))
	{
		mark_mine(show, row, col);//标记的函数，不要放在排查中，否则会导致逻辑错误
		//清理缓存区（防止玩家在标记函数的选择中输入错误，导致对下面输入排查坐标造成影响。如在做选择时误输入为坐标，导致输入的排查坐标错误）
		int a = 0;
		while ((a = getchar()) != '\n')
		{
			;
		}
		printf("请输入你要排查的坐标：");
		scanf("%d%d", &i, &j);
		//合法坐标
		if (i >= 1 && i <= row && j >= 1 && j <= col)
		{
			//已被排查过
			if (show[i][j] != '*')
			{
				printf("输入坐标重复，请重新输入！\n");
			}
			//未被排查过
			else
			{
				//排到雷
				if (mine[i][j] == '1')
				{
					display_board(mine, row, col);//打印剩下雷的分布（需要放在以下语句前面，否则会将下面的语句清空）（下面打印同理）
					printf("很遗憾，你踩到雷了！\n");
					return;//需要结束此程序，因为返回类型为void，所以直接return结束(break也可以)
				}
				//不是雷
				else if (mine[i][j] == '0')
				{
					expand_board(show, mine, i, j);//两个功能：展开一片；记录坐标周围雷的个数
					display_board(show, row, col);//打印当前局势
				}
			}
		}
		//非法坐标
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
	if (0 == is_end(show, mine, row, col))
	{
		display_board(mine, row, col);//打印雷的分布
		int end = clock();
		//time_t end = time(NULL);//记录结束时间(法2)
		int data = end - begin;//统计游戏时间
		printf("恭喜你，排雷成功！用时%d ms\n", data);//clock()算的是ms,法2算的是s
	}
}