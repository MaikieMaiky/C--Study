#include <iostream>
#include <memory.h>
using namespace std;
// 自制只能指针

// 1.练习智能指针的实现
template <typename T>
class mySmartPointer
{
private:
    T *m_pointer;
public:
    mySmartPointer(T *pointer) : m_pointer(pointer) { cout << "mySmartPointer constructor" << endl; }
    ~mySmartPointer() { delete m_pointer; cout << "mySmartPointer destructor" << endl; }
    T &operator*() { return *m_pointer; }
    T *operator->() { return m_pointer; }
};


int main()
{
    {
        mySmartPointer<int> p = new int(42);
        cout << *p << endl;
        mySmartPointer<double> p1 = new double(3.14);
        cout << *p1 << endl;
    }
    cin.get();
    cout << "End of main" << endl;
    return 0;
}