#include <iostream>
#include <vector>
using namespace std;

class Shape { // 순수가상함수가 선언된 클래스
public:
    virtual void draw() = 0;    // 순수가상함수 draw 선언
};
class Rectangle : public Shape {    // Shape클래스를 상속한 Rectangle클래스
public:
    virtual void draw() {   // 순수가상함수 draw를 이용해 지정된 내용을 출력하는 함수
        cout << "Shape: Rectangle" << endl;
    }
};
class Circle : public Shape {   // Shape클래스를 상속한 Circle 클래스
public:
    virtual void draw() {   // 순수가상함수 draw를 이용해 지정된 내용을 출력하는 함수
        cout << "Shape: Circle" << endl;
    }
};

class ShapeDecorator : public Shape {   // Shape클래스를 상속한 ShapeDecorator 클래스
protected:
    Shape *decoratedShape;  // protected에 있는 Shape클래스 객체 decoratedShape 생성
public:
    ShapeDecorator(Shape *decoratedShape) { //위의 객체를 반환값으로 받는 생성자 생성
        this->decoratedShape = decoratedShape;  //this 키워드를 이용해 초기화
    }
    virtual void draw() {   // 위에서 선언된 순수가상함수 draw를 이용해 위의 객체를 이용해 Shape의 draw함수를 호출
        decoratedShape->draw();
    }
};
class RedShapeDecorator : public ShapeDecorator {   // Shape클래스를 상속한 RedShapeDecorator 클래스
public:
    RedShapeDecorator(Shape *decoratedShape) : ShapeDecorator(decoratedShape) { }   // super를 흉내내기 위한 initializer list를 이용한 초기화시키는 생성자
    virtual void draw() {   // 순수가상함수 draw를 이용해 부모클래스에서 생성했던 객체를 이용한 함수 호출 및 setRedBorder라는 함수에 객체를 매개변수로 삼음
        decoratedShape->draw();
        setRedBorder(decoratedShape);
    }
private:
    void setRedBorder(Shape *decoratedShape) {  // 위의 setRedBorder함수사용을 위해 매개변수에 객체를 매개변수로 지정
        cout << "Border Color: Red" << endl;
    }
};

int main() {
    // 각각에 해당하는 객체 생성
    Shape *circle = new Circle();
    Shape *redCircle = new RedShapeDecorator(new Circle());
    Shape *redRectangle = new RedShapeDecorator(new Rectangle());

    cout << "Circle with normal border" << endl;
    circle->draw(); // 함수 호출

    cout << "\nCircle of red border" << endl;
    redCircle->draw();  // 함수호출

    cout << "\nRectangle of red border" << endl;
    redRectangle->draw();   // 함수호출
}



