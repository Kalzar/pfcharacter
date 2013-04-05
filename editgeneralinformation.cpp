#include "editgeneralinformation.h"
#include "ui_editgeneralinformation.h"

EditGeneralInformation::EditGeneralInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGeneralInformation)
{
    ui->setupUi(this);
}

EditGeneralInformation::~EditGeneralInformation()
{
    delete ui;
}
