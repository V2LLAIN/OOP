#include <iostream>

int& func(int &a) { return a; }

int main() {
    int x = 1;
    std::cout << func(x)++ << std::endl;
    std::cout << x << std::endl;
}

//lavaue는 변수, rvalue는 상수이다.
//대입연산자의 피연산자는 좌변에만 올 수 있다.
//따라서 lvalue required as increment operand는 상수를 피연산자로 취할때 나타나는 operator
//해결책은 lvalue가 필요하다는 것이다.
//즉, 함수에서 lvalue를 반환하는것(&)으로 해결할 수 있다.
//https://upbo.tistory.com/109