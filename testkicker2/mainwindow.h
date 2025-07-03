#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_plusTeam1_clicked();

    void on_minusTeam1_clicked();

    void on_plusTeam2_clicked();

    void on_minusTeam2_clicked();

    //int scoreTeam1;

    //int scoreTeam2;

    void on_endButton_clicked();

    void on_startButton_clicked();

    void on_saveAndExitButton_clicked();

    void on_exitWithoutSaveButton_clicked();

    void on_backToGameButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
