#include <iostream>
using namespace std;

int main() {
    // Déclaration des variables
    double prixHT, kilos, tva, prixTTC;

    cout << "Entrez le prix HT d'un kilo de carottes (en euros) : ";
    cin >> prixHT;

    cout << "Entrez le nombre de kilos de carottes : ";
    cin >> kilos;

    cout << "Entrez le taux de TVA (ex : pour 15%, tapez 15) : ";
    cin >> tva;

    prixTTC = prixHT * kilos * (1 + tva / 100);

    cout << "Le prix TTC de la marchandise est : " << prixTTC << " euros" << endl;

    return 0;
}
