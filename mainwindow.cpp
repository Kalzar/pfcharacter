#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i(0); i<6; i++)
    {
        lbAbilityArr[i] = new QLabel(this);
        ui->abilityVerticalLayout->addWidget(lbAbilityArr[i]);
    }
    for (int i(0); i<34; i++)
    {
        lbSkillArr[i] = new QLabel(this);
        ui->skillVerticalLayout->addWidget(lbSkillArr[i]);
    }
    ui->tabWidget->setEnabled(false);
    setSkillLabels();
}

void MainWindow::setSkillLabels()
{

}

MainWindow::~MainWindow()
{
    m_characterDB.close();
    delete ui;
}

void MainWindow::on_OEditAbility_clicked()
{
    /* Open a Dialog to update ability, when the OK button is clicked, an accepted signal is sent */
    EditAbility wEditAbility(this);
    wEditAbility.setModal(true);
    connect(&wEditAbility, SIGNAL(accepted()), this, SLOT(updateAbility()));
    wEditAbility.exec();
}

void MainWindow::on_OEditSkill_clicked()
{
    EditSkill wEditSkill(this);
    wEditSkill.setModal(true);
    connect(&wEditSkill, SIGNAL(accepted()), this, SLOT(updateSkills()));
    wEditSkill.exec();
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

void MainWindow::on_actionOpen_activated()
{
    /* Get the path of the database file and put it in m_dbPath */
    m_dbPath = QFileDialog::getOpenFileName(this, tr("Open Character"), "", tr("Files (*.pfchar)"));

    /* Open databaswe connection */
    m_characterDB = QSqlDatabase::addDatabase("QSQLITE");
    m_characterDB.setDatabaseName(m_dbPath);
    QFileInfo checkFile(m_dbPath);

    /* Check if the files is exist then if it's open, if not trow error with qDebug */
    if(checkFile.isFile())
    {
        if(m_characterDB.open())
        {
            ui->tabWidget->setEnabled(true);
            updateAbility();
        }
    }
    else
    {
        qDebug() << "[E]File does not exist";
    }
}

void MainWindow::updateAbility()
{
    /* Pass trough all the ability id (from str to cha) */
    int abilityTotal(0);
    double abilityMod(0);
    QString abilityName;
    for (int i(0); i<6; i++)
    {
        abilityName = character.getAbilityName(i);
        abilityMod = character.getAbilityMod(i);
        abilityTotal = character.getAbilityTotal(i);
        QString showValue = QString ("%1: Total: %2 || Mod: %3").arg(abilityName).arg(abilityTotal).arg(abilityMod);
        lbAbilityArr[i]->setText(showValue);
    }
    updateSkills();
}

void MainWindow::updateSkills()
{
    int j(0);
    /* Pass trough all the skills id */
    for(int i(0); i<34; i++)
    {
        if(character.getSkillIsTrained(i) == true)
        {
            lbSkillArr[j]->setText(QString ("%1: %2").arg(character.getSkillName(i)).arg(character.getSkillTotal(i)));
            j++;
        }
    }
}

void MainWindow::on_OEditLevel_clicked()
{
    EditLevel wEditLevel;
    wEditLevel.setModal(true);
    wEditLevel.exec();
}
