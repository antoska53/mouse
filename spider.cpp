#include "spider.h"
#include <QCursor>
#include<QPixmap>
#include <QBitmap>

Spider::Spider(){
  isDrawing = false;
  isDrawingRect = false;
  spiderMove = false;
  flagX = false;
  flagY = false;
  moveX = 1;
  moveY = 1;
  spiderPos.setX(100);
  spiderPos.setY(100);
  QPixmap qbmp("./Images_lab2/super_spy.bmp");
  spiCursor = new QCursor(qbmp, QBitmap(qbmp));

  //spiCursor = spiCursor2;
  //spiCursor.setShape(qbmp, QBitmap(qbmp));
}

void Spider::setSpider(bool b){
    isDrawing = b;
}

bool Spider::getSpider(){
    return isDrawing;
}

QCursor *Spider::getCursor(){
    return spiCursor;
}

void Spider::setDrawRect(bool r){
    isDrawingRect = r;
}

bool Spider::getDrawRect(){
    return isDrawingRect;
}
void Spider::setSpiderMove(bool s){
    spiderMove = s;
}
bool Spider::getSpiderMove(){
    return spiderMove;
}
void Spider::setSpiderPos(int x, int y){
   // spiderPos->setX(x);
    //spiderPos->setY(y);
}
QPoint* Spider::getSpiderPos(){
    //return spiderPos;
}
