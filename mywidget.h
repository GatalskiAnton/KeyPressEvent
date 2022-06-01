#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QPixMap>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget* parent = nullptr);
    void setPix(QPixmap);
    QPixmap getPix();
    void setLines(QVector<QLine>);
    QVector<QLine> getLines();
    void setPen(QColor color = Qt::black, int size = 1);
    QPen getPen();
    void setStep(int);
    void setStartPos(QPoint);

signals:

protected:
    void paintEvent(QPaintEvent*) override;
    void keyPressEvent(QKeyEvent*) override;

private:
    QString str;
    QPen pen;
    QPoint currentPos;
    QPoint startPos;
    QLine currentLine;
    QVector<QLine> lines;
    QPixmap pix;
    QVector<QPen> pens;
    int step;
};

#endif // MYWIDGET_H
