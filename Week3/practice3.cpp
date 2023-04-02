#include <iostream>
void increment(int &x)
{
    ++x;
}
int main()
{
    int x=55;
    int &rtx = x;
    std::cout<<" Before increment: "<<x<< std::endl;
    increment( rtx );
    std::cout << " After increment: " << x << std::endl;
    system("pause");
    return 0;
}