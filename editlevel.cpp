#include "editlevel.h"
#include "ui_editlevel.h"

EditLevel::EditLevel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditLevel)
{
    ui->setupUi(this);
}

EditLevel::~EditLevel()
{
    delete ui;
}
