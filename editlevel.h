#ifndef EDITLEVEL_H
#define EDITLEVEL_H

#include <QDialog>

namespace Ui {
class EditLevel;
}

class EditLevel : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditLevel(QWidget *parent = 0);
    ~EditLevel();
    
private:
    Ui::EditLevel *ui;
};

#endif // EDITLEVEL_H
