#ifndef DEF_ABILITY
#define DEF_ABILITY
 
#include <string>
 
class Ability
{
    public:

    Ability();
    void Ability::changeAbility(int nbChange, string bonusType); 
    bool estVivant();
 
    private:

    int m_ability[5] 
};
 
#endif
