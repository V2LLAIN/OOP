#include <iostream>

int main(){
    int array[3] = {8,1,7};
    /* 코드 작성 */ // array 배열과 연결되는 레퍼런스 배열 re 정의
    int(&re)[3] = array;
    /* 코드 작성 */ // re에 값 입력
    re[0] = 8;
    re[1] = 7;
    re[2] = 1;
    std::cout << "Array: " << array[0] << array[1] << array[2] << std :: endl;
    std::cout << "Reference: " << re[0] << re[1] << re[2] << std :: endl;

    return 0;
}

/*
----- 출력 값 -----
Array: 817
Reference: 871
--------------------
 */

// reference 배열은 특별한 경우가 아닌 이상 메모리에서 공간을 차지하지 않는다.
// 따라서 C++차원에서는 금지되어 있다. int& arr[2[ = {a, b}; (X)

// 배열들의 reference는 가능한데 이는 아래와 같다.
// int arr[3] = {1,2,3};            ref가 arr을 참조하도록 함.
// int (&ref)[3] = arr;             크기가 3인 int 배열의 별명(참조자)
