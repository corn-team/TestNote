#include "dialogfonts.h"
#include "ui_dialogfonts.h"

DialogFonts::DialogFonts(QWidget *parent, QFont *font) :
    QDialog(parent),
    ui(new Ui::DialogFonts)
{
    ui->setupUi(this);
    ui->lineEdit_Size->setValidator(new QIntValidator(0, 100, this));

    finalFont = *font;

    ui->label->setFont(finalFont);

    ui->lineEdit_Font->setFont(finalFont.family());
    ui->lineEdit_Font->setText(finalFont.family());

    ui->checkBox_Bold->setChecked(finalFont.bold());
    ui->checkBox_Italic->setChecked(finalFont.italic());

    if (finalFont.pixelSize() == -1) {
        finalFont.setPixelSize(11);
    }
    ui->lineEdit_Size->setText(QString::number(finalFont.pixelSize()));

    ui->verticalLayout_Btns->setAlignment(Qt::AlignRight);

    setFixedSize(height * 4 / 7, height * 3 / 5);
    ui->listWidget_Font->setMinimumWidth(height * 2 / 7);

    int cnt = 0, needed;
    for (QString f : database.families()) {
        if (f == "Cambria Math") {
            continue;
        }
        QListWidgetItem *x = new QListWidgetItem(f);
        x->setFont(f);
        ui->listWidget_Font->addItem(x);
        if (f == finalFont.family()) {
            qDebug() << f;
            needed = cnt;
        }
        cnt++;
    }
    ui->listWidget_Font->setCurrentRow(needed);
    QSet<QString> styles;
    for (QString f : database.families()) {
        for (QString s : database.styles(f)) {
            styles.insert(s);
        }
    }
//    for (QString s : styles) {
//        qDebug() << s;
//    }

    for (int size : database.standardSizes()) {
        ui->listWidget_Size->addItem(QString::number(size));
    }

    connect(ui->checkBox_Bold, SIGNAL(stateChanged(int)), this, SLOT(setBold(int)));
    connect(ui->checkBox_Italic, SIGNAL(stateChanged(int)), this, SLOT(setItalic(int)));

    connect(ui->pushButton_Apply, SIGNAL(clicked()), this, SLOT(apply()));
    connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(cancel()));
}

DialogFonts::~DialogFonts()
{
    delete ui;
}

void DialogFonts::on_listWidget_Font_itemClicked(QListWidgetItem *item)
{
    ui->lineEdit_Font->setText(item->text());

    changeFont(item->text());
}

void DialogFonts::on_listWidget_Size_itemClicked(QListWidgetItem *item)
{
    ui->lineEdit_Size->setText(item->text());
}

void DialogFonts::on_lineEdit_Size_textChanged(const QString &arg1)
{
    int x = ui->lineEdit_Size->text().toInt();

    QFont font = ui->label->font();
    font.setPixelSize(x);
    ui->label->setFont(font);

    int cnt = 0, needed;
    bool z = false;
    for (int y : database.standardSizes()) {
        if (x == y) {
            needed = cnt;
            z = true;
        }
        cnt++;
    }
    if (z) {
        ui->listWidget_Size->setCurrentRow(needed);
    }
}

void DialogFonts::changeFont(QString font)
{
    QFont cnt = ui->label->font();

    cnt.setFamily(font);
    cnt.setBold(ui->checkBox_Bold->isChecked());
    cnt.setItalic(ui->checkBox_Italic->isChecked());

    ui->label->setFont(cnt);

    ui->lineEdit_Font->setFont(font);
}

void DialogFonts::setBold(int arg)
{
    QFont font = ui->label->font();
    if (!arg) {
        font.setBold(false);
    } else {
        font.setBold(true);
    }
    ui->label->setFont(font);
}

void DialogFonts::setItalic(int arg)
{
    QFont font = ui->label->font();
    if (!arg) {
        font.setItalic(false);
    } else {
        font.setItalic(true);
    }
    ui->label->setFont(font);
}

void DialogFonts::apply()
{
    finalFont = ui->label->font();
    QDialog::close();
}

void DialogFonts::cancel()
{
    QDialog::close();
}
