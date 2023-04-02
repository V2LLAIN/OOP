#include <iostream>
void increment(int *x)
{
    ++*x;
}
int main()
{
    int x=55;
    int *ptx = &x;
    std::cout<<" Before increment: "<<x<< std::endl;
    increment( ptx );
    std::cout << " After increment: " << x << std::endl;
    system("pause");
    return 0;
}