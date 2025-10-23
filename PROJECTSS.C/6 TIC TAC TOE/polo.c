 #include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 3

typedef struct{
    int player;
    int computer;
    int draw;
}Score;
Score score={.player=0, .computer=0, .draw=0};

int difficulty;// we make this globalyy as it will be used bw two modes

void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_winner(char board [BOARD_SIZE][BOARD_SIZE],char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move_difficulty_1(char board[BOARD_SIZE][BOARD_SIZE]);
int is_not_valid_move(char board[BOARD_SIZE][BOARD_SIZE],int row,int col);
int computer_check_immediate_win(char board[BOARD_SIZE][BOARD_SIZE]);
int computer_check_immediate_block(char board[BOARD_SIZE][BOARD_SIZE]); 
void computer_check_play_anywhere(char board[BOARD_SIZE][BOARD_SIZE]);
int computer_centre_play(char board[BOARD_SIZE][BOARD_SIZE]);
int computer_corner_play(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move_difficulty_2(char board[BOARD_SIZE][BOARD_SIZE]);


int main(){
    input_difficulty();
    while(1){
        int choice;
        play_game();
        printf("\nPlay again? (1 for yes, 0 for no): ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\n ok");
        }
        else if(choice==0){
            printf("\nThank you for playing our game..");
            return 0;
        }
        else{
            printf("\nPlease enter b/w (1/0)!!!");
        }
    }
}
void input_difficulty(){
    while(1){
        printf("Select difficulty level:\n");
        printf("1-Human (Standard)\n");
        printf("2-God(Impossible to win)\n");
        printf("Enter your choice: ");
        scanf("%d",&difficulty);
        
        if(difficulty!=1 && difficulty!=2){
            printf("\nIncorrect choice enter (1/2)!!\n\n");
        }
        else{
            break;
        }
    }
    
}
void clear_screen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
void print_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("Score- player X: %d, Computer: %d, Draws: %d",score.player,score.computer,score.draw);
    printf("\nTic Tac Toe\n");
    for(int row=0;row< BOARD_SIZE;row++){
        for(int coloumn =0;coloumn< BOARD_SIZE;coloumn++){
            printf(" %c ",board[row][coloumn]);
            if(coloumn< BOARD_SIZE-1){
                printf("|");
            }
        }
        printf("\n");
        if(row< BOARD_SIZE-1){
            printf("---+---+---\n");
        }
    }
}
int check_winner(char board[BOARD_SIZE][BOARD_SIZE],char player){
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            clear_screen();
            return 1;
        }
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            clear_screen();
            return 1;
        }
    }
    if((board[0][0]==player && board[1][1]==player && board[2][2]==player )
    || ( board[2][0]==player && board[1][1]==player && board[0][2]==player )){
        clear_screen();
        return 1;
    }
    return 0;
}
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int row=0;row<BOARD_SIZE;row++){
        for(int coloumn=0;coloumn<BOARD_SIZE;coloumn++){
            if(board[row][coloumn]==' '){
                return 0;
            }
        }
    }
    return 1;
}
void play_game(){
    char board[BOARD_SIZE][BOARD_SIZE]={
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    srand(time(0));
    char current_player= rand() % 2==0  ? 'X' : 'O';

    
    while(1){
        clear_screen();
        print_board(board);
        
        
        if(current_player=='X'){
            player_move(board);
            if(check_winner(board,'X')){
                score.player++;
                print_board(board);
                printf("\nCongrtulation You have won");
                break;
            }
            current_player='O';
        }
        if(difficulty==1){
            computer_move_difficulty_1(board);
            if(check_winner(board,'O')){
                score.computer++;
                print_board(board);
                printf("\nI won !!! Try hard..");
                break;
            }
        }
        else if(difficulty==2){
            computer_move_difficulty_2(board);
            if(check_winner(board,'O')){
                score.computer++;
                print_board(board);
                printf("\nI won !!! Try hard..");
                break;
            }
        }
        if(check_draw(board)){
            score.draw++;
            print_board(board);
            printf("\nIt's a draw!");
            break;
        }
        current_player='X';
    }
    
    
}
int is_not_valid_move(char board[BOARD_SIZE][BOARD_SIZE],int row,int col){
    if(row<0 || col<0 ||
        row>3 || col>3||
        board[row][col]!=' '){
            printf("\nPlease enter b/w (1-3)");
            return 1;
        }
        else{
            return 0;
        }
        
        
    }
    void player_move(char board[BOARD_SIZE][BOARD_SIZE]){
        int row,col;
        do{
            printf("\nPlayer X's turn.");
            printf("\nEnter row and column (1-3) for X's: ");
            scanf("%d %d",&row,&col);    
            row--,col--;  
        }while(is_not_valid_move(board,row,col));
        board[row][col]= 'X';
}
void  computer_move_difficulty_1(char board[BOARD_SIZE][BOARD_SIZE]){
    if(computer_check_immediate_win(board)==1){
         
        
    }
    else if(computer_check_immediate_block(board)==1){
        
    }
    else{
        computer_check_play_anywhere(board);
         
    }
}
int computer_check_immediate_win(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0;i<BOARD_SIZE;i++){
                if(board[0][i]=='O'&& board[1][i]=='O' && board[2][i]==' '){
                    board[2][i]='O';
                    return 1;
                    break;
                }
                else if(board[0][i]=='O'&& board[2][i]=='O' && board[1][i]==' '){
                    board[1][i]='O';
                    return 1;
                    break;
                }
                else if(board[1][i]=='O'&& board[2][i]=='O' && board[0][i]==' '){
                    board[0][i]='O';
                    return 1;
                    break;
                }
                if(board[i][0]=='O'&& board[i][1]=='O' && board[i][2]==' '){
                    board[i][2]='O';
                    return 1;
                    break;
                }
                else if(board[i][0]=='O'&& board[i][2]=='O' && board[i][1]==' '){
                    board[i][1]='O';
                    return 1;
                    break;
                }
                else if(board[i][1]=='O'&& board[i][2]=='O' && board[i][0]==' '){
                    board[i][0]='O';
                    return 1;
                    break;
                }
            }
            if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]==' '){
                board[2][2]='O';
                return 1;
            }
            else if(board[0][0]=='O' && board[2][2]=='O' && board[1][1]==' '){
                board[1][1]='O';
                return 1;
            }
            else if(board[1][1]=='O' && board[2][2]=='O' && board[0][0]==' '){
                board[0][0]='O';
                return 1;
            }
            if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]==' '){
                board[2][0]='O';
                return 1;
            }
            else if(board[0][2]=='O' && board[2][0]=='O' && board[1][1]==' '){
                board[1][1]='O';
                return 1;
            }
            else if(board[1][1]=='O' && board[2][0]=='O' && board[0][2]==' '){
                board[0][2]='O';
                return 1;
            }
            else{

                return 0;    
            }
}
int computer_check_immediate_block(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i=0;i<BOARD_SIZE;i++){
                if(board[0][i]=='X'&& board[1][i]=='X' && board[2][i]==' '){
                    board[2][i]='O';
                    return 1;
                    break;
                    
                }
                else if(board[0][i]=='X'&& board[2][i]=='X' && board[1][i]==' '){
                    board[1][i]='O';
                    return 1;
                    break;
                }
                else if(board[1][i]=='X'&& board[2][i]=='X' && board[0][i]==' '){
                    board[0][i]='O';
                    return 1;
                    break;
                }
                if(board[i][0]=='X'&& board[i][1]=='X' && board[i][2]==' '){
                    board[i][2]='O';
                    return 1;
                    break;
                }
                else if(board[i][0]=='X'&& board[i][2]=='X' && board[i][1]==' '){
                    board[i][1]='O';
                    return 1;
                    break;
                }
                else if(board[i][1]=='X'&& board[i][2]=='X' && board[i][0]==' '){
                    board[i][0]='O';
                    return 1;
                    break;
                }
            }
            if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]==' '){
                board[2][2]='O';
                return 1;
                
            }
            else if(board[0][0]=='X' && board[2][2]=='X' && board[1][1]==' '){
                board[1][1]='O';
                return 1;
                
            }
            else if(board[1][1]=='X' && board[2][2]=='X' && board[0][0]==' '){
                board[0][0]='O';
                return 1;
            }
            if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]==' '){
                board[2][0]='O';
                return 1;
            }
            else if(board[0][2]=='X' && board[2][0]=='X' && board[1][1]==' '){
                board[1][1]='O';
                return 1;
            }
            else if(board[1][1]=='X' && board[2][0]=='X' && board[0][2]==' '){
                board[0][2]='O';
                return 1;
            }
            else{

                return 0;
            }
}
void computer_check_play_anywhere(char board[BOARD_SIZE][BOARD_SIZE]){
    srand(time(0));
    while(1){
        int row=rand()%3;
        int col=rand()%3;
        if(board[row][col]==' '){
            board[row][col]='O';
            return 0;
        }

    }
}
int computer_centre_play(char board[BOARD_SIZE][BOARD_SIZE]){
    if(board[1][1]==' '){
        board[1][1]='O';
        return 1;
    }
    else{
        return 0;
    }
}
int computer_corner_play(char board[BOARD_SIZE][BOARD_SIZE]){
    if(board[0][0]==' '){
        board[0][0]='O';
         return 1;
    }
    else if(board[0][2]==' '){
            board[0][2]='O';
            return 1;
        }
    else if(board[2][0]==' '){
            board[2][0]='O';
            return 1;
        }
    else if(board[2][2]==' '){
            board[2][2]='O';
            return 1;
        }
    else{
        return 0;
    }
}
void computer_move_difficulty_2(char board[BOARD_SIZE][BOARD_SIZE]){
    if(computer_check_immediate_win(board)==1){
        
    }
    else if(computer_check_immediate_block(board)==1){
       
    }
    else if(computer_centre_play(board)==1){

    }
    else if(computer_corner_play(board)==1){

    }
    else{
        computer_check_play_anywhere(board);
    }
}