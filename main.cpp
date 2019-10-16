#include<iostream>
#include<string>
using namespace std;

//定义进程控制块PCB
struct pcb
{
    string process_name;              //进程名
    int process_super;                //优先数
    int need_times;                   //需要运行时间
    int runded_times;                //已运行时间
    char process_status;
    //[3] = {'W', 'R', 'F'};//进程状态
    struct pcb * link;
}*ready = nullptr, *p;

typedef struct pcb PCB;            //将结构体pcb命名为PCB



//采用插入链表结点的方法对所有进程按优先数从大到小的顺序排列成就绪队列。
//每个结点都要找对插入位置，插入后必须保证链表中结点按从大到小的顺序排列）
void sort(void){
    PCB*first, *second;
	int insert = 0;
	if((ready == nullptr) || ((p->process_super) > (ready->process_super)))
	{
		p->link=ready;
		ready=p;
	}
	else
    {
		first=ready;
		second=first->link;
		while(second!=nullptr)
		{
			if((p->process_super) > (second->process_super))
			{
				p->link=second;
				first->link=p;
				second=nullptr;
				insert=1;
			}
			else 
			{
				first=first->link;
				second=second->link;
			}
        }
		if (insert==0) first->link=p;
	}
}

//建立进程
void input(void){
    int sum;                   //进程总数
    cout << "输入要执行的进程数量：";
    cin >> sum;
    cout << endl;

    //分别读入进程的内容
    for (int i = 0; i < sum; i++)
    {
        cout << endl;
        cout << "进程号No." << i + 1 << endl;
        p = new PCB;
        cout << "输入进程名:";
        cin >> p->process_name;
        cout << "输入进程优先数：";
        cin >> p->process_super;
        cout << "输入进程需要运行时间：";
        cin >> p->need_times;
        cout << endl;
        p->runded_times = 0;
        p->process_status = 'W';               //进程状态为就绪状态
        p->link = 0;
        sort();                     //对进程按照优先数进行排序
    }
    
}

//统计就绪队列（链表）中的进程数（结点数）
int W_process_count(void){
    int l=0;
	  PCB* pr=ready;
	  while(pr!=NULL)
	  {
		  l++;
		  pr=pr->link;	  
	  
	  }
      return(1);
}

//建立进程显示函数，用于显示当前进程
void show_current_process(PCB *pr){
    cout << "进程名：" << pr->process_name;
    cout << " " << "进程状态：" << pr->process_status;
    cout << " " << "进程优先数：" << pr->process_super;
    cout << " " << "进程需要运行时间：" << pr->need_times;
    cout << " " << "进程已运行时间：" << pr->runded_times;
    cout << endl;
}

//建立进程查看函数，依次输出当前正在运行的进程和正处于就绪队列的进程的各个参数
void check_process(void){
    PCB* pr;
    cout<<endl<<"****当前正在运行的进程是："<<p->process_name<<endl;//显示当前运行进程
    show_current_process(p);                             //调用函数显示
    pr=ready;
    cout<<endl<<"****当前就绪队列状态为："<<endl;//显示就绪队列状态
    while(pr!=NULL)
    {
        show_current_process(pr);
        pr = pr->link; 
    }
}

//进程撤销函数（进程运行结束，撤销进程）
void destroy_process(void){
    cout<<endl<<"进程"<<p->process_name<<"已完成"<<endl;
    delete (p);
}

//对正在运行的进程进行处理：当前正在运行进程的已运行时间加一，
//若达到所需的运行时间，则撤销进程；否则，优先数-1，插入就绪队列。
void running_times(void){
    (p->runded_times)++;
   if(p->runded_times == p->need_times)
	   destroy_process();//调用撤销函数
   else
   {
      (p->process_super)--;
	   p->process_status = 'w';
	   sort();//调用sort函数 
    }
}

int main(void)
{

    
    int len, h = 0;
    input();
    len = W_process_count();
    while ((len != 0) && (ready != NULL))
    {
        //system("pause");
        h++;
        cout << "*****************第"<< h << "次执行*****************"<<endl;
        p = ready;   //使就绪队列首进程投入运行
	    ready = p->link;
        p->link = NULL;
	    p->process_status='R';
	    check_process();
	    running_times();
        system("pause");
        cout << endl;
    }
    cout << endl << "***********************************************\n";
    cout << endl << "进程模拟完成！" << endl;
    
    system("pause");
    return 0;
}
