#ifndef CUSTOMSCROLLBAR_H
#define CUSTOMSCROLLBAR_H

#include <QScrollBar>
#include <QPaintEvent>
#include <QRegion>
#include <QStyleOptionSlider>
#include <QListWidget>

class CustomScrollBar : public QScrollBar
{

Q_OBJECT
public:
explicit CustomScrollBar(QListWidget *parent = 0);

protected:
void showEvent ( QShowEvent * event );
signals:

public slots:
void updateMask();
};

#endif // CUSTOMSCROLLBAR_H
