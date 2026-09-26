#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char filename[] = "file.dat";
    fstream file(filename, ios::in | ios::out | ios::trunc);
    if (!file) {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    cout<< "write to file: ";
    string data;
    getline(cin, data); // getline() reads full line including spaces until ENTER is pressed

    file<< data;
    file.flush();

    file.seekg(0);
    string readdata;
    getline(file, readdata);
    cout<< "The file data is: " <<readdata<< endl;
    file.close();

    return 0;
}
