#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include "matrixdialog.h"
#include "matrixitemdelegateint.h"
#include "matrixitemdelegatedouble.h"
#include "matrixitemdelegatestring.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    lay_(new QVBoxLayout(this)),
    btnInt_(new QPushButton(tr("Matrix of integers"), this)),
    btnDouble_(new QPushButton(tr("Matrix of doubles"), this)),
    btnString_(new QPushButton(tr("Matrix of strings"), this)),
    btnScientific_(new QPushButton(tr("Matrix of scientific notations"), this))
{
    ui->setupUi(this);

    lay_->addWidget(btnInt_);
    lay_->addWidget(btnDouble_);
    lay_->addWidget(btnString_);
    lay_->addWidget(btnScientific_);

    ui->centralWidget->setLayout(lay_);

    connect(btnInt_, SIGNAL(clicked()), this, SLOT(onBtnIntClicked()));
    connect(btnDouble_, SIGNAL(clicked()), this, SLOT(onBtnDoubleClicked()));
    connect(btnString_, SIGNAL(clicked()), this, SLOT(onBtnStringClicked()));
    connect(btnScientific_, SIGNAL(clicked()), this, SLOT(onBtnScientificClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openAndPrint(MatrixDialog *dlg)
{
    QStringList lst;

    if (dlg->exec())
    {
        lst = dlg->getValues();
        // print the values
        for (int i = 0; i < lst.count(); ++i)
            qDebug() << lst.at(i);
    }
}

void MainWindow::onBtnIntClicked()
{
    QStringList vals;
    QStringList labels;

    vals.append(QString::number(0));
    vals.append(QString::number(10));
    vals.append(QString::number(50));
    vals.append(QString::number(100));
    vals.append(QString::number(999));
    vals.append(QString::number(1));
    vals.append(QString::number(11));
    vals.append(QString::number(51));
    vals.append(QString::number(101));
    vals.append(QString::number(1000));


    labels << "Int1";
    labels << "Int2";
    labels << "Int3";
    labels << "Int4";
    labels << "Int5";

    MatrixItemDelegate  *delegate = new MatrixItemDelegateInt(-1, 1000, this);
    MatrixDialog        *dlg = new MatrixDialog(2, 5, tr("Matrix of integers"), labels, vals, delegate, this);

    openAndPrint(dlg);
}

void MainWindow::onBtnDoubleClicked()
{
    QStringList vals;
    QStringList labels;

    vals.append(QString::number(0.0));
    vals.append(QString::number(10.0));
    vals.append(QString::number(50.0));
    vals.append(QString::number(100.0));
    vals.append(QString::number(1000.0));

    labels << "Float1";
    labels << "Float2";
    labels << "Float3";
    labels << "Float4";
    labels << "Float5";

    MatrixItemDelegate  *delegate = new MatrixItemDelegateDouble(-0.05, 2000.0, 2, this);
    MatrixDialog        *dlg = new MatrixDialog(1, 5,tr("Matrix of doubles"), labels, vals, delegate, this);

    openAndPrint(dlg);
}

void MainWindow::onBtnStringClicked()
{
    QStringList vals;
    QStringList labels;

    vals.append("once");
    vals.append(QString::number(10));
    vals.append(QString::number(50));
    vals.append(QString::number(100));
    vals.append(QString::number(999));

    labels << "String1";
    labels << "String2";
    labels << "String3";
    labels << "String4";
    labels << "String5";

    MatrixItemDelegate  *delegate = new MatrixItemDelegateString(QRegExp("(once|[1-9]\\d{,2})"), this);
    MatrixDialog        *dlg = new MatrixDialog(1, 5,tr("Matrix of strings"), labels, vals, delegate, this);

    openAndPrint(dlg);
}

void MainWindow::onBtnScientificClicked()
{
    QStringList vals;
    QStringList labels;

    vals.append(QString::number(0));
    vals.append(QString::number(10));
    vals.append(QString::number(50));
    vals.append(QString::number(100));
    vals.append(QString::number(999));

    labels << "Sci1";
    labels << "Sci2";
    labels << "Sci3";
    labels << "Sci4";
    labels << "Sci5";

    MatrixItemDelegate  *delegate = new MatrixItemDelegateString(QRegExp("(\\+|\\-)?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE](\\+|\\-)?\\d+)?"), this);
    MatrixDialog        *dlg = new MatrixDialog(1, 5,tr("Matrix of floats with scientific notation"), labels, vals, delegate, this);

    openAndPrint(dlg);

}
