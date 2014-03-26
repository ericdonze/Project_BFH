#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

class Personnage
{
    public:
        Personnage();
        virtual ~Personnage();

    public:

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();

    private:

    int m_vie;
    int m_mana;
    std::string m_nomArme; //Pas de using namespace std, il faut donc mettrestd:: devant string
    int m_degatsArme;
};

#endif // PERSONNAGE_H
