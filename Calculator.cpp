#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Addition()
{
    double n1, n2;

    cout << "Enter number 1 : ";
    cin >> n1;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout << "Enter number 2 : ";
    cin >> n2;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout<<endl;
    cout<<"Answer: "<< n1 + n2 << endl;
    cout<<endl;
}

void Subtraction()
{
    double n1, n2;

    cout << "Enter number 1 : ";
    cin >> n1;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout << "Enter number 2 : ";
    cin >> n2;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout<<endl;
    cout<<"Answer: "<< n1 - n2 << endl;
    cout<<endl;
}

void Division()
{
    double n1, n2;

    cout << "Enter number 1 : ";
    cin >> n1;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout << "Enter number 2 : ";
    cin >> n2;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout<<endl;
    cout<<"Answer: "<< n1 / n2 << endl;
    cout<<endl;
}

void Multiplication()
{
    double n1, n2;

    cout << "Enter number 1 : ";
    cin >> n1;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout << "Enter number 2 : ";
    cin >> n2;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl
             << "---- InValid Choice ----" << endl;
        return;
    }

    cout<<endl;
    cout<<"Answer: "<< n1 * n2 << endl;
    cout<<endl;
}

int main()
{
    int choice;
    do
    {
        cout << "---------------------------------------" << endl;
        cout << endl;

        cout << "Welcome to Calculator : " << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Division" << endl;
        cout << "4. Multiplication" << endl;
        cout << "5. Close" << endl;

        cout << endl;
        cout << "---------------------------------------" << endl;

        cout << "Enter Your Choice : ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl
                 << "---- InValid Choice ----" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            Addition();
            break;
        case 2:
            Subtraction();
            break;
        case 3:
            Division();
            break;
        case 4:
            Multiplication();
            break;
        case 5:
            cout << endl
                 << "---- App Closed ----" << endl;
            break;
        default:
            cout << endl
                 << "---- InValid Choice ----" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}