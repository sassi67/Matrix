#ifndef MATRIXITEMDELEGATEDOUBLE_H
#define MATRIXITEMDELEGATEDOUBLE_H

#include "matrixitemdelegate.h"

class MatrixItemDelegateDouble : public MatrixItemDelegate
{
    Q_OBJECT
public:
    MatrixItemDelegateDouble(double bottom, double top, int decimals, QObject *parent = 0);

protected:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem, const QModelIndex) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
    void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex) const;

signals:

public slots:
};

#endif // MATRIXITEMDELEGATEDOUBLE_H
