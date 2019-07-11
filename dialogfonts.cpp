#include "dialogfonts.h"
#include "ui_dialogfonts.h"

DialogFonts::DialogFonts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFonts)
{
    ui->setupUi(this);

    setFixedSize(width / 2, height / 2);
    ui->listWidget_Font->setMinimumWidth(width / 5);

    QFontDatabase database;

    ui->listWidget_Font->addItems(database.families());

    for (int size : database.standardSizes()) {
        ui->listWidget_Size->addItem(QString::number(size));
    }


}

DialogFonts::~DialogFonts()
{
    delete ui;
}


