#include <iostream>
using namespace std;

auto sum() ->double { return 0; }   //auto 키워드와 decltype 표기방식을 활용하여 return type이 double임을 표시, 아래의 sum 함수가 반환이 1개일 때를 대비하기 위한 함수

template<typename T, typename... Args>  //variadic template 방법을 활용해 여러 인자를 한번에 받을 수 있게 template를 설정
auto sum(T num, Args... args) ->double {    //auto 키워드와 decltype 표기방식을 활용하여 return type이 double임을 표시
    return num + sum(args...);
}

template<typename... Args>
auto average(Args... args) ->double {   // 위에서의 sum함수를 이용해 평균을 내기 위해 만들어진 함수로 auto 키워드와 decltype 표기방식을 활용하여 return type이 double임을 명시적으로 표시
    return static_cast<double>(sum(args...)) / sizeof...(args); // type casting 중 static_cast를 이용해 double임을 표시, sizeof...연산자를 이용해 위의 args의 개수를 count
}

int main() {
    std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // 위에서의 average함수의 인자에 각 값들을 대입
    return 0;
}


