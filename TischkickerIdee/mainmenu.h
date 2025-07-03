// mainmenuwidget.h
#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

class QPushButton;

class MainMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenuWidget(QWidget *parent = nullptr);

signals:
    void goToTeamAuswahl();
    void goToTeamErstellen();
    void goToPlayerStats();

private:
    QPushButton *btnTeamAuswahl;
    QPushButton *btnTeamErstellen;
    QPushButton *btnPlayerStats;
};

#endif // MAINMENUWIDGET_H
