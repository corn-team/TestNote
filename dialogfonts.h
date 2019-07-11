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

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();
};

#endif // DIALOGFONTS_H
