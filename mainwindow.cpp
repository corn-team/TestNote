#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(width * 7 / 10, height * 7 / 10);
    setMinimumSize(width * 2 / 10, height * 2 / 10);
    setWindowTitle("New File COCOCO");

    ui->statusBar->addPermanentWidget(ui->label_Status);
    currentFile = "";
    saved = true;
    ui->label_Status->setText("Line: 1, Column: 1");

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
    connect(ui->actionCopy, SIGNAL(triggered()), this, SLOT(copy()));
    connect(ui->actionCut, SIGNAL(triggered()), this, SLOT(cut()));
    connect(ui->actionPaste, SIGNAL(triggered()), this, SLOT(paste()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNewWindowTitle(QString name)
{
    int pos = -1, cnt = name.indexOf("/");
    while (cnt != -1) {
        pos = cnt;
        cnt = name.indexOf("/", pos + 1);
    }
    if (pos != -1) {
        name = name.right(name.size() - pos - 1);
    }
    setWindowTitle(name);
}

// File->New
void MainWindow::newFile()
{
    if (!saved) {
        closeEvent(new QCloseEvent);
    }
    if (closeReply) {
        currentFile.clear();
        ui->textEdit->setText(QString());
        setNewWindowTitle("New File");
        saved = true;
    }
}

// File->Open
void MainWindow::openFile()
{
    if (!saved) {
        closeEvent(new QCloseEvent);
    }
    if (closeReply) {
        QString fileName = QFileDialog::getOpenFileName(this, "Open the file", "", "*.txt");
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;
        }
        currentFile = fileName;
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        setNewWindowTitle(fileName);
        saved = true;
        file.close();
    }
}

bool MainWindow::save()
{
    if (currentFile == "") {
        return saveAs();
    } else {
        QFile file(currentFile);
        if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return false;
        }
        setNewWindowTitle(currentFile);
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        saved = true;
        file.close();

        return true;
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as", "", "*.txt");
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return false;
    }
    currentFile = fileName;
    setNewWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    saved = true;
    file.close();

    return true;
}

void MainWindow::exit()
{
    closeEvent(new QCloseEvent);
    if (closeReply) {
        QApplication::quit();
    }
}

void MainWindow::undo()
{
    ui->textEdit->undo();
}

void MainWindow::redo()
{
    ui->textEdit->redo();
}

void MainWindow::copy()
{
    ui->textEdit->copy();
}

void MainWindow::cut()
{
    ui->textEdit->cut();
}

void MainWindow::paste()
{
    ui->textEdit->paste();
}

void MainWindow::on_textEdit_textChanged()
{
    qDebug() << 3;
    if (saved) {
        saved = false;
        setWindowTitle(windowTitle() + "*");
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!saved) {
        dialogClose = new DialogClose(this);
        dialogClose->exec();
        switch (dialogClose->reply) {
        case 0:
            if (!save()) {
                closeEvent(event);
            }
            closeReply = true;
            event->accept();
            break;
        case 1:
            closeReply = true;
            event->accept();
            break;
        case 2:
            closeReply = false;
            event->ignore();
            break;
        }
    } else {
        closeReply = true;
        event->accept();
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About us", "Made by the TEST team<br>"
                                         "Our contacts : <br>"
                                         "<a href='https://vk.com/leonid1313'>VK page</a><br>"
                                         "Email: ll441369@gmail.com");
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    QTextCursor textCursor = ui->textEdit->textCursor();
    int x = textCursor.blockNumber();
    int y = textCursor.columnNumber();
    ui->label_Status->setText("Line: " + QString::number(x + 1) + ", Column: " + QString::number(y + 1));
}

void MainWindow::on_textEdit_selectionChanged()
{
    QTextCursor textCursor = ui->textEdit->textCursor();
    int x = textCursor.blockNumber();
    int y = textCursor.columnNumber();
    int size = textCursor.selectionEnd() - textCursor.selectionStart();
    ui->label_Status->setText("Line: " + QString::number(x + 1) + ", Column: " + QString::number(y + 1) +
                               (size > 0 ? ", Selected: " + QString::number(size) : ""));
}

void MainWindow::on_actionFont_triggered()
{
    dialogFonts = new DialogFonts(this);
    dialogFonts->exec();
}
