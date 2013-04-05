#ifndef EDITABILITY_H
#define EDITABILITY_H

#include <QDialog>

namespace Ui {
class EditAbility;
}

class EditAbility : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditAbility(QWidget *parent = 0);
    ~EditAbility();


    public slots:

private:
    Ui::EditAbility *ui;
};

#endif // EDITABILITY_H
