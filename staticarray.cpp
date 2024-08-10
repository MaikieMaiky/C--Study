#include <algorithm>
#include <array>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    array<string, 3> arr2 = {"one", "two", "three"};
    for (const auto& element : arr2)
    {
        cout << element << " ";
    }
    cout << endl;
    cout << sizeof(arr) << endl;
    return 0;
}