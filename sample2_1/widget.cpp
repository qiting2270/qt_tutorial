#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("Hello!!!!");
    ui->pushButton->setText("Click to Close");
}

Widget::~Widget()
{
    delete ui;
}
