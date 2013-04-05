#include "editcombatstats.h"
#include "ui_editcombatstats.h"

EditCombatStats::EditCombatStats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCombatStats)
{
    ui->setupUi(this);
}

EditCombatStats::~EditCombatStats()
{
    delete ui;
}
