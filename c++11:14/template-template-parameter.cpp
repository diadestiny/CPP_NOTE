#include <vector>
using namespace std;

// 什么场景需要用到模板模板参数？
// 比如vector<T,allocator<T>> 


// 首先XCLs是一个模板类：
// 1. 希望内部的容器成员的属性可以是任意类型
template<typename T>
class XCLs_0{
private:
        vector<T> c;
}
// 2. 希望内部的容器成员c可以适配多种容器，比如vector, list, array等
// XCls所以需要指定第二个模板参数(原始的话是typename Container), 如果这样的话，成员Container<T> 是不能通过的，因为有些Container是需要指定内部的第二个模板参数的，所以需要引入模板模板参数
template<typename T,
        template<class>
        class Container
        >
class XCls{
private:
    Container<T> c;
public:
    XCls() {
        for(long i = 0; i < 100; ++i) {
            c.insert(c.end(), T());
        }
    }
};

template<typename T>
using Vec = vector<T, allocator<T>>;

class MyString{};

int main() {
    XCls<MyString, Vec> x;
}
