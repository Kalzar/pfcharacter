#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "EditAbility.h"
#include "editcombatstats.h"
#include "editgeneralinformation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OEditAbility_clicked()
{
    EditAbility wEditAbility;
    wEditAbility.setModal(true);
    wEditAbility.exec();
}

void MainWindow::on_OEditCombatStats_clicked()
{
    EditCombatStats wEditCombatStats;
    wEditCombatStats.setModal(true);
    wEditCombatStats.exec();
}

void MainWindow::on_OEditGeneralInformation_clicked()
{
    EditGeneralInformation wEditGeneralInformation;
    wEditGeneralInformation.setModal(true);
    wEditGeneralInformation.exec();
}
