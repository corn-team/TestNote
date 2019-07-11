#ifndef DIALOGFONTS_H
#define DIALOGFONTS_H

#include <QDialog>

#include <QFontDatabase>
#include <QDesktopWidget>

namespace Ui {
class DialogFonts;
}

class DialogFonts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFonts(QWidget *parent = nullptr);
    ~DialogFonts();

private:
    Ui::DialogFonts *ui;

    QFontDatabase database;

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();

private slots:
    void changeExampleFont();

    void on_listWidget_Font_itemSelectionChanged();
    void on_listWidget_Style_itemSelectionChanged();
    void on_listWidget_Size_itemSelectionChanged();
};

#endif // DIALOGFONTS_H
