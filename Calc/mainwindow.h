#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include  "lexer.h"
#include <QMainWindow>
#include <QtCore/QSignalMapper>
#include <QPushButton>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showError();

    void createKeyBoard();

    void clicked(QString str);

    void clear();

    void clearOneSymbol();

    void calculate();


private:
    Ui::MainWindow *ui;
    QPushButton* buttons[21];
};

#endif // MAINWINDOW_H
