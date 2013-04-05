#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_OEditAbility_clicked();

    void on_OEditCombatStats_clicked();

    void on_OEditGeneralInformation_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
