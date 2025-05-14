#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Entrez le premier entier : ";
    cin >> a;

    cout << "Entrez le deuxième entier : ";
    cin >> b;

    cout << "Entrez le troisième entier : ";
    cin >> c;

    int max;

    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    cout << "Le plus grand nombre est : " << max << endl;

    return 0;
}
