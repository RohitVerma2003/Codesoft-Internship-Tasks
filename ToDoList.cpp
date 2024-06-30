#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Task
{
public:
    string taskName;
    bool isCompleted;

    Task(string taskName)
    {
        this->taskName = taskName;
        this->isCompleted = false;
    }
};

Task *addTask()
{
    string taskName;
    cout << "Enter the task : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin , taskName);

    Task *newTask = new Task(taskName);
    return newTask;
}

void setComplete(vector<Task *> &toDoList)
{
    int index;
    int size = toDoList.size();

    cout << endl
         << "Enter The Number Of Task Which Is Completed : ";
    cin >> index;

    if (cin.fail() || index <= 0 || index > size)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- InValid Number ----" << endl;
        return;
    }

    toDoList[index - 1]->isCompleted = true;
    cout << endl
         << "Congratulations Task Completed!" << endl;
}

void deleteTask(vector<Task *> &toDoList)
{
    int index;
    int size = toDoList.size();

    cout << endl
         << "Enter The Number Of Task Which Is To Deleted : ";
    cin >> index;

    if (cin.fail() || index <= 0 || index > size)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl << "---- InValid Number ----" << endl;
        return;
    }

    delete toDoList[index - 1];
    toDoList.erase(toDoList.begin() + (index - 1));
    cout << endl
         << "Task Deleted!" << endl;
}

void showTasks(vector<Task *> toDoList)
{
    cout << endl
         << "----- To Do List -----" << endl;

    for (int i = 0; i < toDoList.size(); i++)
    {
        auto ele = toDoList[i];
        cout << (i + 1) << ". "<< ele->taskName << " ";

        if (ele->isCompleted)
            cout << "(Completed)" << endl;
        else
            cout << "(Not Completed)" << endl;
    }
}

int main()
{
    int choice;
    vector<Task *> toDoList;

    do
    {
        cout << "---------------------------------------" << endl;
        cout << endl;

        cout << "Welcome to your To Do List : " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Tick Task To Complete" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. View All Tasks" << endl;
        cout << "5. Close" << endl;

        cout << endl;
        cout << "---------------------------------------" << endl;

        cout << "Enter Your Choice : ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << endl << "---- InValid Choice ----" << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            toDoList.push_back(addTask());
            cout << endl
                 << "Task Added " << endl;
            break;
        case 2:
            setComplete(toDoList);
            break;
        case 3:
            deleteTask(toDoList);
            break;
        case 4:
            showTasks(toDoList);
            break;
        case 5:
            cout << endl
                 << "---- App Closed ----" << endl;
            break;
        default:
            cout << endl << "---- InValid Choice ----" << endl;
            break;
        }
    } while (choice != 5);
}