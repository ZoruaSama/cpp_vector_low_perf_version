#include <iostream>
#include <string>
#include <vector>
#include "Vector.h"


using namespace std;
using namespace zorua::stl;

int main()
{
    vector<int> vec;
    Vector<int> v;
    for (int i = 0; i < 5; ++i){
        v.push_back(i);
        cout << v[i] << " " << v.capacity() << endl;
    }
    cout << "v.reverse()" << endl;
    v.reverse();
    for (int i = 0; i < 5; ++i){
        cout << v[i] << " " << v.capacity() << endl;
    }
    cout << "Test for Iterator" << endl;
    for (Vector<int>::Iterator it = v.begin(); it != v.end(); it++){
        cout << (*it) << endl;
    }
    cout << "Test for cout" << endl;
    cout << v << endl;
    v.clear();
    v.push_back(135);

    Vector<string> vs;
    vs.push_back("123");
    vs.push_back("456");
    vs.push_back("789");
    vs.push_back("10 11 12");
    cout << vs << endl;
    return 0;
}