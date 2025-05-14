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
};

// Classe dérivée Pingouin
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;

public:
    Pingouin(std::string n, double vitesse_nage, double vitesse_marche)
        : Aquatique(vitesse_nage), Terrestre(vitesse_marche), nom(n) {}

    void sePresenter() const {
        std::cout << "Je suis un pingouin et je m'appelle " << nom << "." << std::endl;
    }

    void nage() const override {
        std::cout << "Le pingouin nage à " << vitesse_nage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << "Le pingouin marche à " << vitesse_marche << " m/s." << std::endl;
    }
};

int main() {
    Pingouin pingouin("Pingo", 2.0, 1.5);
    pingouin.sePresenter();
    pingouin.nage();
    pingouin.marche();

    return 0;
}
