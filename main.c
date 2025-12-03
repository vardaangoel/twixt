
#include"fun.h"
#include"board.h"
int main(){
    int v=1;
    while(v){
   Board b;
    b=create(b);
    Player winner=Empty;
    printf("WELCOME TO TWIXT\nType 'rules' to see the rules.\n");
    char n[10];
    while (1){
    scanf("%9s",n);
    if (strcmp(n,"rules")==0) {rules();printf("Type 'start' to start the game\n");}
    else if (strcmp(n,"start")==0) break;
        else if (strcmp(n,"exit")==0){printf("Exiting app...");return 0;}
        else {printf("Invalid input, try again\n");}}
    print(b);
    int t=1;
    while(t){
        P move;
        printf("Player %s's turn:\n",(b.current==Red)?"Red":"Black");
        char c[10];
        scanf(" %9s",c);
        if (strcmp(c,"rules")==0){rules();continue;}
        else if (strcmp(c,"resign")==0){winner=b.current==Red?Black:Red;break;}
       else if (strcmp(c,"exit")==0){printf("Exiting app...\n");return 0;}
       else if (strlen(c)!=2){printf("Invalid input, try again\n");continue;}
       
        c[2]='\0';
        move.r=c[0]-'A';
        move.c=c[1]-'a';
                    
            if (strcmp(c,"Aa")==0||strcmp(c,"Ax")==0||strcmp(c,"Xa")==0||strcmp(c,"Xx")==0) {printf("Cannot place at the corners, try again\n");continue;}
            if (c[0]<'A'||c[0]>'X'||c[1]<'a'||c[1]>'x') {printf("Invalid input, try again\n");continue;}
        if ((((c[1]=='a')||c[1]=='x')&&b.current==Red)||(((c[0]=='A')||c[0]=='X')&&b.current==Black)) {printf("Cannot place in Opposite Player's area, try again\n");continue;}
        else{if (b.board[move.r][move.c].player!=Empty){printf("Place already occupied, try again\n");continue;}
       b.board[move.r][move.c].player=(b.current==Red)?Red:Black;}
      print(b);links(&b,move);printlinks(b);
     if (win(b)==1){winner=b.current;t=0;}
       
          else {b.current=(b.current==Red)?Black:Red;}}
        
    
        if (winner!=Empty) 
        
        {printf("\n**GAME OVER**\nPLAYER %s WINS!!\n\nType 'new' to start a new game\nType anything else to exit the app\n",winner==Red?"RED":"BLACK");}
      
        scanf(" %9s",n);
        if (strcmp(n,"new")!=0){printf("Exiting app...\n");v=0;}}
          return 0;
}