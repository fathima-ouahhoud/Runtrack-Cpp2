#include <iostream>
using namespace std;

int main() {
    int valeur;
    double somme = 0;

    for (int i = 1; i <= 5; ++i) {
        cout << "Entrez l'entier n°" << i << " : ";
        cin >> valeur;
        somme += valeur;
    }

    cout << "La moyenne des 5 entiers est : " << somme / 5 << endl;

    return 0;
}
