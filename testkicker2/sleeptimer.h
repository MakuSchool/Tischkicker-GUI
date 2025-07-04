#ifndef SLEEPTIMER_H
#define SLEEPTIMER_H


#include <QApplication>
#include <QEvent>
#include <QTimer>
#include <QDebug>
#include <QProcess>

class SleepTimer : public QApplication {
public:
    SleepTimer(int &argc, char **argv) : QApplication(argc, argv) {
        idleTimer.setInterval(10000); // 10 seconds for testing
        connect(&idleTimer, &QTimer::timeout, this, &SleepTimer::onIdleTimeout);
        idleTimer.start();
    }

protected:
    bool event(QEvent *event) override {
        if (event->type() == QEvent::KeyPress ||
            event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseMove) {
            resetIdleTimer();
        }
        return QApplication::event(event);
    }

private:
    QTimer idleTimer;

    void resetIdleTimer() {
        idleTimer.start();
        qDebug() << "Activity detected, resetting timer";
    }

    void onIdleTimeout() {
        qDebug() << "No activity detected, triggering sleep";
        // Call system command to suspend here
        QProcess::execute("systemctl", QStringList() << "suspend");
    }
};

#endif // SLEEPTIMER_H
