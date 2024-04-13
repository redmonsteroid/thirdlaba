#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double p;
    int b = 1; 
    cin >> p;

    while ( (p - 1) % pow (2, b)!= 0 ) {
        b++;
    
    }
    return 0;
}
