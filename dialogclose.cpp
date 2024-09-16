#include "dialogclose.h"
#include "ui_dialogclose.h"

DialogClose::DialogClose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClose)
{
    ui->setupUi(this);
    setFixedSize(3 * height * 2 / 15, height * 2 / 15);
    setWindowTitle("Save the file");
}

DialogClose::~DialogClose()
{
    delete ui;
}

void DialogClose::on_pushButton_Yes_clicked()
{
    reply = 0;
}

void DialogClose::on_pushButton_No_clicked()
{
    reply = 1;
}

void DialogClose::on_pushButton_Cancel_clicked()
{
    reply = 2;
}
