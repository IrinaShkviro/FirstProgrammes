#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("");
    createKeyBoard();

    buttons[18] = new QPushButton("←", this);
    connect(buttons[18], SIGNAL(clicked()), this, SLOT(clearOneSymbol()));
    ui->keyBoard->addWidget(buttons[18], 4, 4);

    buttons[19] = new QPushButton("C", this);
    connect(buttons[19], SIGNAL(clicked()), this, SLOT(clear()));
    ui->keyBoard->addWidget(buttons[19], 4, 5);

    buttons[20] = new QPushButton("=", this);
    connect(buttons[20], SIGNAL(clicked()), this, SLOT(calculate()));
    ui->keyBoard->addWidget(buttons[20], 5, 5);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createKeyBoard()
{
    QSignalMapper *signalMapper = new QSignalMapper(this);
    for (int i = 1; i < 10; i++)
    {
        buttons[i] = new QPushButton(QString::number(i), this);
        signalMapper->setMapping(buttons[i], QString::number(i));
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        ui->keyBoard->addWidget(buttons[i], (i-1)/3, (i-1)%3);
    }
    buttons[0] = new QPushButton(QString::number(0), this);
    signalMapper->setMapping(buttons[0], QString::number(0));
    connect(buttons[0], SIGNAL(clicked()), signalMapper, SLOT(map()));
    ui->keyBoard->addWidget(buttons[0], 4, 1);

    buttons[10] = new QPushButton("(", this);
    signalMapper->setMapping(buttons[10], "(");
    connect(buttons[10], SIGNAL(clicked()), signalMapper, SLOT(map()));
    ui->keyBoard->addWidget(buttons[10], 4, 0);

    buttons[11] = new QPushButton(")", this);
    signalMapper->setMapping(buttons[11], ")");
    connect(buttons[11], SIGNAL(clicked()), signalMapper, SLOT(map()));
    ui->keyBoard->addWidget(buttons[11], 4, 2);

    QString operations[6] = {"+", "-", "/", "*", "^", "e"};
    for (int i = 0; i < 6; i++)
    {
        buttons[12+i] = new QPushButton(operations[i], this);
        signalMapper->setMapping(buttons[12+i], operations[i]);
        connect(buttons[12+i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        ui->keyBoard->addWidget(buttons[12+i], i/2, 4+i%2);
    }
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
}

void MainWindow::showError()
{
    ui->label_2->setText("Expression is incorrect");
}

void MainWindow::clicked(QString str)
{
    ui->label_2->clear();
    QString expression = ui->lineEdit->text();
    ui->lineEdit->setText(expression + str);
}



void MainWindow::calculate()
{
    ui->label_2->clear();
    Parser myParser;
    QString result = myParser.getExpr(ui->lineEdit->text(), ui->checkBox->isChecked());
    if (!result.isEmpty())
        ui->lineEdit->setText(result);
    else
        showError();
}



void MainWindow::clearOneSymbol()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text().mid(0, ui->lineEdit->text().length() - 1));
}

void MainWindow::clear()
{
    ui->label_2->clear();
    ui->lineEdit->setText("");
}

