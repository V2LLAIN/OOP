#include <iostream>

int main()
{
    const int &x = 5;
    std::cout << x << std::endl;
}


//코드의 컴파일 에러를 수정하시오. 단, x의 타입 (레퍼런스)을 유지해야함.
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=0511cjh&logNo=221590246985