#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "sleeptimer.h"

#include <QKeyEvent>
#include <sstream>
#include <string>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    allowClose(false)

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); //Anfangsseite auf 0 (Startseite) setzen, 1 ist die Score-Seite und 2 die Datenuebermittlungsseite

    //Die einzelnen Knoepfe mit den UI-Elementen verbinden
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked); //Startbutton auf der Startseite
    connect(ui->endButton, &QPushButton::clicked, this, &MainWindow::on_endButton_clicked); //"Spiel beenden"-Button auf der Score-Seite
    connect(ui->saveAndExitButton, &QPushButton::clicked, this, &MainWindow::on_saveAndExitButton_clicked); //"Mit Speichern beenden"-Button auf der Datenuebermittlungsseite
    connect(ui->exitWithoutSaveButton, &QPushButton::clicked, this, &MainWindow::on_exitWithoutSaveButton_clicked); //"Ohne Speichern beenden"-Button auf der Datenuebermittlungsseite
    connect(ui->backToGameButton, &QPushButton::clicked, this, &MainWindow::on_backToGameButton_clicked);//"Zurueck zum Spiel"-Button auf der Datenuebermittlungsseite

    ui->lcdTimer->setDigitCount(4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int scoreT1 = 0;
int scoreT2 = 0;

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        allowClose = true;
        close();
    } else {
        event->ignore();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (allowClose) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::on_plusTeam1_clicked()
{

    std::stringstream ss; //string stream initialisieren
    scoreT1++;

    ss << scoreT1; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT1->setText(str); // QLabel Text setzen
}


void MainWindow::on_minusTeam1_clicked()
{
    std::stringstream ss; //string stream initialisieren
    if(scoreT1 > 0) scoreT1--;

    ss << scoreT1; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT1->setText(str); // QLabel Text setzen
}


void MainWindow::on_plusTeam2_clicked()
{
    std::stringstream ss; //string stream initialisieren
    scoreT2++;

    ss << scoreT2; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT2->setText(str); // QLabel Text setzen

}


void MainWindow::on_minusTeam2_clicked()
{
    std::stringstream ss; //string stream initialisieren
    if(scoreT2 > 0) scoreT2--;

    ss << scoreT2; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT2->setText(str); // QLabel Text setzen

}


void MainWindow::on_endButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); //Uebergang von der Score-Seite zur Datenuebermittlungsseite
}


void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); //Uebergang von der Spielerauswahl zur Score-Seite
}


void MainWindow::on_saveAndExitButton_clicked()
{

    //TO DO: Add database stuff here

    scoreT1 = 0;
    scoreT2 = 0;
    std::stringstream ss; //string stream initialisieren

    ss << scoreT2 && scoreT1; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT2->setText(str); // QLabel Text setzen
    ui->scoreDispT1->setText(str); // QLabel Text setzen

    ui->stackedWidget->setCurrentIndex(0); //Uebergang von der Datenuebermittlungsseite zur Spielerauswahlseite

}


void MainWindow::on_exitWithoutSaveButton_clicked()
{
    scoreT1 = 0;
    scoreT2 = 0;
    std::stringstream ss; //string stream initialisieren

    ss << scoreT2 && scoreT1; // variable in den string reinschreiben (umwandeln)
    QString str = QString::fromStdString(ss.str()); // den 'Standard' String in einen QString umwandeln

    ui->scoreDispT2->setText(str); // QLabel Text setzen
    ui->scoreDispT1->setText(str); // QLabel Text setzen

    ui->stackedWidget->setCurrentIndex(0); //Uebergang von der Datenuebermittlungsseite zur Spielerauswahlseite

}


void MainWindow::on_backToGameButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(1); //Uebergang von der Datenuebermittlungsseite zurueck zur Score-Seite
}

