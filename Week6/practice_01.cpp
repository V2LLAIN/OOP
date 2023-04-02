#include <iostream>
using namespace std;

class unary{ // 전,후위 증가연산자에 대한 클래스
private:
    int num; // 증가연산을 위한 int형 변수
public:
    unary(int num = 0) : num(num) {} //생성자로 num변수 초기화

    void show() {  // print를 위한 show함수
        cout << num << ' ';
    }

    //prefix unary operator (전위증가연산자)
    unary& operator++(){
        num += 1;
        return *this;
    }

    //postfix unary operator (후위증가연산자)
    const unary& operator++(int){
        const unary obj(*this);
        num += 1;
        return obj;
    }
};

int main(){
    unary a(5); //객체a 생성 후 5로 초기화
    a.show(); // show함수 call, 5 출력
    cout << "(초기값), ";

    a++; // 객체 a를 오버로딩한 후위증가연산자로 연산 진행
    a.show(); // show함수 call, 6 출력
    cout << "(a++ 결과), ";
    ++a; //// 객체 a를 오버로딩한 전위증가연산자로 연산 진행
    a.show(); // show함수 call, 7 출력
    cout << "(++a 결과)" << endl;
}