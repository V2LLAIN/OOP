#include<iostream>

void swap (int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

int main()
{
    int a = 2, b = 3;
    int &rta = a;
    int &rtb = b;
    swap( rta, rtb );
    std::cout << a << " " << b << std::endl;
    return 0;
}