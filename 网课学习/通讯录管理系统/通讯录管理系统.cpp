/*************************************************************************
    > File Name       : 通讯录管理系统.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2019-12-31 16:55:13
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

// 显示操作菜单
void showMenu(void)
{
  cout << "*************************" << endl;
  cout << "***** 1、添加联系人 *****" << endl;
  cout << "***** 2、显示联系人 *****" << endl;
  cout << "***** 3、删除联系人 *****" << endl;
  cout << "***** 4、查找联系人 *****" << endl;
  cout << "***** 5、修改联系人 *****" << endl;
  cout << "***** 6、清空联系人 *****" << endl;
  cout << "***** 0、退出通讯录 *****" << endl;
  cout << "*************************" << endl;
}

// 人结构体
struct Person
{
  string name;
  int sex;
  int age;
  string phone;
  string addr;
};

//通讯录结构体
#define MAX 1000 // 最大人数
struct AddressBooks
{
  struct Person personArray[MAX];
  int size; // 通讯录中人员个数
};

// 添加联系人
void addPerson(AddressBooks *abs)
{
  if (abs->size == MAX)
    cout << "通讯录已满，无法添加！\n";
  else
  {
    cout << "请输入姓名： ";
    string name;
    cin >> name;
    abs->personArray[abs->size].name = name;

    cout << "请输入性别：\n";
    cout << "\t1、男\n"
         << "\t2、女\n";
    int num;
    while (true)
    {
      cin >> num;
      if (num == 1 || num == 2)
      {
        abs->personArray[abs->size].sex = num;
        break;
      }
      else
        cout << "请输入正确的代号！\n";
    }

	cout << "请输入年龄： ";
	int age;
	cin >> age;
	abs->personArray[abs->size].age = age;

	cout << "请输入联系电话： ";
	string phone;
	cin >> phone;
	abs->personArray[abs->size].phone = phone;

	cout << "请输入家庭地址：";
	string addr;
	cin >> addr;
	abs->personArray[abs->size].addr = addr;

	abs->size++;        // 更新通讯录人数
	cout << "添加成功！\n";

	system("pause");
	system("cls");    // 清屏操作
  }
}

// 显示联系人
void showPerson(AddressBooks* abs)
{
	if (abs->size == 0)
		cout << "当亲记录为空！\n";
	else 
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名： " << abs->personArray[i].name << "\t";
			cout << "性别： " << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].age << "\t";
			cout << "电话： " << abs->personArray[i].phone << "\t";
			cout << "住址： " << abs->personArray[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}

// 检测联系人是否存在，返回联系人在数组中的位置，不存在返回-1
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
			return i;
	}
	return -1;
}

//删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "请输入您要删除的联系人的姓名： ";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->size; i++)	
			// 数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		abs->size--;
		cout << "删除成功！\n";
	}
	else
		cout << "查无此人！";
	
	system("pause");
	system("cls");
}

// 查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "输入要查找的联系人的姓名：";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{	
		cout << "姓名： " << abs->personArray[ret].name << "\t";
		cout << "性别： " << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].age << "\t";
		cout << "电话： " << abs->personArray[ret].phone << "\t";
		cout << "住址： " << abs->personArray[ret].addr << endl;
	}
	else 
		cout << "查无此人！\n";

	system("psuse");
	system("cls");
}

// 修改联系人
void modifyPerson(AddressBooks* abs)
{
	cout << "输入要修改的联系人姓名： ";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名： ";
		string name;
		cin >> name;
		abs->personArray[ret].name = name;
		cout << "请输入性别： \n";
		cout << "\t1、男\n\t2、女\n";
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			else 
				cout << "请输入正确的代号！" << endl;
		}

		cout << "请输入年龄：";
		int age;
		cin >> age;
		abs->personArray[ret].age = age;

		cout << "请输入联系电话：";
		string phone;
		cin >> phone;
		abs->personArray[ret].phone = phone;

		cout << "请输入家庭地址：";
		string addr;
		cin >> addr;
		abs->personArray[ret].addr = addr;
		cout << "修改成功！\n";
	}
	else 
		cout << "查无此人！\n";

	system("pause");
	system("cls");
}


// 清空联系人
void deleteAllPerson(AddressBooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空！\n";

	system("pause");
	system("cls");
}


int main(int argc, char *argv[])
{
  int select = 0;

  AddressBooks abs;
  abs.size = 0;

  while (true)
  {

    showMenu();
    cin >> select;

    switch (select)
    {
    case 1:
      addPerson(&abs);
      break;
    case 2:
	  showPerson(&abs);
      break;
    case 3:
	  deletePerson(&abs);
      break;
    case 4:
	  findPerson(&abs);	  
      break;
    case 5:
	  modifyPerson(&abs);
      break;
    case 6:
	  deleteAllPerson(&abs);
      break;
    case 0:
      cout << "欢迎下次使用！\n";
      system("pause");
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}
