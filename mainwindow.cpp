#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtWidgets>

QMap<QString, quint8> createNumberCodeHash()
{
    QMap<QString, quint8> result;
    result.insert("a", 1);
    result.insert("i", 1);
    result.insert("q", 1);
    result.insert("j", 1);
    result.insert("y", 1);

    result.insert("b", 2);
    result.insert("k", 2);
    result.insert("r", 2);

    result.insert("c", 3);
    result.insert("g", 3);
    result.insert("l", 3);
    result.insert("s", 3);

    result.insert("d", 4);
    result.insert("m", 4);
    result.insert("t", 4);

    result.insert("e", 5);
    result.insert("h", 5);
    result.insert("n", 5);

    result.insert("u", 6);
    result.insert("v", 6);
    result.insert("w", 6);
    result.insert("x", 6);
    result.insert("ç", 6);

    result.insert("o", 7);
    result.insert("z", 7);

    result.insert("f", 8);
    result.insert("p", 8);
    return result;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->nameEdit, SIGNAL(editFinished()),
            this, SLOT(calculateNumbers()));

    // prepara um hash, contendo os códigos numéricos
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateNumbers()
{
    QMessageBox::warning(this, "", "test");
}
