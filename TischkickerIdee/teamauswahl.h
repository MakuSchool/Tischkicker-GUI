#ifndef TEAMAUSWAHLWIDGET_H
#define TEAMAUSWAHLWIDGET_H

#include <QWidget>
class QPushButton;

class TeamAuswahlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TeamAuswahlWidget(QWidget *parent = nullptr);

signals:
    void goToMainMenu();

private:
    QPushButton *btnBack;
};

#endif // TEAMAUSWAHLWIDGET_H
