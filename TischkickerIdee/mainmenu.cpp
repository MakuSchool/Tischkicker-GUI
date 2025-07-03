// mainmenuwidget.cpp
#include "mainmenu.h"
#include <QHBoxLayout>
#include <QPushButton>

MainMenuWidget::MainMenuWidget(QWidget *parent)
    : QWidget(parent)
{
    btnTeamAuswahl = new QPushButton("Team Auswahl");
    btnTeamErstellen = new QPushButton("Team Erstellen");
    btnPlayerStats = new QPushButton("Player Stats");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(btnTeamAuswahl);
    layout->addWidget(btnTeamErstellen);
    layout->addWidget(btnPlayerStats);

    setLayout(layout);

    connect(btnTeamAuswahl, &QPushButton::clicked, this, &MainMenuWidget::goToTeamAuswahl);
    connect(btnTeamErstellen, &QPushButton::clicked, this, &MainMenuWidget::goToTeamErstellen);
    connect(btnPlayerStats, &QPushButton::clicked, this, &MainMenuWidget::goToPlayerStats);
}
