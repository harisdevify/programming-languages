#include <iostream>
using namespace std;

void counterDemo() {
    // This variable is recreated every time the function is called
    int normalVar = 0;

    // This variable is initialized only once and retains its value
    static int staticVar = 0;

    normalVar++;
    staticVar++;

    cout << "Normal: " << normalVar << " | Static: " << staticVar << endl;
}

int main() {
    cout << "First Call:" << endl;
    counterDemo();

    cout << "\nSecond Call:" << endl;
    counterDemo();

    cout << "\nThird Call:" << endl;
    counterDemo();

    return 0;
}
