#include "mainwindow.h"
#include <QApplication>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
    toggleButton(new QPushButton("Spieler anzeigen", this)),
    listWidget(new QListWidget(this)),
    leftPanel(new QWidget(this)),
    rightPanel(new QWidget(this)),
    allowClose(false)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->setContentsMargins(10, 10, 10, 10);
    leftLayout->setSpacing(5);

    toggleButton->setText("▼ Spieler anzeigen");
    toggleButton->setFixedSize(180, 40);
    toggleButton->setStyleSheet(
        "background: #f0f0f0;"
        "border: none;"
        "color: #000000;"
        );
    leftLayout->addWidget(toggleButton, 0, Qt::AlignTop);

    listWidget->setVisible(false);

    listWidget->setStyleSheet(
        "QListWidget { background: #f0f0f0; border: none; } "
        "QListWidget::item:selected { background: #daeafc; }"
        "QListWidget::item { border: 1px solid black; padding: 4px; }"
        );

    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    listWidget->setSelectionMode(QListWidget::NoSelection);

    listWidget->setDragEnabled(true);
    listWidget->setDragDropMode(QAbstractItemView::DragOnly);

    listWidget->setUniformItemSizes(true);

    textEdit = new QTextEdit();
    textEdit->setFixedSize(180, 40);
    this->textEdit = textEdit;
    textEdit->setPlaceholderText("Spieler suchen ...");
    connect(textEdit, &QTextEdit::textChanged, this, [=]() {
        this->filterList(textEdit->toPlainText());
    });

    const QSize tileSize(180, 60);
    for (int i = 1; i < 100; i++) {
        QListWidgetItem *item = new QListWidgetItem(QStringLiteral("Spieler %1").arg(i), listWidget);
        item->setSizeHint(tileSize);
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(item->flags() | Qt::ItemIsDragEnabled);
        listWidget->addItem(item);
    }

    leftLayout->addWidget(listWidget, 1);

    leftLayout->addWidget(textEdit, Qt::AlignBottom);

    leftPanel->setLayout(leftLayout);
    leftPanel->setFixedWidth(200);

    leftPanel->setStyleSheet("background: #222222;");
    rightPanel->setStyleSheet("background: #222222;");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(leftPanel);
    mainLayout->addWidget(rightPanel, 1);
    setLayout(mainLayout);

    QScroller::grabGesture(listWidget->viewport(), QScroller::TouchGesture);
    QScroller::grabGesture(listWidget->viewport(), QScroller::LeftMouseButtonGesture);

    QScroller *scroller = QScroller::scroller(listWidget->viewport());

    QScrollerProperties props = scroller->scrollerProperties();
    props.setScrollMetric(QScrollerProperties::MaximumVelocity,
                          QVariant(0.05));
    props.setScrollMetric(QScrollerProperties::DecelerationFactor,
                          QVariant(0.03));
    props.setScrollMetric(QScrollerProperties::DragVelocitySmoothingFactor,
                          QVariant(0.4));
    props.setScrollMetric(QScrollerProperties::HorizontalOvershootPolicy,
                          QVariant(QScrollerProperties::OvershootAlwaysOff));

    scroller->setScrollerProperties(props);

    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::onToggleList);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onToggleList()
{
    bool opened = listWidget->isVisible();

    listWidget->setVisible(!opened);
    textEdit  ->setVisible(!opened);

    if (opened) {
        leftPanel->setStyleSheet("background: #222222;");
        toggleButton->setText("▼ Spieler anzeigen");
    } else {
        leftPanel->setStyleSheet("background: #f0f0f0;");
        toggleButton->setText("▲ Spieler verbergen");
    }
}

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

void MainWindow::filterList(const QString &text)
{
    for (int i = 0; i < listWidget->count(); ++i) {
        QListWidgetItem *item = listWidget->item(i);
        item->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
    }
}

void MainWindow::handleTextChange()
{
    filterList(textEdit->toPlainText());
}
