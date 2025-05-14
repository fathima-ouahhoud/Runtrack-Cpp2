#include <iostream>
using namespace std;

int main() {
    int nombre;

    cout << "Entrez un entier pour afficher sa table de multiplication : ";
    cin >> nombre;

    cout << "Table de multiplication de " << nombre << " :" << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << nombre << " x " << i << " = " << nombre * i << endl;
    }

    return 0;
}
