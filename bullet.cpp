#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet(bool playerMade)
    :Actor(-2,-2,2)
{
    movementTimer = new QTimer();
    connect(movementTimer,SIGNAL(timeout()), this, SLOT(move()));
    this->playerMade = playerMade;

    movementTimer->start(50);
}

void Bullet::move()
{
    //Move away from player
    if(playerMade){
        setPos(x(),y()-10);
        //Remove bullets from scene when they leave screen region then delete
        if(pos().y() < 0 - y()){
            scene()->removeItem(this);
            delete this;
        }
    }
    //Move towards player
    else {
       setPos(x(),y()+10);
       //Remove bullets from scene when they leave screen region then delete
       if(pos().y() > scene()->height()){
           scene()->removeItem(this);
           delete this;
       }
    }
}
