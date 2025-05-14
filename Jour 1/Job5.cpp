#include <iostream>
using namespace std;

int main() {
    double num1, num2, sum;

    cout << "Entrez le premier nombre : ";
    cin >> num1;

    cout << "Entrez le deuxième nombre : ";
    cin >> num2;

    sum = num1 * num2;

    cout << "La somme de " << num1 << " et " << num2 << " est : " << sum << endl;

    return 0;
}
