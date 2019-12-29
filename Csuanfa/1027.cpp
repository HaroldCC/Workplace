#include<iostream>

//最大公约数
int maxDiv(int n1, int n2){
    return n2 ? maxDiv(n2, n1%n2) : n1;
}

//最小公倍数
int minMul(int n1, int n2){
    int minMul = 0;
    return minMul = n1 * n2 / maxDiv(n1, n2);
}

int main(void)
{
    int num1, num2;
    std::cin >> num1 >> num2;

    int maxDivisor, minMultiple;
    maxDivisor = minMultiple = 0;

    maxDivisor = maxDiv(num1, num2);
    minMultiple = minMul(num1, num2);
    
    std::cout << maxDivisor << " " << minMultiple << std::endl;
    
    
    system("pause");
    return 0;
}