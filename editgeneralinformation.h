#ifndef EDITGENERALINFORMATION_H
#define EDITGENERALINFORMATION_H

#include <QDialog>

namespace Ui {
class EditGeneralInformation;
}

class EditGeneralInformation : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditGeneralInformation(QWidget *parent = 0);
    ~EditGeneralInformation();
    
private:
    Ui::EditGeneralInformation *ui;
};

#endif // EDITGENERALINFORMATION_H
