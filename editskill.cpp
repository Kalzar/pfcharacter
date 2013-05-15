#include "editskill.h"
#include "ui_editskill.h"

EditSkill::EditSkill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSkill)
{
    ui->setupUi(this);

    skillTable = new QSqlTableModel(this);
    skillTable->setTable("skill");
    skillTable->select();
    skillTable->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(skillTable);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setColumnHidden(3, true);
    ui->tableView->setColumnHidden(5, true);
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() ^ Qt::ItemIsEditable);
    connect(ui->pushButtonOK, SIGNAL(clicked()), this, SIGNAL(accepted()));
    connect(this, SIGNAL(accepted()), this, SLOT(dbUpdate()));
}

void EditSkill::dbUpdate()
{
    skillTable->submitAll();
}

EditSkill::~EditSkill()
{
    delete ui;
}

void EditSkill::on_pushButtonOK_clicked()
{
    this->close();
}

void EditSkill::on_pushButtonCancel_clicked()
{
    this->close();
}
