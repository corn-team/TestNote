#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialogclose.h"
#include "dialogfonts.h"

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QStatusBar>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newFile();

    void openFile();

    bool save();

    bool saveAs();

    void exit();

    void undo();

    void redo();

    void copy();

    void cut();

    void paste();

    void on_textEdit_textChanged();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();

    void on_actionFont_triggered();

    void updateStatusBar();

private:
    Ui::MainWindow *ui;

    QDesktopWidget desktopWidget;
    int width = desktopWidget.width();
    int height = desktopWidget.height();

    QString currentFile;
    bool saved;
    DialogClose *dialogClose;
    bool closeReply = true;
    DialogFonts *dialogFonts;

    void setNewWindowTitle(QString name);

    void closeEvent(QCloseEvent *event) override;

};

#endif // MAINWINDOW_H
