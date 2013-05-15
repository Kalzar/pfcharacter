#include "character.h"

Character::Character(QObject *parent) :
    QObject(parent)
{

}

Character::~Character()
{

}

int Character::getAbilityTotal(int id)
{
    QString strQuery = "SELECT base, racial, inherent, enhancement, circumstantial, untyped, luck, temporary FROM ability WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        int abilityTotal(0);
        while(qry.next())
        {
            for (int i(0); i < 9; i++)
            {
                abilityTotal += qry.value(i).toInt();
            }
        }
        return abilityTotal;
    }
    else
    {
        qDebug() << "[E]Unable to execute query";
    }
}

int Character::getAbilityMod(int id)
{
    QString strQuery = "SELECT base, racial, inherent, enhancement, circumstantial, untyped, luck, temporary FROM ability WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        int abilityValue(0);
        while(qry.next())
        {
            for (int i(0); i < 9; i++)
            {
                abilityValue += qry.value(i).toInt();
            }
            abilityValue -= 10;
            abilityValue=floor(abilityValue / 2);
            return abilityValue;
        }
    }
    else
    {
        qDebug() << "[E]Unable to execute query";
    }
}

QString Character::getAbilityName(int id)
{
    QString strQuery = "SELECT name FROM ability WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        while(qry.next())
        {
            return qry.value(0).toString();
        }
    }
    else
    {
        qDebug() << "[E]Unable to execute query";
    }
}

int Character::getSkillTotal(int id)
{
    QString strQuery = "SELECT ability, rank , misc FROM skill WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        int skillTotal(0);
        while(qry.next())
        {
            skillTotal = getAbilityMod(qry.value(0).toInt());
            for (int i(1); i <= 2; i++)
            {
                skillTotal += qry.value(i).toInt();
            }
            if (id == 0)
            {
                qDebug() << "Updating skills";
            }
        }
        return skillTotal;
    }
    else
    {
        qDebug() << "[E]Unable to execute query";
    }
}

bool Character::getSkillIsTrained(int id)
{
    QString strQuery = "SELECT untrained , rank FROM skill WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        while (qry.next())
        {
            if (qry.value(0).toBool() == true || qry.value(1).toInt() > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


QString Character::getSkillName(int id)
{
    QString strQuery = "SELECT name FROM skill WHERE id = :id";
    QSqlQuery qry;
    qry.prepare(strQuery);
    qry.bindValue("id", id);
    if (qry.exec())
    {
        while(qry.next())
        {
            return qry.value(0).toString();
        }
    }
    else
    {
        qDebug() << "[E]Unable to execute query";
    }
}
