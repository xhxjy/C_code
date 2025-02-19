#pragma once
#include <stdio.h>
#include <stdlib.h>//srand
#include <time.h>//time

//定义9是因为我们实际存放的数据都在9*9的数组里
#define ROW 9
#define COL 9

//定义11是由于雷分布的特点，对于边界的雷我们不便排查，变成11*11的数组便于排查雷
#define ROWS ROW+2
#define COLS COL+2

#define mine_number 10//要测试相关功能时，雷数可以设置的多一些，便于测试

//初始化数组(11*11)
void init_board(char board[ROWS][COLS], int rows, int cols, char set);

//打印地图(9*9)
void display_board(char board[ROWS][COLS], int row, int col);
//不可写成board[ROW][COL],因为传的仍然是11*11的数组名，只是由于后面传的参数不同，而打印的是9*9

//设置雷
void set_mine(char board[ROWS][COLS], int row, int col);

//排查雷(有4个辅助函数)
void check_mine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);

//判断输赢
//int judge_game(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);


