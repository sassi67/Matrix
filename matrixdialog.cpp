/**************************************************************************
**    CFDEM Workbench
**
**    File: matrixdialog.cpp
**    Author: Alessandro Sacilotto
**    Created on: 2015-03-26
**
**    Copyright (C) 2015 DCS Computing GmbH
**************************************************************************/

#include "matrixdialog.h"
#include "matrixitemdelegate.h"
#include "validator.h"

#include <QCloseEvent>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>

/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog
 * @param title
 * @param nrows
 * @param ncols
 * @param values
 * @param parent
 */
MatrixDialog::MatrixDialog(int nrows, int ncols,
                           const QString& title, const QStringList &labels,
                           const QStringList& values,
                           MatrixItemDelegate *delegate, QWidget *parent):
	QDialog(parent),
    layMain_(new QVBoxLayout()),
    layTable_(new QHBoxLayout()),
	tableView_(new QTableView(this)),
    layButtons_(new QHBoxLayout()),
	btnSave_(new QPushButton(tr("Save"), this)),
	btnExit_(new QPushButton(tr("Exit"), this)),
	model_(new QStandardItemModel(nrows, ncols, this)),
	values_(values),
    modified_(false),
    itDelegate_(delegate)
{
	// fill the matrix
	int curValIdx = 0;
	for (int row = 0; row < nrows; ++row)
	{
		for (int col = 0; col < ncols; ++col)
		{
            model_->setHorizontalHeaderItem(col, new QStandardItem(labels.at(col)));
			Q_ASSERT(curValIdx < values_.size());
			model_->setItem(row, col, new QStandardItem(values_.at(curValIdx++)));
		}
	}

	tableView_->setModel(model_);
	connect(model_, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(onDataChanged(QModelIndex,QModelIndex)));
    tableView_->setItemDelegate(itDelegate_);

	// set the layouts
    layTable_->addWidget(tableView_);
	layButtons_->addWidget(btnSave_);
	layButtons_->addWidget(btnExit_);
	layMain_->addLayout(layTable_);
	layMain_->addLayout(layButtons_);
    setLayout(layMain_);

//    tableView_->horizontalHeader()->setStretchLastSection(true);
//    tableView_->resizeColumnsToContents();
//    tableView_->resizeRowsToContents();

	setWindowTitle(title);

	// close the dialog and send values_ to the caller
	connect(btnSave_, SIGNAL(clicked()), this, SLOT(accept()));
	// close the dialog WITHOUT sending values_ to the caller
	connect(btnExit_, SIGNAL(clicked()), this, SLOT(close()));
}

/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog::closeEvent
 * @param event
 */
void MatrixDialog::closeEvent(QCloseEvent *event)
{
	if (!modified_)
		return;

	QMessageBox msgBox;
	msgBox.setText(tr("The values have been modified."));
	msgBox.setInformativeText(tr("Do you want to save your changes?"));
	msgBox.setStandardButtons(QMessageBox::Save |
							  QMessageBox::Discard |
							  QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Save);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Save)
	{
		writeData();
		event->accept();
		// close the window and set accepted
		QDialog::accept();
	}
	else if (ret == QMessageBox::Cancel)
	{
		event->ignore();
    }
}
/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog::resizeEvent
 * @param evt
 */
void MatrixDialog::resizeEvent(QResizeEvent *evt)
{
    tableView_->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    tableView_->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    QDialog::resizeEvent(evt);
}
/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog::writeData
 */
void MatrixDialog::writeData()
{
	if (modified_)
	{
		// from tableView_ to values_
		values_.clear();

		QAbstractItemModel *tableModel = tableView_->model();
		int iRows = tableModel->rowCount();
		int iCols = tableModel->columnCount();

		for (int row = 0; row < iRows; ++row)
		{
			for (int col = 0; col < iCols; ++col)
			{
				values_ << tableModel->index(row, col).data().toString();
			}
		}

		modified_ = false;
	}
}
/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog::accept
 */
void MatrixDialog::accept()
{
	writeData();
	QDialog::accept();
}
/**
 * @author Alessandro Sacilotto
 * @brief MatrixDialog::onDataChanged
 */
void MatrixDialog::onDataChanged(QModelIndex, QModelIndex)
{
	modified_ = true;
}


