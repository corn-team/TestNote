#ifndef DIALOGFONTS_H
#define DIALOGFONTS_H

#include <QDialog>

#include <QFontDatabase>
#include <QDesktopWidget>
#include <QListWidgetItem>
#include <QDebug>

namespace Ui {
class DialogFonts;
}

class DialogFonts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFonts(QWidget *parent = nullptr);
    ~DialogFonts();

private slots:

    void on_listWidget_Font_itemClicked(QListWidgetItem *item);

    void on_listWidget_Style_itemClicked(QListWidgetItem *item);

private:
    Ui::DialogFonts *ui;

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();

    QFontDatabase database;
};

#endif // DIALOGFONTS_H
