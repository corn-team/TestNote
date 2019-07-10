#ifndef DIALOGCLOSE_H
#define DIALOGCLOSE_H

#include <QDialog>

#include <QDebug>
#include <QDesktopWidget>

namespace Ui {
class DialogClose;
}

class DialogClose : public QDialog
{
    Q_OBJECT

public:
    explicit DialogClose(QWidget *parent = nullptr);
    ~DialogClose();
    int reply;

private slots:
    void on_pushButton_Yes_clicked();

    void on_pushButton_No_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::DialogClose *ui;

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();
};

#endif // DIALOGCLOSE_H
