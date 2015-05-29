#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    lay_(new QVBoxLayout(this)),
    btnDouble_(new QPushButton(tr("Matrix of doubles"), this))
{
    ui->setupUi(this);


    ui->centralWidget->setLayout(lay_);
}

MainWindow::~MainWindow()
{
    delete ui;
}
