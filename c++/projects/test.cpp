#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout << left << setw(10) << "Number"
         << "Marks" << endl;

    cout << setw(10) << "1"
         << "4" << endl;

    cout << setw(10) << "2"
         << "5" << endl;

    cout << setw(10) << "3"
         << "6" << endl;

    return 0;
}
