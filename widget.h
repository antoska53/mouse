#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "spider.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Spider sp;
   // QPoint m_startPoint;
    QRect rect2;
    QVector<QRect> vecRects;
    QPolygon qpoly;
    QVector<QPoint> vecPoints;

protected:
        virtual void mousePressEvent(QMouseEvent *) override;
        virtual void mouseReleaseEvent(QMouseEvent *) override;
        virtual void mouseMoveEvent (QMouseEvent * event ) override;
        virtual void paintEvent(QPaintEvent * event) override;
        virtual void resizeEvent(QResizeEvent * event) override;
        virtual void timerEvent(QTimerEvent *event) override;
};

#endif // WIDGET_H
