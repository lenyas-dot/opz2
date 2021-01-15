#include <iostream>
#include "methods.h"

using namespace std;

int main() {
    
    char* str = new char[1000];

    cin.getline(str, 1000);

    float a = mainLogic(str);

    cout << a;

    return 0;
}
