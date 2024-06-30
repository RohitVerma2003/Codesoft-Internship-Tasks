#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int random = rand() % 101;
    int guess;
    int score = 100;

    cout<<"---------- Starting the game ----------"<<endl;
    cout<<"      Number lies between 0 to 100       "<<endl;
    do
    {
        cout<<"Guess The Number : ";
        cin>>guess;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << endl << "---- InValid Choice ----" << endl;
            continue;
        }

        if(guess == random){
            cout<<endl;
            cout<<"Congrats "<<random<<" is the correct number"<<endl;
            cout<<"Your Score is "<<score<<endl;
            cout<<endl;
        }

        if(guess < random){
            cout<<endl;
            cout<<"Correct Number is Greater than "<<guess<<endl;
            cout<<endl;
        }

        if(guess > random){
            cout<<endl;
            cout<<"Correct Number is Smaller than "<<guess<<endl;
            cout<<endl;
        }

        score--;

        if(score == 0) break;
    } while (guess != random);

    cout << endl << "---- Game Over ----" << endl;

    if(score == 0) cout << endl << "---- You Lost ----" << endl;

    return 0;
    
}