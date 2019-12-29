#include<iostream>
int main(void)
{
    int number[5];
    int num;
    std::cin >> num;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        number[i] = num % 10;
        num = num / 10;
        count++;
    }
    std::cout <<count << std::endl;
    //顺序输出
    for (int i = count - 1; i >= 0; i--)
    {
        std::cout << number[i] << " ";
    }
    std::cout << std::endl;
    
    //逆序输出
    for (int i = 0; i < 5; i++)
    {
        std::cout << number[i];
    }
    std::cout << std::endl;

    
    system("pause");
    return 0;
}