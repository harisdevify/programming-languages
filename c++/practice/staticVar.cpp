#include <iostream>
using namespace std;

void counterDemo() {
int auto_var = 0;
static int static_var = 0;
auto_var++;
static_var++;
cout<<"auto_var: "<<auto_var<<"| static_var: "<< static_var<<endl;
}

int main() {
    cout<< "First call: ";
    counterDemo();
    cout<< "\n second call: ";
    counterDemo();
    cout<< "\n third call: ";
    counterDemo();
    return 0;
}
