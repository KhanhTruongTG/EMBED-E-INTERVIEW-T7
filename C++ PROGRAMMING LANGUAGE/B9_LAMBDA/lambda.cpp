#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* [capture clause] (parameters) -> return-type
{
    definition of method
}
*/
void test(){   // được lưu ở phân vùng stack
    int a = 10;
    auto test = [](int a, int b)->int{
        return a+b;
    };
    cout<<test(6,7)<<endl;
}

/*bool myfunction (int i, int j) = {return i<j};*/

//Khi kết thúc test thì những địa chỉ, biến trong test bị thu hồi hết
//Trong hàm tốn bộ nhớ hơn lambda

int main(int argc, char const *argv[])
{
    test();
    int d = 10, e = 15, f = 20;
    auto tong = [=](int a, int b)->int{ //  [=]: những biến mà mình sử dụng thì nó sẽ tự hiểu
        return a+b+d+e+f;
    };
    cout<<tong(5,5)<<endl;


    vector <int> v1 = {1,2,5,7,3,9,6};
    sort(v1.begin(), v1.end(), [](int i, int j){return i<j;});
    vector <int>::iterator it;
    for (it = v1.begin(); it != v1.end(); ++it)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}
