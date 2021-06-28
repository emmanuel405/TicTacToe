#include <iostream>
#include "tic.hpp"

using namespace std;

int main(){
    Plan p;
    bool win = false; int t = 0;
    while(!win){
        display(p);
        t++;
        if(t % 2) // == 1
            turn(FIRST, p);
        else
            turn(SECOND, p);
        
        if(t >= 5){ // Possibility to win
            if(checkWinner(t%2, p))
                win = true;
        }
    }
    if(t % 2) t = 1;
    else t = 2;
    cout << "Player " << t << "\nYOU WIN !!" << endl;

}



