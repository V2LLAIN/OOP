#include <iostream>
#include <cassert>

class CEO { virtual void what() {} };
class CPO { virtual void what() {} };
class Manager : public CEO, public CPO {};
class Staff : public CPO {};

int main() {
    CPO* cpo = new Staff(); // up
    Staff* staff = dynamic_cast<Staff*>(cpo); // down
    Manager* manager = dynamic_cast<Manager*>(staff); // down
    CEO* ceo = new Manager(); // up

    std::cout << typeid(cpo).name() << std::endl;
    std::cout << typeid(Staff*).name() << std::endl;
    
    assert(typeid(cpo) == typeid(Staff*));

    delete cpo;
    delete ceo;
}
