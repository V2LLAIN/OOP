#include <iostream>
#include <exception>
#include <string>
using namespace std;

class NewException : public exception{ //새로운 Exception NewException은 exception클래스를 상속받음
public:
    const char* what() const noexcept override{ // what 함수의 오버라이딩 진행
        return "NewException";
    }
};

int main(){
    try{
        string str;
        str.resize(-100);
    }
    catch (exception& e){
        try {
            throw NewException(); // 예외 발생시 새로운 Exception throw
        }
        catch (const NewException& newException){
            cout << "My exception is " << newException.what() << endl; // NewException의 what()에서 전달받은 문자열 출력
        }
    }
}
