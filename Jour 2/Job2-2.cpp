#include <iostream>
#include <string>

// Classe de base Aquatique
class Aquatique {
protected:
    double vitesse_nage;

public:
    Aquatique(double vitesse) : vitesse_nage(vitesse) {}

    virtual void nage() const {
        std::cout << "Je nage à " << vitesse_nage << " m/s." << std::endl;
    }

    virtual ~Aquatique() {}

    void setVitesseNage(double vitesse) {
        vitesse_nage = vitesse;
    }

    double getVitesseNage() const {
        return vitesse_nage;
    }
};

// Classe de base Terrestre
class Terrestre {
protected:
    double vitesse_marche;

public:
    Terrestre(double vitesse) : vitesse_marche(vitesse) {}
    virtual void marche() const {
        std::cout << "Je marche à " << vitesse_marche << " m/s." << std::endl;
    }

    virtual ~Terrestre() {}

    void setVitesseMarche(double vitesse) {
        vitesse_marche = vitesse;
    }

    double getVitesseMarche() const {
        return vitesse_marche;
    }
};

// Classe dérivée Pingouin
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesse_glisse;

public:
    Pingouin(std::string n, double vitesse_nage, double vitesse_marche, double vitesse_glisse)
        : Aquatique(vitesse_nage), Terrestre(vitesse_marche), nom(n), vitesse_glisse(vitesse_glisse) {}

    Pingouin(const Pingouin &autre)
        : Aquatique(autre.vitesse_nage), Terrestre(autre.vitesse_marche), nom(autre.nom), vitesse_glisse(autre.vitesse_glisse) {}

    void sePresenter() const {
        std::cout << "Je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    void nage() const override {
        std::cout << "Le pingouin nage à " << vitesse_nage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << "Le pingouin marche à " << vitesse_marche << " m/s." << std::endl;
    }

    void glisse() const {
        std::cout << "Le pingouin glisse à " << vitesse_glisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double vitesse) {
        vitesse_glisse = vitesse;
    }

    double getVitesseGlisse() const {
        return vitesse_glisse;
    }

    void setNom(const std::string &new_nom) {
        nom = new_nom;
    }

    std::string getNom() const {
        return nom;
    }

    virtual ~Pingouin() {}
};

int main() {
    Pingouin pingouin("Eiser", 2.0, 1.5, 5.0);

    pingouin.sePresenter();
    pingouin.nage();
    pingouin.marche();
    pingouin.glisse();

    pingouin.setVitesseNage(3.0);
    pingouin.setVitesseMarche(2.0);
    pingouin.setVitesseGlisse(6.0);

    std::cout << "\nAprès modification des vitesses :\n";
    pingouin.nage();
    pingouin.marche();
    pingouin.glisse();

    Pingouin pingouin_copie = pingouin;

    std::cout << "\nLe pingouin copié se présente :\n";
    pingouin_copie.sePresenter();
    pingouin_copie.nage();
    pingouin_copie.marche();
    pingouin_copie.glisse();

    return 0;
}
