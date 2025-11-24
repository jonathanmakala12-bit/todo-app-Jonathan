#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
vector<string> loadTasks()
{
    vector<string> tasks;
    fstream file("Task3file.txt");
    string line;
    while (getline(file,line))
    {
        tasks.push_back(line);
    }
    file.close();
    return tasks;
}
void saveTasks(const vector<string>& tasks)
{
    fstream file("Task3file.txt",ios::out);
    for (const string& task : tasks)
    {
        file<<task<<endl;
    }
    file.close();
}
void markTaskAsDone(int index)
{
    vector<string> tasks = loadTasks();
    if (index<1 || index>tasks.size())
    {
        cout<<"Invalid task number.\n";
        return;
    }
    if (tasks[index - 1].rfind("[DONE]",0)!=0)
    {
        tasks[index - 1]="[DONE]" + tasks[index - 1];
    }
    saveTasks(tasks);
    cout<<"Task marked as done!!!\n";
}
void deleteTask(int index)
{
    vector<string> tasks = loadTasks();
    if (index < 1 || index > tasks.size())
    {
        cout<<"Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin()+(index - 1));
    saveTasks(tasks);
    cout<<"Task deleted succesfully!\n";
}
void add_task(string task)
{
    fstream file;
    file.open("Task3file.txt",ios::app);
    if (file.is_open())
    {
        file<<task<<endl;
        file.close();
    }
}
void view_task()
{
    fstream file;
    file.open("Task3file.txt",ios::in);
    string line;
    while (getline(file,line))
    {
        cout<<" - "<<line<<endl;
    }
    file.close();
}
int main()
{
    int option, choice, num;
    string task, line;
    while (true)
    {
        cout<<"=================="<<endl;
        cout<<"  TO - DO LIST    "<<endl;
        cout<<"=================="<<endl;
        cout<<endl;
        cout<<"1. Add Task "<<endl;
        cout<<"2. View Tasks "<<endl;
        cout<<"3. Mark Task as Completed "<<endl;
        cout<<"4. Delete Task "<<endl;
        cout<<"5. Exit "<<endl;
        cout<<endl;
        cout<<"Choose a number from the menu above : ";
        if (!(cin>>option))
        {
            cout<<"Wrong Entry Check the menu "<<endl;
            cout<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();
        switch (option)
        {
        case 1:
            cout<<"Enter a new task : ";
            getline(cin,task);
            add_task(task);
            cout<<endl;
            break;
        case 2:
            view_task();
            cout<<endl;
            break;
        case 3:
            cout<<"Enter task number to mark as done : ";
            cin>>num;
            markTaskAsDone(num);
            cout<<endl;
            break;
        case 4:
            cout<<"Enter task number to delete : " ;
            cin>>choice;
            deleteTask(choice);
            cout<<endl;
            break;
        case 5:
            cout<<"Exiting ... "<<endl;
            return 0;
            break;
        default :
            cout<<"Wrong number Entry check from the menu "<<endl;
            cout<<endl;
        }
    }
    return 0;
}
