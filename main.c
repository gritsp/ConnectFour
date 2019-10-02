#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//สร้างตาราง 7*6
char *board[][7] = {
    {"1","2","3","4","5","6","7"},
    {" "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "},
    {" "," "," "," "," "," "," "}
};

//ฟังค์ชั่นสำหรับเพิ่มค่าลงตาราง
void play(int n,int turn, char *board[][7]){
    int i;
    for ( i = 6; i >= 0; i--){  //วนลูปหาหลัก
        if (board[i][n]==" "){  //ค่า n เป็นตัวเลือกแถว
            if(turn == 1) {     //เช็คว่าเป็นเทรินของใคร
                board[i][n] ="X";
            }
            else
            {
                board[i][n] ="O";
            }
            
            break;
        }
    }
}
//ฟังคฺชั่นล้างตาราง
void clearboard(char *board[][7]){
    int i,j;
    for (i = 1; i<=7;i++){
        for(j = 0; j<=6;j++){
            board[i][j] = " ";
        }
    }
}

//ฟังค์ชั่นวาดตาราง
void draw(char *board[][7]){
    system("@cls || clear");    //เคลียร์หน้าจอ
    int i;
    for ( i = 0; i <= 6; i++)   //วนลูปหาหลัก
    {
        int j;
        for ( j = 0; j <= 6; j++){  //วนลูปหาแถว
            printf("| %s ",board[i][j]);
        }
        printf("|\n-----------------------------\n");
    }
    
}

//เช็คเงื่อนไขการชนะ
bool checkWin(char *board[][7]){
    int i;
    for (i = 0; i < 7; i++){
        int j;
        for (j=0;j < 7;j++){
            //player 1
            //เช็คแนวตั้ง
            if (board[i][j] == "X" && board[i][j+1] == "X" && board[i][j+2] == "X" && board[i][j+3] == "X" && j<4){
                return true;
            }
            //เช็คแนวนนอน
            if (board[i][j] == "X" && board[i+1][j] == "X" && board[i+2][j] == "X" && board[i+3][j] == "X" && i<4)
            {
                return true;
            }
            //เช็คแนวทแยงลงขวา
            if (board[i][j] == "X" && board[i+1][j+1] == "X" && board[i+2][j+2] == "X" && board[i+3][j+3] == "X" && i<4&&j<4){
                return true;
            }
            //เช็คแนวทแยงลงซ้าย
            if (board[i][j] == "X" && board[i+1][j-1] == "X" && board[i+2][j-2] == "X" && board[i+3][j-3] == "X" && i<4&&j>3){
                return true;
            }
            
            //player 2
            //เช็คแนวตั้ง
            if (board[i][j] == "O" && board[i][j+1] == "O" && board[i][j+2] == "O" && board[i][j+3] == "O" && j<4){
                return true;
            }
            //เช็คแนวนอน
            if (board[i][j] == "O" && board[i+1][j] == "O" && board[i+2][j] == "O" && board[i+3][j] == "O" && i<4)
            {
                return true;
            }
            //เช็คแนวทแยงลงขวา
            if (board[i][j] == "O" && board[i+1][j+1] == "O" && board[i+2][j+2] == "O" && board[i+3][j+3] == "O" && i<4&&j<4){
                return true;
            }
            //เช็คแนวทแยงลงซ้าย
            if (board[i][j] == "O" && board[i+1][j-1] == "O" && board[i+2][j-2] == "O" && board[i+3][j-3] == "O"&& i<4&&j>3){
                return true;
            }
        }
    }
    return false;
}

void randomBlock(char *board[][7],int num){
    int i,x,y;
    
    srand(time(NULL));
    for (i = 0; i<num; i++){
        
        x = rand() %6 + 1;
        y = rand() %6 + 1;
        board[y][x] = "B";
    }
}

//แสดงข้อความต้อนรับ
void wellcome(){
    printf("     Wellcome to CONNECT 4\n\n");
    printf("         How to play\n");
    printf("1. Swap player to choose coin to put in colum (1-7)\n");
    printf("2. Coin will put form bottom to top\n");
    printf("3. Who can arrange 4 coin wil is winer\n\n");

    //getch();
}

int main(){
    char player1Name[50],player2Name[50];
    int numBlock;
    wellcome();     //เรียกใช้ฟังค์ชั่นแสดงข้อความต้อนรับ
    printf("Insert Player 1 name\n>");
    scanf("%s",player1Name);
    printf("Insert Player 2 name\n>");
    scanf("%s",player2Name);
    printf("Intert number of Block 1 to 42\n>");
    scanf("%d",&numBlock);
    printf("Wellcome %s and %s to Connect 4\n",player1Name,player2Name);
    getch();
    randomBlock(board,numBlock);
    draw(board);    //เรียกใช้ฟังค์ชั่นวาดตารา
    int turn =1;    //ตั้งให้เป็นเทรินของผู้เล่นคนที่ 1
    while (true)    //ลูปมี่วนจนกว่าจะมีคนชนะ
    {
        int n;                  //ตัวแปรสำหรับรับค่าแถวที่ป้อน
        printf("> ");
        scanf("%d",&n);
        while (n<1 || n>7)      //ลูปเพื่อเช็คว่าป้อนค่าที่ไม่ใช่ 1-7
        {
            printf("Please insert number 1-7\n> ");
            scanf("%d",&n);
        }
        n = n-1;                //ลดค่า n ลงเพื่อให้เริ่ม index ที่ถูกต้องของอาเรย์
        
        play(n,turn,board);     //เรียกใช้ฟังค์ชั่นเพิ่มค่าลงตาราง
        draw(board);            //วากตาราง
        bool check = checkWin(board);   //เช็คหาผู้ชนะ
        if (check == true){     //แสดงว่าใครเป็นผู้ชนะ
            if (turn == 1){
                printf("%s is Winner",player1Name);                                  
            }
            else
            {
                printf("%s is Winner",player2Name);                
            }
            printf("Play agian? Enter [Y/N]\n");
            char ch;
            scanf(" %c",&ch);
            if (ch == 'Y')
            {
                clearboard(board);
                randomBlock(board,numBlock);
                draw(board);
            }
            else
            {
                break;
            }
            //break;  // เมื่อมีผู้ชนะจะสั่งหยุดการวนลูป
        }
        if(turn == 1){  //สลับเทรินของผู้เล่น
            turn = 2;
        }
        else
        {
            turn = 1;
        }
    }

    return 0;
}