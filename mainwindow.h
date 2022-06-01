#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QStatusBar>
#include <QVBoxLayout>
#include "mywidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
protected slots:
    void onClickedSaveAction();
    void onClickedOpenAction();
    void onClickedNewAction();
    void onClickedWidthAction();
    void onClickedStepAction();
    void onClickedColorAction();
    void onClickedStartAction();
private:
    MyWidget* myWidget;
};
#endif // MAINWINDOW_H
