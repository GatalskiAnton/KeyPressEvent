#include "mainwindow.h"
#include "XYdialog.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    myWidget = new MyWidget(this);

    QMenu* file = new QMenu("File", this);
    QMenu* others = new QMenu("Others", this);
    QAction* saveAction = new QAction("Save as", this);
    QAction* openAction = new QAction("Open", this);
    QAction* newAction = new QAction("New", this);
    QAction* widthAction = new QAction("Change width", this);
    QAction* stepAction = new QAction("Change step", this);
    QAction* colorAction = new QAction("Change color", this);
    QAction* startAction = new QAction("Change start pos", this);

    QMenuBar* bar = new QMenuBar(this);
    file->addAction(saveAction);
    file->addAction(openAction);
    file->addAction(newAction);

    others->addAction(widthAction);
    others->addAction(stepAction);
    others->addAction(colorAction);
    others->addAction(startAction);


    bar->addMenu(file);
    bar->addMenu(others);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(bar);
    mainLayout->addWidget(myWidget);

    connect(saveAction, SIGNAL(triggered()), SLOT(onClickedSaveAction()));
    connect(openAction, SIGNAL(triggered()), SLOT(onClickedOpenAction()));
    connect(newAction, SIGNAL(triggered()), SLOT(onClickedNewAction()));

    connect(widthAction, SIGNAL(triggered()), SLOT(onClickedWidthAction()));
    connect(stepAction, SIGNAL(triggered()), SLOT(onClickedStepAction()));
    connect(colorAction, SIGNAL(triggered()), SLOT(onClickedColorAction()));
    connect(startAction, SIGNAL(triggered()), SLOT(onClickedStartAction()));

    myWidget->setFocus();
    this->setCentralWidget(myWidget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::onClickedSaveAction()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), "img.png");
    int pos = fileName.lastIndexOf('.');
    pos++;
    int nLen = fileName.length() - pos;
    QString strSuffix = fileName.right(nLen);
    QPixmap pixmap = QPixmap::grabWidget(this, 0, height() /35, width(), height());
    pixmap.save(fileName, strSuffix.toUpper().toUtf8());
}

void MainWindow::onClickedOpenAction()
{
    QString openFile = QFileDialog::getOpenFileName();
    QImage img;
    img.load(openFile);
    myWidget->setPix(QPixmap::fromImage(img));
    myWidget->setPix(myWidget->getPix().scaled(width(), height()));
}

void MainWindow::onClickedNewAction()
{
    QVector<QLine> newLines;
    myWidget->setLines(newLines);
}

void MainWindow::onClickedWidthAction()
{
    bool ok;
    myWidget->setPen(myWidget->getPen().color(), QInputDialog::getInt(this, tr("Width"), tr("Width"), 25, 0, 100, 1, &ok));
}

void MainWindow::onClickedStepAction()
{
    bool ok;
    myWidget->setStep(QInputDialog::getInt(this, tr("Step"), tr("Step"), 25, 0, 100, 1, &ok));

}

void MainWindow::onClickedColorAction()
{
    myWidget->setPen(QColorDialog::getColor(), myWidget->getPen().width());
}

void MainWindow::onClickedStartAction()
{
    XYdialog* d = new XYdialog(this);
    if (d->exec() == QDialog::Accepted)
    {
        myWidget->setStartPos(QPoint(width() / 2 + d->getX(), height() / 2 - d->getY()));
    }
}
