#ifndef CONTACTACTIONS_H
#define CONTACTACTIONS_H

#include <QWidget>

namespace Ui {
class ContactActions;
}

class ContactActions : public QWidget
{
    Q_OBJECT

public:
    explicit ContactActions(QWidget *parent = 0);
    ~ContactActions();

private:
    Ui::ContactActions *ui;
};

#endif // CONTACTACTIONS_H
