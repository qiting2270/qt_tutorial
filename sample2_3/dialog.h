#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
class QCheckBox;
class QRadioButton;
class QPlainTextEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkboxUnder;
    QCheckBox *checkboxItalic;
    QCheckBox *checkboxBold;

    QRadioButton *radioBlack;
    QRadioButton *radioRed;
    QRadioButton *radioBlue;

    QPlainTextEdit *txtEdit;

    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;

private slots:
    void do_checkBoxUnder(bool checked);
    void do_checkBoxBold(bool checked);
    void do_checkBoxItalic(bool checked);

    void do_setFontColor();

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void V(QHBoxLayout *HLayout, QVBoxLayout *VLayout);
};

#endif // DIALOG_H
