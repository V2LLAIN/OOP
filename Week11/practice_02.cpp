#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Rect {
private:
    int w, h;
public:
    Rect(): w(0), h(0){ }
    Rect(int w, int h): w(w), h(h) { }
    int area() { return w*h; }
    void print() { cout << "(" << w << "," << h << "," << area() << ")" << endl; }

    static bool compare(Rect *rect1, Rect *rect2) {
        return rect1->area() < rect2->area();
    }
};

int main() {
    vector<Rect*> v;

    cout << "사각형의 개수:";
    int num;    cin >> num;
    for (int i = 0; i < num; i++) {
        int wid, height;
        cout << "사각형의 폭:";  cin >> wid;
        cout << "사각형의 높이:"; cin >> height;
        v.push_back(new Rect(wid, height));
    }

    sort(v.begin(), v.end(), Rect::compare);

    for (int i = 0; i < num; i++) {
        v[i]->print();
    }
}
