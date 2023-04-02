#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
    int num;
    for (int i = 0; i < 10; i++) {
        cin >> num;
        v.push_back(num);
    }

    auto it = minmax_element(v.begin(), v.end());
    cout << "min: " << *it.first << " " << "MAX" << *it.second << endl;
}
