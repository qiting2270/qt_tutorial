#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->radioButton_Black, SIGNAL(clicked()), this, SLOT(change_FontColor()));
    connect(ui->radioButton_Blue, SIGNAL(clicked()), this, SLOT(change_FontColor()));
    connect(ui->radioButton_Red, SIGNAL(clicked()), this, SLOT(change_FontColor()));

}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_checkBox_underline_clicked(bool checked)
{
    // get the font of edit text
    QFont font = ui->plainTextEdit->font();
    //add underline
    font.setUnderline(checked);
    //update edit text font
    ui->plainTextEdit->setFont(font);

}


void Dialog::on_checkBox_Italic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_bold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::change_FontColor()
{
    QPalette palette = ui->plainTextEdit->palette();
    if(ui->radioButton_Black->isChecked()){
        palette.setColor(QPalette::Text, Qt::black);
    }
    else if(ui->radioButton_Blue->isChecked()){
        palette.setColor(QPalette::Text, Qt::blue);
    }
    else if(ui->radioButton_Red->isChecked()){
        palette.setColor(QPalette::Text, Qt::red);
    }


    ui->plainTextEdit->setPalette(palette);
}

