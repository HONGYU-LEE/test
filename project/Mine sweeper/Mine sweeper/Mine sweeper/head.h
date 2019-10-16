#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS 11
#define COLS 11

#define BOOMNUM 10
#define SAFENUM ROW*COL-BOOMNUM

void GameMenu();

void InitBoard(char Board[ROWS][COLS], int row, int col, char ch);

void SetBoom(char Boom[ROWS][COLS], int row, int col);

void ShowBoard(char Board[ROWS][COLS], int row, int col);

int BombsAround(char Boom[ROWS][COLS], int row, int col);

char FindBoom(char Board[ROWS][COLS], char Boom[ROWS][COLS], int row, int col);

void Game(char Board[ROWS][COLS], char Boom[ROWS][COLS], int row, int col);
