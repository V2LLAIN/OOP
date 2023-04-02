#include <iostream>
#include <string>
using namespace std;

class Person{ // Person 클래스로 기본클래스로 이름,주소,나이를 출력하는 함수가 존재
private:
    string name; //이름을 받는 string형 변수
    int age; // 나이를 받는 int형 변수
    string address; // 주소를 받는 string형 변수

public:
    string getName() { return name; } // string을 반환형으로 받고 name을 return하는 함수
    string getAddress() { return address; } // string을 반환형으로 받고 address를 return하는 함수
    int getAge() { return age; } // int를 반환형으로 받고 age를 return하는 함수

    // 생성자 생성 및 member initializer로 member 변수 초기화
    Person(string name, int age, string address) : name(name), age(age), address(address){    }
};

class Student : public Person{ // Person 클래스를 상속받는 Student 클래스
private:
    int studentID; // 학번을 받는 int형 변수
public:
    int getStudentID(){ return studentID; }
    // 생성자 생성 및 member initializer로 member 변수 및 상속받은 Person member 변수도 초기화 진행
    Student(string myname, int myage, string myaddress, int studentID) : Person(myname, myage, myaddress), studentID(studentID){
        cout << "Student Information" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Age : " << getAge() << endl;
        cout << "Address : " << getAddress() << endl;
        cout << "Student ID : " << getStudentID() << endl;
    }
};

int main(){
    //student 객체 생성
    Student student("임형찬", 10, "daejeon", 202102559);
}
