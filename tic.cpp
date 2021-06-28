#include <iostream>
#include "tic.hpp"

using namespace std;

bool inPlan(int &number){
    if(number <= 0 || number > 9)
        return false;
    return true;
}

void turn(int num, Plan& p){
    int row, col ,cube;
    bool flag = true;
    cout << "Player number " << num << " - it's your turn" << endl;
    while(flag){
        cout << "Choose a cube:" << endl;
        cin >> cube;
        if(inPlan(cube)){
            math(cube, row, col);

            if('X' == p.get(row, col) || 'O' == p.get(row, col))
                cout << "The cube is full\nTry again" << endl;
            
            else{
                if(num == FIRST)
                    p.set(row, col, 'X');
                else
                    p.set(row, col, 'O');
                
                flag = false;
            }
        }
        else
            cout << "No, you are not in the plane\nTry again" << endl;
    }
}

void display(Plan &p){

    for(int i=0; i<2; i++){
        cout << p.get(i,0) << " | " << p.get(i,1) << " | " << p.get(i,2) << endl;
        cout << "-   -   -" << endl;
    }
    cout << p.get(2,0) << " | " << p.get(2,1) << " | " << p.get(2,2) << endl;
}

void math(const int& cube, int& row, int& col){
    switch(cube){
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
    }
    
}

bool checkWinner(int num, Plan& p){
    if(num == 1)
        return isWin(p, 'X');
    else
        return isWin(p, 'O');
}

bool isWin(Plan& p, char ch){
    // Rows
    for(int i=0; i<=2; i++){
        if(p.get(i,0) == p.get(i,1) && p.get(i,1) == p.get(i,2) 
            && p.get(i,2) == ch)
            return true;
    }
    // Cols
    for(int i=0; i<=2; i++){
        if(p.get(0,i) == p.get(1,i) && p.get(1,i) == p.get(2,i) 
            && p.get(2,i) == ch)
            return true;
    }
    // Diagonal
    if((p.get(0,0) == p.get(1,1) && p.get(1,1) == p.get(2,2) ||
        p.get(0,0) == p.get(1,1) && p.get(1,1) == p.get(2,2))
        && p.get(2,2) == ch)
        return true;

    return false;
}
