#include "playerstats.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QLabel>

PlayerStatsWidget::PlayerStatsWidget(QWidget *parent)
    : QWidget(parent)
{
    btnBack = new QPushButton("Zurück");
    btnBack->setStyleSheet("background-color: yellow");

    namen = new QLabel("Name");
    QLabel *aktuelleseason = new QLabel("Aktuelle Season");
    aktuelleseason->setStyleSheet("font-weight: bold;");

    QHBoxLayout *ueberblick = new QHBoxLayout();
    ueberblick->addWidget(new QLabel("Anzahl Spiele"));
    ueberblick->addWidget(new QLabel("Punkte"));
    ueberblick->addWidget(new QLabel("Tore"));
    ueberblick->addWidget(new QLabel("Gegentore"));
    ueberblick->addWidget(new QLabel("Trueskill"));

    QHBoxLayout *ueberblick2 = new QHBoxLayout();
    ueberblick2->addWidget(new QLabel("253"));
    ueberblick2->addWidget(new QLabel("52325"));
    ueberblick2->addWidget(new QLabel("523525"));
    ueberblick2->addWidget(new QLabel("2552325"));
    ueberblick2->addWidget(new QLabel("252"));

    QLabel *ausfuehrlicheDaten = new QLabel("Ausführliche Daten");
    ausfuehrlicheDaten->setStyleSheet("font-weight: bold;");

    QLabel *roteSeite = new QLabel("Rote Seite");

    QHBoxLayout *statsroteSeite = new QHBoxLayout();
    statsroteSeite->addWidget(new QLabel("MU"));
    statsroteSeite->addWidget(new QLabel("Sigma"));
    statsroteSeite->addWidget(new QLabel("MU Angriff"));
    statsroteSeite->addWidget(new QLabel("MU Verteidigung"));

    QHBoxLayout *statsroteSeite2 = new QHBoxLayout();
    statsroteSeite2->addWidget(new QLabel("23"));
    statsroteSeite2->addWidget(new QLabel("23"));
    statsroteSeite2->addWidget(new QLabel("43"));
    statsroteSeite2->addWidget(new QLabel("35"));

    QLabel *gelbeSeite = new QLabel("Rote Seite");

    QHBoxLayout *statsgelbeseite = new QHBoxLayout();
    statsgelbeseite->addWidget(new QLabel("MU"));
    statsgelbeseite->addWidget(new QLabel("Sigma"));
    statsgelbeseite->addWidget(new QLabel("MU Angriff"));
    statsgelbeseite->addWidget(new QLabel("MU Verteidigung"));

    QHBoxLayout *statsgelbeseite2 = new QHBoxLayout();
    statsgelbeseite2->addWidget(new QLabel("23"));
    statsgelbeseite2->addWidget(new QLabel("23"));
    statsgelbeseite2->addWidget(new QLabel("43"));
    statsgelbeseite2->addWidget(new QLabel("35"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(btnBack,Qt::AlignTop);
    layout->addWidget(namen);
    layout->addSpacing(20);
    layout->addWidget(aktuelleseason);
    layout->addSpacing(10);
    layout->addLayout(ueberblick);
    layout->addLayout(ueberblick2);
    layout->addSpacing(20);
    layout->addWidget(ausfuehrlicheDaten);
    layout->addSpacing(10);
    layout->addWidget(roteSeite);
    layout->addSpacing(10);
    layout->addLayout(statsroteSeite);
    layout->addLayout(statsroteSeite2);
    layout->addWidget(gelbeSeite);
    layout->addSpacing(10);
    layout->addLayout(statsgelbeseite);
    layout->addLayout(statsgelbeSeite2);

    setLayout(layout);

    connect(btnBack, &QPushButton::clicked, this, &PlayerStatsWidget::goToMainMenu);
}
