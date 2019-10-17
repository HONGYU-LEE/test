#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define BOMBSNUM 10


void GameMenu();

void InitBoard(char Board[ROWS][COLS], int row, int col, char ch);

void SetBombs(char Bombs[ROWS][COLS], int row, int col, int Bombsnum);

void ShowBoard(char Board[ROWS][COLS], int row, int col);

int BombsAround(char Bombs[ROWS][COLS], int row, int col);

char FindBombs(char Board[ROWS][COLS], char Bombs[ROWS][COLS], int row, int col);

void Game(char Board[ROWS][COLS], char Bombs[ROWS][COLS], int row, int col);

void MoveBomb(char Bombs[ROWS][COLS], int row, int col);

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);

void SafeArea(char Board[ROWS][COLS], char Bombs[ROWS][COLS], int row, int col);