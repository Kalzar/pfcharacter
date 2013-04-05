#ifndef EDITCOMBATSTATS_H
#define EDITCOMBATSTATS_H

#include <QDialog>

namespace Ui {
class EditCombatStats;
}

class EditCombatStats : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditCombatStats(QWidget *parent = 0);
    ~EditCombatStats();
    
private:
    Ui::EditCombatStats *ui;
};

#endif // EDITCOMBATSTATS_H
