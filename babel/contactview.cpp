#include "contactview.h"
#include "ui_contactview.h"

ContactView::ContactView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactView)
{
    ui->setupUi(this);
}

ContactView::~ContactView()
{
    delete ui;
}
