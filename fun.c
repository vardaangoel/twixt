#include "fun.h"

void links(Board* b,P move){
    int knight[2][8]={{2,2,1,1,-1,-1,-2,-2},{1,-1,2,-2,2,-2,1,-1}};
    for (int i=0;i<8;i++){
        P link={move.r+knight[0][i],move.c+knight[1][i]};
        if (link.r<0||link.r>23||link.c<0||link.c>23) continue;
        if (b->board[link.r][link.c].player!=b->current) continue;
    int flag=0;
       for (int j=0;j<b->count;j++){
        Link temp=b->all_links[j];
        if (check(move,link,temp.p1,temp.p2)){flag=1;break;}
       }
            if (flag==0){
                Peg p1=b->board[move.r][move.c];
                Peg p2=b->board[link.r][link.c];
               p1.links[p1.num++]=link;
               p2.links[p2.num++]=move;
               b->board[move.r][move.c]=p1;
               b->board[link.r][link.c]=p2;
               Link new={move,link,b->current};
               printf("*NEW LINK*:- %s:%c%c--%c%c\n",b->current==Red?"Red":"Black",'A'+move.r,'a'+move.c,'A'+link.r,'a'+link.c);
               b->all_links[b->count++]=new;
            }       
                }return;
            }
    

int check(P a1,P a2,P b1,P b2){
int A=a1.r-a2.r;
int B=a2.c-a1.c;
int C=-A*a1.c-B*a1.r;
int first=A*b1.c+B*b1.r+C;
int second=A*b2.c+B*b2.r+C;
if (first*second>=0) return 0;
A=b1.r-b2.r;
B=b2.c-b1.c;
C=-A*b1.c-B*b1.r;
first=A*a1.c+B*a1.r+C;
second=A*a2.c+B*a2.r+C;
if (first*second>=0) return 0;
return 1;
}
int win(Board b){
    int checked[24][24]={0};
    Player p=b.current;
    if (p==Red){for (int i=1;i<23;i++){
        if (b.board[0][i].player==Red){P t={0,i};if (recursion(&b,t,checked,0)) return 1;}
    }}
    if (p==Black){for (int i=1;i<23;i++){
        if (b.board[i][0].player==Black){P t={i,0};if (recursion(&b,t,checked,1)) return 1;}
    }}
    return 0;
}
int recursion(Board *b,P move,int checked[24][24],int val){
    checked[move.r][move.c]=1;
    if (val==0){
        if (move.r==23)return 1;}
        else {if (move.c==23)return 1;}
        Peg t=b->board[move.r][move.c];
        for (int i=0;i<t.num;i++){
P next=t.links[i];
if (checked[next.r][next.c]==0){if (recursion(b,next,checked,val)==1)return 1;}
        }
        return 0;
    }
void printlinks(Board b){
    printf("ALL LINKS:\n");
    printf("RED: ");
    for (int i=0;i<24;i++){
        for (int j=0;j<24;j++){
            Peg temp=b.board[i][j];
            if (temp.player==Red){for (int k=0;k<temp.num;k++){
                P link=temp.links[k];
                if (i<link.r||(i==link.r&&j<link.c)){
                    printf("%c%c--%c%c  ",'A'+i,'a'+j,'A'+link.r,'a'+link.c);
                }
            }}
        }
        
    } printf("\n");printf("BLACK: ");for (int i=0;i<24;i++){
        for (int j=0;j<24;j++){
            Peg temp=b.board[i][j];
            if (temp.player==Black){for (int k=0;k<temp.num;k++){
                P link=temp.links[k];
                if (i<link.r||(i==link.r&&j<link.c)){
                    printf("%c%c--%c%c  ",'A'+i,'a'+j,'A'+link.r,'a'+link.c);
                }
            }}
        }
    }printf("\n");
}
