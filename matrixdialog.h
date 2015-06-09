/**************************************************************************
**    CFDEM Workbench
**
**    File: matrixdialog.h
**    Author: Alessandro Sacilotto
**    Created on: 2015-03-26
**
**    Copyright (C) 2015 DCS Computing GmbH
**************************************************************************/

#ifndef MATRIXDIALOG_H
#define MATRIXDIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QModelIndex>

class MatrixItemDelegate;
class QCloseEvent;
class QHBoxLayout;
class QPushButton;
class QStandardItemModel;
class QTableView;
class QVBoxLayout;

class MatrixDialog : public QDialog
{
	Q_OBJECT
public:
    MatrixDialog(int nrows, int ncols,
                 const QString& title, const QStringList& labels,
                 const QStringList& values,
                 MatrixItemDelegate *delegate, QWidget *parent = 0);

	QStringList getValues() const { return values_; }

protected:
	void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *evt);

private:

    QVBoxLayout             *layMain_;
    QHBoxLayout             *layTable_;
    QTableView                 *tableView_;
    QHBoxLayout             *layButtons_;
    QPushButton             *btnSave_;
    QPushButton             *btnExit_;
	QStandardItemModel  *model_;
    QStringList                 values_;
    bool                            modified_;
    MatrixItemDelegate      *itDelegate_;

	void writeData();

signals:

public slots:

private slots:
	void accept();
	void onDataChanged(QModelIndex,QModelIndex);
};

#endif // MATRIXDIALOG_H
