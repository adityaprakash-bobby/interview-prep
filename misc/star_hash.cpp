#include <iostream>

using namespace std;

void printPattern(int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i - j < 0) {
                cout << "# ";
            } else {
                cout << "* ";
            }
        }
        cout << "\n";
    }
    return;
}

int main(int argc, char const *argv[])
{
    int sq_size = 5;
    printPattern(sq_size);   
    return 0;
}