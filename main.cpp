#include<iostream>
#include<string>
using namespace std;

struct pcb
{
    string process_name;              //进程名
    int process_super;                //优先数
    int need_times;                   //需要运行时间
    int runded_times;                //已运行时间
    char[3] process_status = {'W', 'R', 'F'};//进程状态
};


void input(void){
    int sum;                   //进程总数
    cout << "输入要执行的进程数量：";
    cin >> sum;

    //分别读入进程的内容
    for (int i = 0; i < sum; i++)
    {
        cout << endl;
        cout << "进程号No." << i + 1 << endl;
        cout << "输入进程名";
        cin >> process_name;
        cout << "输入进程优先数：";
        cin >> process_super;
        cout << "输入进程运行时间：";
        cin >> need_times;
    }
    
}
