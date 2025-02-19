#include "dialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckbox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>


void Dialog::do_checkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_checkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_checkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet = txtEdit->palette();
    if(radioBlack->isChecked()){
        plet.setColor(QPalette::Text, Qt::black);
    }
    if(radioBlue->isChecked()){
        plet.setColor(QPalette::Text, Qt::blue);
    }
    if(radioRed->isChecked()){
        plet.setColor(QPalette::Text, Qt::red);
    }
    txtEdit->setPalette(plet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    checkboxUnder = new QCheckBox("Underline");
    checkboxBold = new QCheckBox("Bold");
    checkboxItalic = new QCheckBox("Italic");

    QHBoxLayout *HLayout = new QHBoxLayout();
    HLayout -> addWidget(checkboxUnder);
    HLayout -> addWidget(checkboxItalic);
    HLayout -> addWidget(checkboxBold);

    radioBlack = new QRadioButton("Black");
    radioBlue = new QRadioButton("Blue");
    radioRed = new QRadioButton("Red");
    QHBoxLayout * HLayout2 = new QHBoxLayout();
    HLayout2 -> addWidget(radioBlack);
    HLayout2 -> addWidget(radioBlue);
    HLayout2 -> addWidget(radioRed);


    txtEdit = new QPlainTextEdit;
    txtEdit -> setPlainText("hello world \n");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    btnOK = new QPushButton("OK");
    btnCancel = new QPushButton("Cancel");
    btnClose = new QPushButton("Close");
    QHBoxLayout * HLayout3 = new QHBoxLayout();
    HLayout3 -> addStretch();
    HLayout3 -> addWidget(btnOK);
    HLayout3 -> addStretch();

    HLayout3 -> addWidget(btnCancel);
    HLayout3 -> addWidget(btnClose);


    QVBoxLayout *VLayout = new QVBoxLayout();
    VLayout -> addLayout(HLayout);
    VLayout -> addLayout(HLayout2);
    VLayout -> addWidget(txtEdit);
    VLayout -> addLayout(HLayout3);

    setLayout(VLayout);

    connect(checkboxUnder, SIGNAL(clicked(bool)), this, SLOT(do_checkBoxUnder(bool)));
    connect(checkboxBold, SIGNAL(clicked(bool)), this, SLOT(do_checkBoxBold(bool)));
    connect(checkboxItalic, SIGNAL(clicked(bool)), this, SLOT(do_checkBoxItalic(bool)));

    connect(radioBlack, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioRed, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));
    connect(radioBlue, SIGNAL(clicked(bool)), this, SLOT(do_setFontColor()));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

    setWindowTitle("手工打造UI");
}

Dialog::~Dialog() {}
