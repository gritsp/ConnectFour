#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

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
    for (i = 0; i <=6; i++){
        int j;
        for (j=0;j<=6;j++){
            //player 1
            //เช็คแนวตั้ง
            if (board[i][j] == "X" && board[i][j+1] == "X" && board[i][j+2] == "X" && board[i][j+3] == "X"){
                return true;
            }
            //เช็คแนวนนอน
            if (board[i][j] == "X" && board[i+1][j] == "X" && board[i+2][j] == "X" && board[i+3][j] == "X")
            {
                return true;
            }
            //เช็คแนวทแยงลงขวา
            if (board[i][j] == "X" && board[i+1][j+1] == "X" && board[i+2][j+2] == "X" && board[i+3][j+3] == "X"){
                return true;
            }
            //เช็คแนวทแยงลงซ้าย
            if (board[i][j] == "X" && board[i+1][j-1] == "X" && board[i+2][j-2] == "X" && board[i+3][j-3] == "X"){
                return true;
            }
            
            //player 2
            //เช็คแนวตั้ง
            if (board[i][j] == "O" && board[i][j+1] == "O" && board[i][j+2] == "O" && board[i][j+3] == "O"){
                return true;
            }
            //เช็คแนวนอน
            if (board[i][j] == "O" && board[i+1][j] == "O" && board[i+2][j] == "O" && board[i+3][j] == "O")
            {
                return true;
            }
            //เช็คแนวทแยงลงขวา
            if (board[i][j] == "O" && board[i+1][j+1] == "O" && board[i+2][j+2] == "O" && board[i+3][j+3] == "O"){
                return true;
            }
            //เช็คแนวทแยงลงซ้าย
            if (board[i][j] == "O" && board[i+1][j-1] == "O" && board[i+2][j-2] == "O" && board[i+3][j-3] == "O"){
                return true;
            }
        }
    }
    return false;
}

//แสดงข้อความต้อนรับ
void wellcome(){
    printf("     Wellcome to CONNECT 4\n\n");
    printf("         How to play\n");
    printf("1. Insert number of collum 1-7 to put X or O\n");
    printf("2. It will insert bottom to top\n");
    printf("3. If X or O adjacent 4 is Winner!!!\n");
    getch();
}

int main(){
    wellcome();     //เรียกใช้ฟังค์ชั่นแสดงข้อความต้อนรับ
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
                printf("X is Winner");
            }
            else
            {
                printf("O is Winner");
            }
            
            break;  // เมื่อมีผู้ชนะจะสั่งหยุดการวนลูป
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