#include <iostream>
#include <cstring>
using namespace std;


// be care of the edge of the array memory
// need safe check
int main()
{
    int arr[5] = { 0 };
    // use < not <= because of performance and visiable
    for (int i = 0; i < 5; i++)
        cout << arr[i] << endl;
    int* another = new int [5];
    delete[] another;
    const char* name = "Jack";
    cout << name << endl;
    const char name2[8] = "bir\0d";
    cout << name2 << endl;
    cout << "length of name2: " << strlen(name2) << endl;
}