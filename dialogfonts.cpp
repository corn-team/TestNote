#include "dialogfonts.h"
#include "ui_dialogfonts.h"

DialogFonts::DialogFonts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFonts)
{
    ui->setupUi(this);

    QFontDatabase database;
    //TODO

    for (int size : sizes) {
        ui->listWidget_Size->addItem(QString::number(size));
    }
}

DialogFonts::~DialogFonts()
{
    delete ui;
}


