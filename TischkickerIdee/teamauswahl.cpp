#include "teamauswahl.h"
#include <QVBoxLayout>
#include <QPushButton>

TeamAuswahlWidget::TeamAuswahlWidget(QWidget *parent)
    : QWidget(parent)
{
    btnBack = new QPushButton("Zurück");
    btnBack->setStyleSheet("background-color: yellow");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(btnBack,Qt::AlignTop,Qt::AlignRight);
    setLayout(layout);

    connect(btnBack, &QPushButton::clicked, this, &TeamAuswahlWidget::goToMainMenu);
}
