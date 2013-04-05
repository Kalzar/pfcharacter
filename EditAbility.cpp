#include "EditAbility.h"
#include "ui_EditAbility.h"

EditAbility::EditAbility(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAbility)
{
    ui->setupUi(this);
}

EditAbility::~EditAbility()
{
    delete ui;
}
