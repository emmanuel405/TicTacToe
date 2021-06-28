#pragma once
#define FIRST 1
#define SECOND 2


class Plan{
    private:
        char board[3][3] = 
           {{'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}};
    
    public:

        char get(int row, int col){
            return board[row][col];                
        }
        void set(int row, int col, char choice){
            board[row][col] = choice;
        }
        
};

void display(Plan&);
void turn(int, Plan&);
bool inPlan(int&, int&);
void math(const int&, int&, int&);
bool checkWinner(int, Plan&);
bool isWin(Plan&, char);
