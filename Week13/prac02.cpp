#include <iostream>
#include <algorithm>
#include <forward_list>
using namespace std;

template <typename ForwardIterator, typename Compare>   // template키워드를 이용해 2개의 인자를 생성, 1개는 iterator구현을 위한 것이며 다른 하나는 비교함수를 사용하기 위함
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {   // bubble_sort를 구현한 함수로 위의 iterator를 구현한 ForwardIterator형의 first, last와 comp함수.
    for (auto sorted = first; first != last; last = sorted ) {  // ForwardIterator형태의 sorted를 iterator기반 for문을 이용해 구현
        sorted = first; // sorted라는 변수가 first일 때부터 시작하며
        for (auto current = first, prev = first; ++current != last; ++prev ) {  // current라는 ForwardIterator형태의 변수 current와 prev를 이용해 first일 때와 current를 증가시키면서 last가 되기 전까지 prev도 증가시킨다. 
            if (comp(*current, *prev)) { // 이때, 증가조건을 위해서 아래에서 구현될 comp함수를 이용해 비교하는 것으로 if문을 이용해주고
                swap(*current, *prev); //std::swap함수를 이용해 comp를 했을 때 true라면 swap을 해준다.
                sorted = current;
            }
        }
    }
}

class compGreater { // 오름차순 정렬에 사용
// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
public:
    bool operator()(const int& a, const int& b) {   // a, b라는 int형의 매개변수를 비교하는 함수
        return a > b;   // 오름차순 정렬을 위해 a>b형태로 return
    }
};

class compLess { // 내림차순 정렬에 사용
// functor로 구현(두 정수 비교 결과를 bool 타입으로 리턴, operator( ) 구현)
public:
    bool operator()(const int& a, const int& b) {   // a, b라는 int형의 매개변수를 비교하는 함수
        return a < b;   // 내림차순 정렬을 위해 a<b형태로 return
    }
};

int main() {
    std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
    std::cout << "오름차순 정렬" << std::endl;
    // bubble sort 사용하여 오름차순 정렬 후 결과 출력
    bubble_sort(values.begin(), values.end(), compLess());      // 함수형태로 first, last, comp에 각각 대입
    for(auto x:values)  // 범위기반 for문을 이용해 모든 values를 순회하며 출력
        cout << x << " ";
    std::cout << std::endl;

    // bubble sort 사용하여 내림차순 정렬 후 결과 출력
    std::cout << "내림차순 정렬" << std::endl;
    bubble_sort(values.begin(), values.end(), compGreater());   // 함수형태로 first, last, comp에 각각 대입
    for(auto x:values) {    // 범위기반 for문을 이용해 모든 values를 순회하며 출력
        cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
