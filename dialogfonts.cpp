#include "dialogfonts.h"
#include "ui_dialogfonts.h"
#include <map>

std::map <QString, int> styles;

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
<<<<<<< HEAD
=======



    ui->listWidget_Style->addItems({"Light", "Normal", "DemiBold", "Bold", "Black"});
    styles["Light"] = 25; styles["Normal"] = 50; styles["DemiBold"] = 63;
    styles["Bold"] = 75; styles["Black"] = 87;

    connect(ui->lineEdit_Font, SIGNAL(textChanged(QString)), this, SLOT(changeExampleFont()));
    connect(ui->lineEdit_Size, SIGNAL(textChanged(QString)), this, SLOT(changeExampleFont()));
    connect(ui->lineEdit_Style, SIGNAL(textChanged(QString)), this, SLOT(changeExampleFont()));
>>>>>>> fc7ee931c059c4f8e1a00213f7274be4747626eb
}

DialogFonts::~DialogFonts()
{
    delete ui;
}

<<<<<<< HEAD
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
=======
void DialogFonts::changeExampleFont()
{
    QFont currentfontSet = ui->exampleText->font();

    QString currentFont = ui->lineEdit_Font->text();
    if (database.families().contains(currentFont))
        currentfontSet.setFamily(currentFont);

    bool ok;
    int currentSize = ui->lineEdit_Size->text().toInt(&ok);
    if (ok && currentSize > 0)
        currentfontSet.setPointSize(currentSize);

    QString style = ui->lineEdit_Style->text();
    if (styles.count(style)) {
        int currentStyle = styles[style];
        currentfontSet.setWeight(currentStyle);
    }

    ui->exampleText->setFont(currentfontSet);
}

void DialogFonts::on_listWidget_Font_itemSelectionChanged()
{
    ui->lineEdit_Font->setText(ui->listWidget_Font->currentItem()->text());
}

void DialogFonts::on_listWidget_Style_itemSelectionChanged()
{
    ui->lineEdit_Style->setText(ui->listWidget_Style->currentItem()->text());
}

void DialogFonts::on_listWidget_Size_itemSelectionChanged()
{
    ui->lineEdit_Size->setText(ui->listWidget_Size->currentItem()->text());
}

//короче тут надо чтобы когда курсор наводишь на итем, временно менялся текст примера
//ниже штука неправильная я там почитала надо мышь вроде отслеживать ну короче разберешься да

void DialogFonts::on_listWidget_Font_viewportEntered()
{
    QFont fontSet = ui->exampleText->font();

    QString currentFont = ui->listWidget_Font->;
    if (database.families().contains(currentFont))
        fontSet.setFamily(currentFont);

//    bool ok;
//    int currentSize = ui->lineEdit_Size->text().toInt(&ok);
//    if (ok && currentSize > 0)
//        fontSet.setPointSize(currentSize);

//    QString style = ui->lineEdit_Style->text();
//    if (styles.count(style)) {
//        int currentStyle = styles[style];
//        fontSet.setWeight(currentStyle);
//    }

    ui->exampleText->setFont(fontSet);
>>>>>>> fc7ee931c059c4f8e1a00213f7274be4747626eb
}
