#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <cmath>
#include "editability.h"
#include "editskill.h"
#include "editcombatstats.h"
#include "editgeneralinformation.h"
#include "character.h"
#include "editlevel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();



public slots:

private slots:
    void on_OEditAbility_clicked();

    void on_OEditCombatStats_clicked();

    void on_OEditGeneralInformation_clicked();

    void on_actionOpen_activated();

    void updateAbility();

    void updateSkills();

    void on_OEditSkill_clicked();

    void on_OEditLevel_clicked();

private:
    void setSkillLabels();

    Ui::MainWindow *ui;
    QString m_dbPath;
    QSqlDatabase m_characterDB;
    QWidget *mainWindow;
    QLabel *lbAbilityArr[6];
    QLabel *lbSkillArr[35];
    Character character;
};

#endif // MAINWINDOW_H
