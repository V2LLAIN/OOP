#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Shape{  // 인터페이스 생성 (함수에 대한 구현이 없 포함)
public:
    virtual void draw() = 0;  // 순수 가상함수
};
class RoundedRectangle : public Shape{ // 인터페이스 상속
public:
    virtual void draw() override{   // 인터페이스에서 만든 가상함수를 이용해 override한 함수
        cout << "Inside RoundedRectangle::draw() method." << endl;
    }
};
class RoundedSquare : public Shape{ // 인터페이스 상속
public:
    virtual void draw() override{   // 인터페이스에서 만든 가상함수를 이용해 override한 함수
        cout << "Inside RoundedSquare::draw() method." << endl;
    }
};
class Rectangle : public Shape{ // 인터페이스 상속
public:
    virtual void draw() override{   // 인터페이스에서 만든 가상함수를 이용해 override한 함수
        cout << "Inside Rectangle::draw() method." << endl;
    }
};
class Square : public Shape{ // 인터페이스 상속
public:
    virtual void draw() override{   // 인터페이스에서 만든 가상함수를 이용해 override한 함수
        cout << "Inside Square::draw() method." << endl;
    }
};

class AbstractFactory {     // 추상클래스 생성
public:
    virtual Shape* getShape(const char *shapeType) = 0;
};
class ShapeFactory : public AbstractFactory {   // 생성한 추상클래스 상속
public:
    virtual Shape *getShape(const char *shapeType) {    // getShape함수로 Shape클래스 타입을 반환함

        if (stricmp(shapeType, "RECTANGLE") == 0) {        //shapeType.equalsIgnooreCase("RECTANGLE")
            return new Rectangle();     // 생성된 새로운 객체를 반환
        }

        else if (stricmp(shapeType, "SQUARE") == 0) {        //shapeType.equalsIgnooreCase("SQUARE")
            return new Square();        // 생성된 새로운 객체를 반환
        }
        return nullptr;        // null값 반환
    }
};
class RoundedShapeFactory : public AbstractFactory {    // 생성한 추상클래스 상속
public:
    virtual Shape* getShape(const char *shapeType) override {       // Shape클래스를 return 타입으로 받는 함수 생성
        if (stricmp(shapeType, "RECTANGLE") == 0)  {        //shapeType.equalsIgnooreCase("RECTANGLE")와 동일한 역할을 수행
            return new RoundedRectangle();      // 생성된 새로운 객체 반환
        }
        else if (stricmp(shapeType, "SQUARE") == 0) {       //shapeType.equalsIgnooreCase("SQUARE")와 동일한 역항를 수행
            return new RoundedSquare();         // 생성된 새로운 객체 반환
        }
        return NULL;
    }
};

class FactoryProducer {     // 추상클래스를 return타입으로 하는 함수를 갖는 클래스
public:
    static AbstractFactory *getFactory(bool rounded) {  //추상클래스를 return타입으로 하는 static 함수
        if(rounded){        // rounded가 true인 경우
            return new RoundedShapeFactory();   // RoundedShapeFactory객체를 생성하도록 함
        }
        else{       // rounded가 true가 아닌 경우
            return new ShapeFactory();  //ShapeFactory객체를 생성
        }
    }
};

int main() {
    //get shape factory
    AbstractFactory *shapeFactory = FactoryProducer().getFactory(false);
    //get an object of Shape Rectangle
    Shape *shape1 = shapeFactory->getShape("RECTANGLE");
    //call draw method of Shape Rectangle
    shape1->draw();

    //get an object of Shape Square
    Shape *shape2 = shapeFactory->getShape("SQUARE");
    //call draw method of Shape Square
    shape2->draw();
    //get shape factory
    AbstractFactory *shapeFactory1 = (new FactoryProducer)->getFactory(true);

    //get an object of Shape Rectangle
    Shape *shape3 = shapeFactory1->getShape("RECTANGLE");
    //call draw method of Shape Rectangle
    shape3->draw();

    //get an object of Shape Square
    Shape *shape4 = shapeFactory1->getShape("SQUARE");
    //call draw method of Shape Square
    shape4->draw();
}