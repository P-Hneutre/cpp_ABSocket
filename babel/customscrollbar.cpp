#include "customscrollbar.h"

CustomScrollBar::CustomScrollBar(QListWidget *parent) :
    QScrollBar(parent)
{
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(updateMask()));
}

void CustomScrollBar::updateMask(){
    QStyleOptionSlider opt;
    initStyleOption(&opt);

    QRegion r(style()->subControlRect(QStyle::CC_ScrollBar, &opt, QStyle::SC_ScrollBarSlider, this));
    r+= style()->subControlRect(QStyle::CC_ScrollBar, &opt, QStyle::SC_ScrollBarAddLine, this);
    r+= style()->subControlRect(QStyle::CC_ScrollBar, &opt, QStyle::SC_ScrollBarSubLine, this);
    setMask(r);
}

void CustomScrollBar::showEvent ( QShowEvent * event ){
    QScrollBar::showEvent(event);
    updateMask();
}
