#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QToolTip>
#include <QPainter>
#include <QPixmap>
#include <QBitmap>
#include  "spider.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent* event){//, QKeyEvent* kevent) {

    int x,y, x1, y1;


    Qt::MouseButton button = event->button();
    Qt::KeyboardModifiers but = event->modifiers();
    if(button == Qt::RightButton && but == Qt::ControlModifier){
        x = event->globalPos().x();
        y = event->globalPos().y();
        x1 = event->pos().x();
        y1 = event->pos().y();
      //  sp.setDrawRect(true);
        //this->m_startPoint.setX(x1);
        //this->m_startPoint.setY(y1);
    }

    if(button == Qt::RightButton){
        //x1 = event->pos().x();
        //y1 = event->pos().y();
        sp.setDrawRect(true);
        QPoint m_startPoint(event->pos());
        this->rect2.setTopLeft(m_startPoint);
        //this->m_startPoint.setY(y1);
    }
    if(button == Qt::LeftButton && but == Qt::ShiftModifier){
        sp.setSpiderMove(!sp.getSpiderMove());
       // sp.setSpiderPos(event->pos().x(), event->pos().y());
        sp.spiderPos.setX(event->pos().x());
        sp.spiderPos.setY(event->pos().y());
        qDebug() << sp.getSpiderMove();
    }
    if(sp.getSpiderMove()){
        this->startTimer(10);
        qDebug() << "start";
    }
    //if(!sp.getSpiderMove()){
      //  this->killTimer();
        //qDebug() << "stop";
    //}


    QPoint pos(x, y);
    QString str;
    QTextStream tstream(&str);
    tstream << "x = " << x1;
    tstream << "y = " << y1;

    QToolTip::showText(pos, str);
    qDebug() << button;
   // QBitmap qbmp("./Images_lab2/spider1.bmp");
    //QCursor qcurs1(qbmp, qbmp);
 //this->setCursor(qcurs1);
    //spider sp();
    if(button == Qt::LeftButton){ //рисуем паутину
        sp.setSpider(true);
        this->vecRects.clear();
        //spider::setSpider(true);
         qDebug() << sp.getSpider();
         this->setCursor(*sp.getCursor());
         this->repaint();
    }
   // this->repaint();

}

void Widget::mouseReleaseEvent(QMouseEvent * event){
  sp.setSpider(false);
  //sp.setDrawRect(false);
    //spider::setSpider(false);
  if(sp.getDrawRect()){
  this->vecRects.push_back(this->rect2);
  sp.setDrawRect(false);
  }
  this->setCursor(Qt::CrossCursor);
  this->repaint();

  qDebug() << sp.getSpider();
}

void Widget::mouseMoveEvent (QMouseEvent * event ) {
     QRect rect1 = this->rect();
    if(sp.getSpider() && rect1.contains(event->pos())){
            this->repaint();
        this->setCursor(*sp.getCursor());
}

    if(!rect1.contains(event->pos())){
        this->setCursor(Qt::CrossCursor);

    }

    if(sp.getDrawRect()){
        this->repaint();
    }



}

void Widget::paintEvent(QPaintEvent * event){
    QPixmap spi("./Images_lab2/spider1.bmp"); //паук
    QPainter qp(this);
    QPoint pXYglobal = QCursor::pos();
    QPoint pXY = QWidget::mapFromGlobal(pXYglobal);
   // int moveX = 1;
    //int moveY = 1;
    QRect rect = this->rect();
   // qDebug() << rect;
    if(sp.getSpider()){
        qp.drawLine(rect.topLeft(), pXY);
        qp.drawLine(rect.topRight(), pXY);
        qp.drawLine(rect.bottomLeft(), pXY);
        qp.drawLine(rect.bottomRight(), pXY);
        qp.drawLine(0, rect.height()/2, pXY.x(), pXY.y());
         qp.drawLine(rect.width()/2, 0, pXY.x(), pXY.y());
          qp.drawLine(rect.width(), rect.height()/2, pXY.x(), pXY.y());
           qp.drawLine(rect.width()/2, rect.width(), pXY.x(), pXY.y());
    }
    if(sp.getDrawRect()){
        this->rect2.setBottomRight(pXY);
        qp.drawRect(this->rect2);
        //qp.drawRects(this->vecRects);

    }
    qp.drawRects(this->vecRects);

    if(sp.spiderPos.x() >= rect.width()-5){
       // sp.flagX = !sp.flagX;
    sp.moveX = -1;}
    if( sp.spiderPos.x() <= 1){
     //sp.flagX = !sp.flagX;
     sp.moveX = 1;
    }
     if(sp.spiderPos.y() >= rect.height()-5){
         sp.flagY = !sp.flagY;
        sp.moveY = -1;
     }
     if( sp.spiderPos.y() <= 1){
         sp.moveY = 1;
     }
  // if(sp.flagX){sp.moveX = -1;}
    //else{ sp.moveX = 1;}
    //if(sp.flagY){moveY = -1;}
    //else{moveY = 1;}

     if(sp.getSpiderMove() ){
        sp.spiderPos.setX(sp.spiderPos.x() + sp.moveX);
        sp.spiderPos.setY(sp.spiderPos.y() + sp.moveY);
        this->qpoly.push_back(sp.spiderPos);
       // this->vecPoints.push_back(sp.spiderPos);
        //this->qpoly(this->vecPoints);
        qDebug() << "x=" << sp.spiderPos.x();
        qp.drawPixmap(sp.spiderPos, spi);
        qp.drawPoints(this->qpoly);

    }
}

void Widget::resizeEvent(QResizeEvent *event){
    QString strTitle;
    QTextStream titleStream(&strTitle);
    titleStream << "Width = " << this->width();
    titleStream << "Height = " << this->height();
    this->setWindowTitle(strTitle);
}

void Widget::timerEvent(QTimerEvent *event){
   // sp.setSpiderPos(sp.getSpiderPos()->x() + 5, sp.getSpiderPos()->y() + 5);
    //sp.spiderPos.setX(sp.spiderPos.x() + 1);
    //sp.spiderPos.setY(sp.spiderPos.y() + 1);
    //qDebug() << sp.spiderPos.x();
    //qDebug() << sp.spiderPos.y();
    if(!sp.getSpiderMove()){
        this->killTimer(event->timerId());
        qDebug() << "stop";
    }
    this->repaint();

}
