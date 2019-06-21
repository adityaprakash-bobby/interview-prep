#include <iostream>

using namespace std;

void func(int (*arr)[3], int m, int n) {

    for (auto i = 0; i < m; i++) {

        for (auto j = 0; j < n; j++) {
            printf("%d ", *(*(arr + i) + j));
        }

        printf("\n");

    }

}

int main(int argc, char const *argv[])
{
    int arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    
    func(arr, 2, 3);

    return 0;
}
