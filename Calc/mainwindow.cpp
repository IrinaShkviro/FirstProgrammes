#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowError()
{
    ui->label_2->setText("Expression is incorrect");
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"1");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"2");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"4");
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"5");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"6");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"7");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"8");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"9");
}
void MainWindow::on_pushButton_10_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"0");
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"+");
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"-");
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"*");
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"/");
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"^");
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->label_2->clear();
    Parser myParser;
    QString result = myParser.GetExpr(ui->lineEdit->text(), ui->checkBox->isChecked());
    if (result != "")
        ui->lineEdit->setText(result);
    else
        ShowError();
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"(");
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+")");
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text().mid(0, ui->lineEdit->text().length() - 1));
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->label_2->clear();
    ui->lineEdit->setText(ui->lineEdit->text()+"e");
}
