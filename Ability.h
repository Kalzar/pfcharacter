#ifndef DEF_ABILITY
#define DEF_ABILITY
 
#include <string>
 
class Ability
{
    public:

    Ability();
    void changeAbility(int nbChange, std::string bonusType); 
    int getAbility(); 
    private:

    int m_ability[6]; 
};
 
#endif
