#ifndef FUN
#define FUN
#include"main.h"
void links(Board* b,P move);
int check(P a1,P a2,P b1,P b2);
int win(Board b);
int recursion(Board *b,P move,int check[24][24],int val);
void printlinks(Board b);
#endif