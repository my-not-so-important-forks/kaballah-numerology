#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include "numerologycore.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->nameEdit, &QLineEdit::textChanged,
            this, &MainWindow::setName);
    connect(this, &MainWindow::nameChanged,
            this, &MainWindow::calculateNumbers);

    // prepara um hash, contendo os códigos numéricos
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::name() const
{
    return mName;
}

void MainWindow::calculateNumbers()
{
    QString onlyVowels     = filterVowels(ui->nameEdit->text());
    QString onlyConsonants = filterConsonants(ui->nameEdit->text());

    quint32 sumVowels = doSumOfLetters(onlyVowels);
    quint32 sumConsonants = doSumOfLetters(onlyConsonants);
    quint32 sumAllLetters = doSumOfLetters(ui->nameEdit->text());

    ui->vowelsEdit->setText(QString("%1").arg(sumVowels));
    ui->consonantsEdit->setText(QString("%1").arg(sumConsonants));
    ui->allCharsEdit->setText(QString("%1").arg(sumAllLetters));

    ui->filterVowelsEdit->setText(onlyVowels);
    ui->filterConsonantsEdit->setText(onlyConsonants);

    quint32 reductionVowels = doReduction(sumVowels);
    quint32 reductionConsonants = doReduction(sumConsonants);
    quint32 reductionAllChars = doReduction(sumAllLetters);

    ui->reductionMotivationEdit->setText(QString("%1").arg(reductionVowels));
    ui->reductionImpressionEdit->setText(QString("%1").arg(reductionConsonants));
    ui->reductionExpressionEdit->setText(QString("%1").arg(reductionAllChars));

}

void MainWindow::setName(QString name)
{
    if (name != mName) {
        mName = name;
        emit nameChanged();
    }
}
