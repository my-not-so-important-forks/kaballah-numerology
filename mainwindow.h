#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

signals:
    void nameChanged();


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString name() const;

private slots:
    void calculateNumbers();
    void setName(QString name);

private:
    Ui::MainWindow *ui;
    QString mName;
};

#endif // MAINWINDOW_H
