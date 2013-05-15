#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QtCore>
#include <QtSql>

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = 0);
    ~Character();
    QString getAbilityName(int id);
    int getAbilityTotal(int id);
    int getAbilityMod(int id);
    QString getSkillName(int id);
    int getSkillTotal(int id);
    bool getSkillIsTrained(int id);
signals:
    
public slots:
    
private:

};

#endif // CHARACTER_H
