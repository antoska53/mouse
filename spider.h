#ifndef SPIDER
#define SPIDER
#include <QCursor>

class Spider{
   private:
    bool isDrawing;
    bool isDrawingRect;
    bool spiderMove;

    //QPoint* spiderPos;
    QCursor* spiCursor;
public:
    bool flagX;
    bool flagY;
    int moveX;
    int moveY;
    QPoint spiderPos;
    Spider();
    void setSpider(bool b);
    bool getSpider();
    void setDrawRect(bool r);
    bool getDrawRect();
    void setSpiderMove(bool s);
    bool getSpiderMove();
    void setSpiderPos(int x, int y);
    QPoint* getSpiderPos();
    QCursor* getCursor();
};
#endif // SPIDER

