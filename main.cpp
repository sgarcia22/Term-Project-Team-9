#include <QApplication>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QGraphicsView>
#include <QtCore>
#include "state.h"
#include "actor.h"
#include "player.h"
#include "bullet.h"
#include "gameloop.h"
#include "mainMenu.h"


gameLoop * globalGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    globalGame = new gameLoop(0, 0);

    globalGame->show();

    globalGame->displayMainMenu();

    return a.exec();


}
