#include <iostream>
#include "Vector.h"
#include "StackVector .h"

using namespace std;

int main() {

      StackVector<int> a(50);

      a.push(1);
      a.push(2);
      a.push(3);
      a.push(4);

    for (int i = 0; i < 4; ++i) {
        cout << a.top() << endl;
        a.pop() ;
    }


    return 0;
}
