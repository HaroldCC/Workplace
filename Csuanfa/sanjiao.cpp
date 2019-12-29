#include<iostream>

int main(void)
{
    int rows = 10;
    int array[rows][rows];

    for (int i = 0; i < rows; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                array[i][j] = 1;
            }
            else
            {
                array[i][j] = array[i-1][j] + array[i-1][j-1];
            }
            std::cout << array[i][j] << " ";
        }
        
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}