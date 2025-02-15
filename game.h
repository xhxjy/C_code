#pragma once
#include <stdio.h>//写在这个文件的目的是：使引用它（game.h）的源文件都可以使用这些库函数，不用在那些源文件里再重复写
#include<stdlib.h>//srand
#include<time.h>//time

#define ROW 3
#define COL 3

//初始化棋盘
void init_board(char board[ROW][COL], int row, int col);//二维数组的传参，除了这种还可以将第一维省略，写成cahr board[][COL]
//里面的参数是有效的，要是常数

//打印棋盘
void display_board(char board[ROW][COL], int row, int col);

//玩家下棋
void player_move(char board[ROW][COL], int row, int col);

//电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

//判断输赢(当前对局状态)
//“玩家赢”->'*'
//“电脑赢”->'#'
//“平局”  ->'Q'
//“继续”  ->'C'
char judge_game(char board[ROW][COL], int row, int col);

//判断输赢中版本1中的函数
//判断平局还是继续（棋盘是否是满的）
//int is_full(char board[ROW][COL], int row, int col);
