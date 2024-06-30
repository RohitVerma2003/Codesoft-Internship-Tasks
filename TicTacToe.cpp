#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool win(vector<char>& board , bool player1){
    bool isWin = false;
    if(board[0] != ' ' && !isWin){
        if(board[0] == board[1] && board[0] == board[2]) isWin = true;
        if(board[0] == board[3] && board[0] == board[6]) isWin = true;
        if(board[0] == board[4] && board[0] == board[8]) isWin = true;
    }

    if(board[3] != ' ' && !isWin){
        if(board[3] == board[4] && board[3] == board[5]) isWin = true;
    }

    if(board[1] != ' ' && !isWin){
        if(board[1] == board[4] && board[1] == board[6]) isWin = true;
    }

    if(board[2] != ' ' && !isWin){
        if(board[2] == board[4] && board[2] == board[6]) isWin = true;
    }

    if(board[8] != ' ' && !isWin){
        if(board[8] == board[7] && board[8] == board[6]) isWin = true;
        if(board[8] == board[5] && board[8] == board[2]) isWin = true;
    }

    if(isWin){
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
        cout<<"The Winner Is ";
        if(player1) cout<<"Player 1"<<endl;
        else cout<<"Player 2"<<endl;
        cout<<endl;
        return true;
    }

    return false;
}

bool draw(vector<char>& board , bool player1){
    bool isDraw = true;

    for(auto ele : board){
        if(ele == ' ') isDraw = false;
    }

    if(isDraw){
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
        cout<<"The Game Is Draw"<<endl;
        cout<<endl;
        return true;
    }

    return false;
}

int main(){
    bool player1 = true;
    vector<char> board(9 , ' ');

    cout<<endl;
    cout<<"----- Welcome To Tic Tac Toe -----"<<endl;
    cout<<endl;

    cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"                  "<<1<<" | "<<2<<" | "<<3<<endl;
    cout<<"---"<<" "<<"---"<<" "<<"---"<<"                "<<"---"<<" "<<"---"<<" "<<"---"<<endl;
    cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"                  "<<4<<" | "<<5<<" | "<<6<<endl;
    cout<<"---"<<" "<<"---"<<" "<<"---"<<"                "<<"---"<<" "<<"---"<<" "<<"---"<<endl;
    cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<"                  "<<7<<" | "<<8<<" | "<<9<<endl;
    cout<<endl;

    do
    {
        cout<<"----------------------------------------"<<endl;
        cout<<endl;
        if(player1) cout<<"Player 1 Turn : ";
        else cout<<"Player 2 Turn : ";

        int choice;
        cin>>choice;

        if (cin.fail() || choice < 1 || choice > 9 || board[choice - 1] != ' ')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << endl << "---- InValid Choice ----" << endl;
            continue;
        }

        board[choice - 1] = player1 ? 'X' : 'O';

        cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"                  "<<1<<" | "<<2<<" | "<<3<<endl;
        cout<<"---"<<" "<<"---"<<" "<<"---"<<"                "<<"---"<<" "<<"---"<<" "<<"---"<<endl;
        cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"                  "<<4<<" | "<<5<<" | "<<6<<endl;
        cout<<"---"<<" "<<"---"<<" "<<"---"<<"                "<<"---"<<" "<<"---"<<" "<<"---"<<endl;
        cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<"                  "<<7<<" | "<<8<<" | "<<9<<endl;

        cout<<endl;

        player1 = !player1;
    } while (!win(board , !player1) && !draw(board , !player1));
    
    return 0;
}