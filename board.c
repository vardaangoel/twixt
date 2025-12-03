#include"board.h"
Board create(Board b){
    
    for (int i=0;i<24;i++){
        for (int j=0;j<24;j++){
            b.board[i][j].player=Empty;
b.board[i][j].num=0;
        }
    }
b.current=Red;
b.count=0;
return b;
}

void print(Board b){char c='a';printf("  ");
    char d='A';
for (int i=0;i<26;i++){if (i==1||i==24){printf("  ");continue;}printf("%c ",c);c++;};printf("\n");
for (int i=0;i<24;i++){
    {printf("%c ",d);}
    // if (i==||i==24){printf("      -------------------------------------------     \n");continue;}
for (int j=0;j<24;j++){
char s='.';
if (b.board[i][j].player==Red){s='R';}
else if (b.board[i][j].player==Black){s='B';}
if ((j==0||j==22)&&i!=0&&i!=23){printf("%c | ",s);}
else if ((j==0||j==22)&&(i==0||i==23)){printf("%c   ",s);}
else printf("%c ",s);
}
    printf("%c \n",d);d++;if (i==0||i==22){printf("      -------------------------------------------     \n");}}
c='a';printf("  ");for (int i=0;i<26;i++){if (i==1||i==24){printf("  ");continue;}printf("%c ",c);c++;};printf("\n");
}


void rules(){
        printf("1.Input format: <Row><Column> eg 'Dc' inputs the peg at row 'D' column 'c'\n2. A new link is formed when 2 pegs of same player are a knight's move apart and no other already existing link intersects this link\n3. Player Red needs to connect row A to row X, Player Black needs to connect column a to column x\n4. You cannot place peg at the corners {Aa,Ax,Xa,Xx} or already occupied places\n5. Player Red cannot place peg in column 'a' and column 'x', Player Black cannot place peg in row 'A' and row 'X'\n6. Type 'rules' to see the rules\n7. Type 'resign' to resign from the game, opponent wins\n8. Type 'exit' to exit the app\n\n");
}