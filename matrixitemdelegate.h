#ifndef MATRIXITEMDELEGATE_H
#define MATRIXITEMDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>

class Validator;

class MatrixItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MatrixItemDelegate(QObject *parent = 0);

protected:
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem, const QModelIndex) const = 0;
    virtual void setEditorData(QWidget * editor, const QModelIndex & index) const = 0;
    virtual void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const = 0;
    virtual void updateEditorGeometry(QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex) const = 0;

    Validator *validator_;

private:
signals:
    void dataChanged();
};

#endif // MATRIXITEMDELEGATE_H
