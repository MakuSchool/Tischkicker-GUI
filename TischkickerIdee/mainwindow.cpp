#include "mainwindow.h"
#include "mainmenu.h"
#include "teamauswahl.h"
#include "teamerstellen.h"
#include "playerstats.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stack = new QStackedWidget(this);
    mainMenu = new MainMenuWidget(this);
    teamAuswahl = new TeamAuswahlWidget(this);
    teamErstellen = new TeamErstellenWidget(this);
    playerStats = new PlayerStatsWidget(this);

    stack->addWidget(mainMenu);      // Index 0
    stack->addWidget(teamAuswahl);   // Index 1
    stack->addWidget(teamErstellen); // Index 2
    stack->addWidget(playerStats);   // Index 3

    setCentralWidget(stack);
    stack->setCurrentWidget(mainMenu);

    setupConnections();
}

MainWindow::~MainWindow() {}

void MainWindow::setupConnections()
{
    connect(mainMenu, &MainMenuWidget::goToTeamAuswahl, [this]() {
        stack->setCurrentWidget(teamAuswahl);
    });

    connect(mainMenu, &MainMenuWidget::goToTeamErstellen, [this]() {
        stack->setCurrentWidget(teamErstellen);
    });

    connect(mainMenu, &MainMenuWidget::goToPlayerStats, [this]() {
        stack->setCurrentWidget(playerStats);
    });

    connect(teamAuswahl, &TeamAuswahlWidget::goToMainMenu, [this]() {
        stack->setCurrentWidget(mainMenu);
    });

    connect(teamErstellen, &TeamErstellenWidget::goToMainMenu, [this]() {
        stack->setCurrentWidget(mainMenu);
    });

    connect(playerStats, &PlayerStatsWidget::goToMainMenu, [this]() {
        stack->setCurrentWidget(mainMenu);
    });
}
