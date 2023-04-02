#include <iostream>
using namespace std;

class A{ // 생성자 및 소멸자 정의, 출력하는 클래스 A
public:
    A(){ // 생성자 정의 및 cout으로 출력
        cout << "Constructor()" << endl;
    }
    ~A(){ // 소멸자 정의 및 cout으로 출력
        cout << "Destructor()" << endl;
    }
};

int main(){
    try{
        A a; //객체 생성
        throw a; //그 객체 a를 throw
    }
    catch(A& a){
        cout << "Catch 10" << endl; // throw된 값을 catch에서 cout 출력
    }
}