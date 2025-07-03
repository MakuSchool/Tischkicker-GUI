#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QScroller>
#include <QTextEdit>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onToggleList();
    void handleTextChange();
    void filterList(const QString &text);

private:
    QPushButton *toggleButton;
    QListWidget *listWidget;
    QWidget *leftPanel;
    QWidget *rightPanel;
    QTextEdit *textEdit;
    bool allowClose;
};

#endif // MAINWINDOW_H
