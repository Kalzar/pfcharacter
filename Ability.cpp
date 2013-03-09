#include "Personnage.h"
 
using namespace std;
 
class Ability
{

    Ability::Ability() : m_ability[4] = {10,0,0,0};
    {

    }

    void Ability::changeAbility(int nbChange, string bonusType)
    {
        if ( bonusType == base )
        {
            m_ability[0] = nbChange;
        }
        else if ( bonusType == racial )
        {
            m_ability[1] = nbChange;
        }
        else if ( bonusType == inherent )
        {
            m_ability[2] = nbChange;
        }
        else if ( bonusType == enhancement )
        {
            m_ability[3] = nbChange;
        }
        else
        {
            m_ability[4] = nbChange;
        }
    }
    
    int Ability::getAbility

}
