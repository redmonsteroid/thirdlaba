#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Объявление функций
void cofe(double tempAir, double tempCoffee, double cooling, double maxTime, vector<double>& cofe);
double aproxA(const vector<double>& Cofe);
double aproxB(const vector<double>& Cofe, double a);
double Correlation(const vector<double>& Cofe);

int main() {
    cout << "Enter temperature of air, coffee, cooling coefficient, and max time to cool in minutes: ";
    double tempAir, tempCoffee, cooling, maxTime;
    cin >> tempAir >> tempCoffee >> cooling >> maxTime;
    vector<double> cofeData;

    cofe(tempAir, tempCoffee, cooling, maxTime, cofeData); // Вычисление температур кофе во времени
    cout << setw(10) << "Time" << setw(15) << "Temperature" << endl;

    for (int i = 0; i < maxTime; ++i) { // Вывод таблицы зависимости температуры кофе от времени
        double time = i;
        double temperature = cofeData[i];
        cout << setw(10) << time << setw(15) << temperature << endl;
    }
    double a = aproxA(cofeData);
    double b = aproxB(cofeData, a);
    cout << "Line of approximation: T(t) = " << a << " * t + " << b << endl;
    double correlation = Correlation(cofeData);
    cout << "Correlation coefficient: " << correlation << endl;

    return 0;
}

// Функция для вычисления температуры кофе во времени с учетом охлаждения
void cofe(double tempAir, double tempCoffee, double cooling, double maxTime, vector<double>& cofe) {
    for (int i = 0; i < maxTime; i++) {
        cofe.push_back(tempCoffee);
        tempCoffee = tempCoffee - cooling * (tempCoffee - tempAir);
    }
}

double aproxA(const vector<double>& Cofe) {
    double sumT = 0.0, sumTime = 0.0, sumTTime = 0.0, sumTime2 = 0.0;
    int n = Cofe.size();

    for (int i = 0; i < n; i++) { // метод наименьших квадратов
        sumT += Cofe[i];
        sumTime += i;
        sumTTime += Cofe[i] * i;
        sumTime2 += i * i;
    }

    double slope = (n * sumTTime - sumT * sumTime) / (n * sumTime2 - sumTime * sumTime); // Вычисление коэффициента a (наклона линии аппроксимации)
    return slope;
}
double aproxB(const vector<double>& Cofe, double a) {// пересечения линии аппроксимации с осью времени на основе коэффициента a и среднего значения температур.
    double sumT = 0.0;
    int n = Cofe.size();

    for (int i = 0; i < n; i++) {
        sumT += Cofe[i];
    }

    double intercept = (sumT - a * (n - 1) * n / 2) / n;
    return intercept;
}

double Correlation(const vector<double>& Cofe) {
    int len = Cofe.size();
    double sumTemper = 0.0;
    for (double T : Cofe) {
        sumTemper += T;
    }
    double TMedium = sumTemper / len;

    double tMedium = (len - 1) * len / 2;
    double sumNumbers = 0.0;
    double tSumSquare = 0.0;
    double TSumSquare = 0.0;

    for (int i = 0; i < len; i++) { // Вычисление числителя и знаменателя формулы корреляции.
        double deviationTime = i - tMedium;
        double deviationTemp = Cofe[i] - TMedium;

        sumNumbers += deviationTime * deviationTemp;
        tSumSquare += deviationTime * deviationTime;
        TSumSquare += deviationTemp * deviationTemp;
    }

    double correlation = sumNumbers / sqrt(tSumSquare * TSumSquare); // Вычисление коэффициента корреляции по формуле Пирсона.
    return correlation;
}
