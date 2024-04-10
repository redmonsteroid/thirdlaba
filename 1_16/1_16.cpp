#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void PrintTable (double& x, double y){
    cout << "_____________________" << endl;
    if (abs(y) < 0.000001){
        y=0;
    }
    if (abs(x) < 0.000001){
        x=0;
    }

    cout << setw(6) << x << "    |" << setw(11) << y << endl; // красиво 
}
double secondCircle(double& x) {
    double sqrtCheck = 4 - pow(x, 2);

    if (sqrtCheck >= 0) { // Попадаем в nan когда sqrt(0)
        return 2 - sqrt(sqrtCheck);
    } else {
        return 2.0; 
    }
}

int main () {
    double dx = 0.1;
    double xn = -3;
    double xk = 6;
    double y=0;
    cout << "  x          y" << endl;
    while (-3 <= xn && xn < -0.9){
        PrintTable(xn, -1 * xn - 2);
        xn += dx;
    }
    while (-0.9 <= xn && xn < 0){
        PrintTable(xn, sqrt(1-pow(xn,2))-1);
        xn += dx;
    }
    while (0 <= xn && xn <= 2.1){
        PrintTable(xn, secondCircle(xn));
        xn += dx;
    }
    xn-=dx; // в прошлый раз мы дошли до значения 2.1, но у нас разрывается график
    while (2 <= xn && xn <= 4.1){
        PrintTable(xn, -1);
        xn += dx;
    }
    while (4 <= xn && xn <= xk){
        PrintTable(xn, 0.5 * xn - 3);
        xn += dx;
    }
}