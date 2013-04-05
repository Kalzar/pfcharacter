/*
 * this is where we modify the different bonus for a statistic which are by default
 * Strenght, Dexterity, Constitution, Intelligence, Wisdom and Charisma
 */

#include "Ability.h"
 
using namespace std;

/*
 * Untill I find a better way to initialize an array in the constructor
 * Anyway, this sets the arraway which contains the ability scores and bonus for each stats
 */ 

Ability::Ability()
{
    m_ability[0] = 0;
    for ( int i(0); i < 2; i++)
    {
        m_ability[i] = 0;
    }
}

void Ability::changeAbility(int nbChange, string bonusType)
{
    /* What kind of bonus is it? */
    if ( bonusType == "base" )
    {
        m_ability[0] = nbChange;
    }
    else if ( bonusType == "racial" )
    {
        m_ability[1] = nbChange;
    }
    else if ( bonusType == "inherent" )
    {
        m_ability[2] = nbChange;
    }
    else if ( bonusType == "enhancement" )
    {
        m_ability[3] = nbChange;
    }
    else if ( bonusType == "circumstantial" )
    {
        m_ability[4] = nbChange;
    }
    /* Untyped Bonus */
    else
    {
        m_ability[5] = nbChange;
    }
}

int Ability::getAbility()
{

}
