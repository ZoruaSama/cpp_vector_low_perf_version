#include<iostream>
#include "Vector.h"

using namespace std;
using namespace zorua::stl;

int main(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v[7] = 3;
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<endl;
    }
    return 0;
}