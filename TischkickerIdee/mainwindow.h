#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QStackedWidget;
class MainMenuWidget;
class TeamAuswahlWidget;
class TeamErstellenWidget;
class PlayerStatsWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget *stack;
    MainMenuWidget *mainMenu;
    TeamAuswahlWidget *teamAuswahl;
    TeamErstellenWidget *teamErstellen;
    PlayerStatsWidget *playerStats;

    void setupConnections();
};

#endif // MAINWINDOW_H
