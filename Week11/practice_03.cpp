#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// Class Observer와 Observer의 함수 notifyAllObservers()를 먼저 선언 gn 구현부를 작성해야한다.

class Observer; // 멤버변수로 Subject를 참조해야함

class Subject {  // 멤버변수로 Observer를 참조해야함
private:
    vector<Observer *> observers;
    int state;
public:
    int getState() { return state; }
    void setState(int state) {
        this->state = state;
        notifyAllObservers();
    }
    void attach(Observer* observer) { observers.push_back(observer); }
    void notifyAllObservers();

};
class Observer {
protected:
    Subject *subject;
public:
    virtual void update() = 0;
};

void Subject::notifyAllObservers() {
        for (auto& observer : observers) {
            observer->update();
        }
}
class BinaryObserver : public Observer {
public:
    BinaryObserver(Subject *subject){
        this->subject = subject;
        this->subject->attach(this);
    }
    void update() override {
        cout << "Binary String: " << bitset<4>(subject->getState()).to_string() << endl;    // 4자리 2진수 bit3
    }
};

class OctalObserver : public Observer {
public:
    OctalObserver(Subject *subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    // 10진수 -> 8진수
    void update() override {
        cout << "Octal String: " << oct << subject->getState() << endl;
    }
};

class HexaObserver : public Observer {
public:
    HexaObserver(Subject *subject) {
        this->subject = subject;
        this->subject->attach(this);
    }

    // 10진수 -> 16진수
    void update() override {
        cout << "Hex String: "  << hex << uppercase << subject->getState() << endl;
    }
};

int main() {
    Subject *subject = new Subject();
    new HexaObserver(subject);
    new OctalObserver(subject);
    new BinaryObserver(subject);

    cout << "First state change: 15" << endl;
    subject->setState(15);
    cout << "Second state change: 10" << endl;
    subject->setState(10);

}

// https://hegosumluxmundij.tistory.com/74 (bitset)
