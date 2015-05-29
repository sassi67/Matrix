/**************************************************************************
** Qt Creator license header template
**   Special keywords: alessandro 29.05.2015 2015
**   Environment variables:
**   To protect a percent sign, use '%'.
**************************************************************************/

#ifndef MATRIXITEMDELEGATEINT_H
#define MATRIXITEMDELEGATEINT_H

#include "matrixitemdelegate.h"

class MatrixItemDelegateInt : public MatrixItemDelegate
{
    Q_OBJECT
public:
    MatrixItemDelegateInt(int bottom, int top, QObject *parent = 0);

protected:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem, const QModelIndex) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex) const;

signals:

public slots:

};

#endif // MATRIXITEMDELEGATEINT_H
