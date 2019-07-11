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
    explicit DialogFonts(QWidget *parent = nullptr, QFont *font = nullptr);
    ~DialogFonts();

    QFont finalFont;

private slots:
    void on_listWidget_Font_itemClicked(QListWidgetItem *item);

    void setBold(int arg);

    void setItalic(int arg);

    void apply();

    void cancel();

private:
    Ui::DialogFonts *ui;

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();

    QFontDatabase database;

    void changeFont(QString font);
};

#endif // DIALOGFONTS_H
