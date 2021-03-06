#ifndef PLAYER_H
#define PLAYER_H
#include <QtCore>
#include <QObject>
#include <QTimer>
#include <QTimerEvent>
#include <QList>
#include "actor.h"
#include "weapon.h"
#include "bullet.h"
#include "health.h"

class Player : public Actor
{
    Q_OBJECT
private:
    //Stores keystrokes for duration of timer
    QSet<Qt::Key> keysPressed;

    //Default keys
    Qt::Key moveUp = Qt::Key_W;
    Qt::Key moveUp2 = Qt::Key_Up;
    Qt::Key moveDown = Qt::Key_S;
    Qt::Key moveDown2 = Qt::Key_Down;
    Qt::Key moveLeft = Qt::Key_A;
    Qt::Key moveLeft2 = Qt::Key_Left;
    Qt::Key moveRight = Qt::Key_D;
    Qt::Key moveRight2 = Qt::Key_Right;
    Qt::Key shoot = Qt::Key_Space;

    //Timer used to update movement and similar actions that should happen on a very fast interval
    QTimer* fastTimer;
    //Timer used for staggered actions that should be continous
    QTimer* slowTimer;



    //Used to track animation frames for movement
    int movedUp = 0;
    int movedLeft = 0;
    int movedRight = 0;
    int movedDown = 0;

    //used to retain movement equivalent to screen size
    double realScaling;
    //personal scaling modifer (used to change picture to manageable size)
    double scaling;

    Weapon* equippedWeapon;
    //Stores collsions
    QList<QGraphicsItem *> collision;

public:
    Player(const QString &fileName, double scaling);
    ~Player();

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    Health* health;
    int getHealth();
    void decrementHealth();
    void incrementHealth();

    void setMoveUp(Qt::Key a);
    void setMoveDown(Qt::Key a);
    void setMoveLeft(Qt::Key a);
    void setMoveRight(Qt::Key a);

    void setMoveUp2(Qt::Key a);
    void setMoveDown2(Qt::Key a);
    void setMoveLeft2(Qt::Key a);
    void setMoveRight2(Qt::Key a);

    void setShoot(Qt::Key a);

    //Used for pause and game over
    void startFastTimer();
    void stopFastTimer();

public slots:
    void keyPressFastAction();
    void keyPressSlowAction();
};

#endif // PLAYER_H
