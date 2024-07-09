#include "myArray.h"

int main() {
    int n;
    std::cin >> n;
    if (!(n > 0 && n < 100)) {
        return 1;
    }

    myDynArray myObj = myDynArray(n);

    myObj.fillManually();

    std::cout << myObj.getIndex();
}