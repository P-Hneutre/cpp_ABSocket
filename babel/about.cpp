#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->ui->logo->setStyleSheet("background-image: url(:/img/babelmini.png)");
    connect(this->ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(closeIt()));
}

About::~About()
{
    delete ui;
}

void    About::closeIt()
{
    this->close();
}
