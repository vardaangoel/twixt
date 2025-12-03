#ifndef MAIN
#define MAIN
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum{Empty=0,
    Red=1,Black=2}Player;
typedef struct{
    int r;int c;
}P;
typedef struct{
    P p1,p2;Player player;}Link;
typedef struct{
    Player player;P links[8];
    int num;
}Peg;
typedef struct{
    Peg board[24][24];
    Player current;
    Link all_links[1200];
    int count;
}Board;
#endif