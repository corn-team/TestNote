#include "dialogfonts.h"
#include "ui_dialogfonts.h"

DialogFonts::DialogFonts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFonts)
{
    ui->setupUi(this);

    setFixedSize(width / 3, height / 2);
    ui->listWidget_Font->setMinimumWidth(width / 5);

    ui->listWidget_Font->addItems(database.families());

    for (int size : database.standardSizes()) {
        ui->listWidget_Size->addItem(QString::number(size));
    }
}

DialogFonts::~DialogFonts()
{
    delete ui;
}

void DialogFonts::on_listWidget_Font_itemClicked(QListWidgetItem *item)
{
    qDebug() << 1;
    ui->lineEdit_Font->setText(item->text());

    ui->listWidget_Font->clear();
    ui->listWidget_Font->addItems(database.families());

    ui->listWidget_Style->clear();
    ui->listWidget_Style->addItems(database.styles(item->text()));

    ui->label_Example->setFont(QFont(item->text()));
    ui->listWidget_Style->setFont(QFont(item->text()));
}

void DialogFonts::on_listWidget_Style_itemClicked(QListWidgetItem *item)
{
    ui->lineEdit_Style->setText(item->text());

    ui->listWidget_Style->clear();
    //qDebug() << ui->listWidget_Font->currentItem();
    //ui->listWidget_Style->addItems(database.styles(ui->listWidget_Font->currentItem()->text()));
}
