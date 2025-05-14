#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Classe Aquatique
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

// Classe Pingouin des classes Aquatique et Terrestre
class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesse_glisse;

public:
    static std::vector<std::shared_ptr<Pingouin>> pingouins_instancies;

    Pingouin(std::string n, double vitesse_nage, double vitesse_marche, double vitesse_glisse)
        : Aquatique(vitesse_nage), Terrestre(vitesse_marche), nom(n), vitesse_glisse(vitesse_glisse) {
        pingouins_instancies.push_back(std::shared_ptr<Pingouin>(this)); // Ajout au vector
    }

    Pingouin(const Pingouin &autre)
        : Aquatique(autre.vitesse_nage), Terrestre(autre.vitesse_marche), nom(autre.nom), vitesse_glisse(autre.vitesse_glisse) {
        pingouins_instancies.push_back(std::shared_ptr<Pingouin>(this)); // Ajout au vector
    }

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

    double tempsDeParcours() const {
        // Distances pour chaque section
        double distance_glisse = 15.0;
        double distance_plat1 = 20.0;
        double distance_nage = 50.0;
        double distance_plat2 = 15.0;

        // Calcul du temps pour chaque section
        double temps_glisse = distance_glisse / vitesse_glisse;
        double temps_plat1 = distance_plat1 / vitesse_marche;
        double temps_nage = distance_nage / vitesse_nage;
        double temps_plat2 = distance_plat2 / vitesse_marche;

        // Temps total
        return temps_glisse + temps_plat1 + temps_nage + temps_plat2;
    }

    static void afficherTempsParcours() {
        std::sort(pingouins_instancies.begin(), pingouins_instancies.end(),
            [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
                return a->tempsDeParcours() < b->tempsDeParcours(); // Comparaison des temps de parcours
            });

        for (const auto& pingouin : pingouins_instancies) {
            std::cout << "Pingouin: " << pingouin->nom << ", Temps de parcours: " << pingouin->tempsDeParcours() << " secondes" << std::endl;
        }
    }

    virtual ~Pingouin() {
        // Retirer l'instance du vector lors de la destruction
        pingouins_instancies.erase(
            std::remove_if(pingouins_instancies.begin(), pingouins_instancies.end(),
                           [this](const std::shared_ptr<Pingouin> &p) { return p.get() == this; }),
            pingouins_instancies.end()
        );
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::pingouins_instancies;

int main() {
    std::shared_ptr<Pingouin> p1 = std::make_shared<Pingouin>("Oswald", 2.0, 1.5, 5.0);
    std::shared_ptr<Pingouin> p2 = std::make_shared<Pingouin>("Chesterfield", 2.5, 1.8, 4.5);
    std::shared_ptr<Pingouin> p3 = std::make_shared<Pingouin>("Cobblepot", 3.0, 2.0, 6.0);

    std::cout << "\nTemps de parcours trié de tous les pingouins :" << std::endl;
    Pingouin::afficherTempsParcours();

    return 0;
}