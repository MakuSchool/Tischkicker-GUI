#ifndef TEAMERSTELLENWIDGET_H
#define TEAMERSTELLENWIDGET_H

#include <QWidget>
class QPushButton;

class TeamErstellenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TeamErstellenWidget(QWidget *parent = nullptr);

signals:
    void goToMainMenu();

private:
    QPushButton *btnBack;
};

#endif // TEAMERSTELLENWIDGET_H
