#ifndef PLAYERSTATSWIDGET_H
#define PLAYERSTATSWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>

class QPushButton;

class PlayerStatsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerStatsWidget(QWidget *parent = nullptr);

signals:
    void goToMainMenu();

private:
    QPushButton *btnBack;
    QTableWidget *ueberblick;
    QTableWidget *table;
    QLabel *namen;
};

#endif // PLAYERSTATSWIDGET_H
