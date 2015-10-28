#include <QApplication>
#include <qfontdatabase.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QIcon>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int id = QFontDatabase::addApplicationFont(":/fonts/ArialRoundedMTRegular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont arial(family);
    Login *_logForm = new Login();

    a.setWindowIcon(QIcon(":/img/babelicon.png"));
    a.setFont(arial);
    _logForm->show();

    return a.exec();
}
