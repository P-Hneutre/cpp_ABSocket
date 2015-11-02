#include "contactactions.h"
#include "ui_contactactions.h"

ContactActions::ContactActions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContactActions)
{
    ui->setupUi(this);
}

ContactActions::~ContactActions()
{
    delete ui;
}
