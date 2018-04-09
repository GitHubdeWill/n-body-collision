#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPainter>

#include "envmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    EnvModel model;  // For GUI/Model interaction
    bool isPlaying;

    int fps;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initGUI();
    void makeLabel(Entity* e);

private:
    Ui::MainWindow *ui;

signals:

private slots:
    void timerHit();
};

#endif // MAINWINDOW_H
