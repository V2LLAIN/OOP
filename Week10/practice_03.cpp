#include <iostream>
using namespace std;
class BaseClass { // 기본클래스 생성
public:
    BaseClass() { cout << "Everything is OKAY" << endl; }; //기본클래스 생성자
        virtual ~BaseClass() {} //        가상소멸자
    };
    class DerivedClass : public BaseClass { // 기본클래스를 상속받는 유도클래스 생성
    public:
        DerivedClass() { } // 유도클래스생성자
        virtual ~DerivedClass() {} // 가상소멸자
    };
    int main() {
        BaseClass *base = new DerivedClass();  // 객체생성
        DerivedClass *derived =  dynamic_cast<DerivedClass*>(base); // 타입캐스팅중dynamic_cast를 이용한 방식의 형변환 사용
        if (base == nullptr) //기본클래스의 포인터가nullptr이 나올 때
            cout << "Err" << endl; // 에러 출력
        delete base;
    }
