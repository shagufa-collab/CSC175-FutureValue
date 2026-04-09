#include <iostream> // Double money.cpp
#include <iomanip>
using namespace std;

double calcFutureValue(double monthlyInvestment, double apy, double term) {
    double monthlyRate = apy / 100 /12;
    int months = term * 12;
    double balance =0;

    for (int i = 0; i < months; i++) {
        balance = (balance + monthlyInvestment) * (1 + monthlyRate);

    }
    return balance;
}

double calcDoubleTime (double balance, double apy) {
    double monthlyRate = apy / 100 /12;
    double target = balance * 2;
    int months = 0;

    while (balance < target) {
        balance = balance * (1 + monthlyRate);
        months++;
    }

    return months / 12.0;
}

int main() {
    double monthlyInvestment;
    double apy;
    double term;

    cout << "FUTURE VALUE CALCULAOR\n\n";

    cout << "Enter monthly investment: $";
    cin >> monthlyInvestment;

    cout << "Enter APY for investment: %";
    cin >> apy;

    cout << "Enter term of investment (years): ";
    cin >> term;

    cout << "-------------------------------------\n";

    double futureValue = calcFutureValue(monthlyInvestment, apy, term);
    double doubleTime = calcDoubleTime(1, apy); // better logic

    cout << fixed << setprecision(2);
    cout << "the future value will be $" << futureValue << endl;
    cout << "the account balance would double every "
         << doubleTime << " years." << endl;

    return 0;
}
