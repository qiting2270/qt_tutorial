#include "dialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckbox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>


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


}

Dialog::~Dialog() {}
