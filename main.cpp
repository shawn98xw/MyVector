#include "MyVector.h"
using namespace std;

int main() {
    MyVector<int> vec;
    for (int i = 0; i < vec.capacity(); i++)
        vec.push_back(i);
    vec.push_back(10);

    cout << "capacity: " << vec.capacity() << endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec.at(i) << ", ";
    cout << endl;

    vec.insert(0, 5);
    vec.insert(1, 15);
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << endl;

    vec.remove(1);
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << endl;

    cout << "front: " << vec.front() << ", back: " << vec.back() << endl;

    return 0;
}