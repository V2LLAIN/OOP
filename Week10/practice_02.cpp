#include <iostream>
using namespace std;

class DrawAPI {  // 인터페이스 생성 (구현이 없음)
public:
    virtual void drawCircle(int radius, int x, int y) = 0;  // 순수 가상함수
};
class RedCircle : public DrawAPI {      // 인터페이스를 상속받는 클래스
public:
    void drawCircle (int radius, int x, int y){     // 인터페이스에서 생성한 함수를 이용해 만든 함수, 출력 담당
        cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << endl;
    }
};
class GreenCircle : public DrawAPI {        // 인터페이스를 상속받는 클래스
    void drawCircle (int radius, int x, int y){     // 인터페이스에서 생성한 함수를 이용해 만든 함수, 출력 담당
        cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << endl;
    }
};

// 추상클래스 구현
class Shape {
protected:
    DrawAPI *drawAPI;       // 객체 생성
    Shape(DrawAPI *drawAPI){    // 위에서 생성한 객체를 매개변수로 받는 생성자 생성
        this->drawAPI = drawAPI;
    }
public:
    Shape(){};      // 생성자 생성
    virtual void draw() = 0;     // 순수 가상함수 생성
};

class Circle : public Shape {   // Shape 클래스를 상속받는 파생클래스 생성
private:
    int x, y, radius;   // 멤버 변수 생성
public:
    Circle(int x, int y, int radius, DrawAPI *drawAPI) {// x, y, radius와 DrawAPI의 객체를 매개변수로 받는 생성자 생성
        this->drawAPI = drawAPI;
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() {   //가상함수로 생성한 함수를 이용해 멤버함수 생성
        drawAPI->drawCircle(radius, x, y);      //객체를 이용한 함수접근
    }
};

int main() {
    // 객체생성 후 생성자 형식에 맞게 매개변수값 대입
    Shape *redCircle = new Circle(100,100, 10, new RedCircle());
    Shape *greenCircle = new Circle(100,100, 10, new GreenCircle());

    // 출력
    redCircle->draw();
    greenCircle->draw();
}
