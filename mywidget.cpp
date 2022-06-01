#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent)
    : QWidget{ parent }
{
    startPos = QPoint(300, 350);
    currentPos = QPoint(startPos);
    pen = QPen(Qt::black, 1);
    step = 10;
}

void MyWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(pen);

    painter.drawTiledPixmap(0, 0, width(), height(), pix);
    for (int i = 0; i < lines.size(); ++i)
    {
        painter.setPen(pens[i]);
        painter.drawLine(lines[i]);
    }
}
void MyWidget::keyPressEvent(QKeyEvent* event)
{
    QPoint startPos = currentPos;
    QPoint endPos;

    switch (event->key())
    {
    case Qt::Key_Right:
        currentPos.rx() += step;
        repaint();
        break;
    case Qt::Key_Left:
        currentPos.rx() -= step;
        update();
        break;
    case Qt::Key_Up:
        currentPos.ry() -= step;
        update();
        break;
    case Qt::Key_Down:
        currentPos.ry() += step;
        update();
        break;
    }
    if (currentPos.rx() - width() / 2 < width() / 2 && currentPos.ry() - height() / 2 < height() / 2)
    {
        endPos = currentPos;
        lines.push_back(QLine(startPos, endPos));
        pens.push_back(pen);
    }
    update();
}

void MyWidget::setPix(QPixmap pix_)
{
    pix = pix_;
}
QPixmap MyWidget::getPix()
{
    return pix;
}

void MyWidget::setLines(QVector<QLine> lines_)
{
    lines = lines_;
}

QVector<QLine> MyWidget::getLines()
{
    return lines;
}

void MyWidget::setPen(QColor color, int size)
{
    pen.setColor(color);
    pen.setWidth(size);
}

QPen MyWidget::getPen()
{
    return pen;
}

void MyWidget::setStep(int step_)
{
    step = step_;
}

void MyWidget::setStartPos(QPoint startPos_)
{
    currentPos = startPos_;
}
