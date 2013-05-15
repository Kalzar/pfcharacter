#ifndef EDITSKILL_H
#define EDITSKILL_H

#include <QDialog>
#include <QtDebug>
#include <QtGui>
#include <QtCore>
#include <QtSql>

namespace Ui {
class EditSkill;
}

class EditSkill : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditSkill(QWidget *parent = 0);
    ~EditSkill();
    
private slots:
    void dbUpdate();

    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::EditSkill *ui;
    QSqlTableModel *skillTable;
};

#endif // EDITSKILL_H
