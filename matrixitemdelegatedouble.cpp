#include "matrixitemdelegatedouble.h"
#include "validatordouble.h"
#include <QLineEdit>

MatrixItemDelegateDouble::MatrixItemDelegateDouble(double bottom, double top, int decimals, QObject *parent) :
    MatrixItemDelegate(parent)
{
    validator_ = new ValidatorDouble(bottom, top, decimals, parent);
}

QWidget *MatrixItemDelegateDouble::createEditor(QWidget *parent, const QStyleOptionViewItem, const QModelIndex) const
{
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void MatrixItemDelegateDouble::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    QLineEdit *line = static_cast<QLineEdit*>(editor);
    line->setValidator(validator_);
    line->setText(value);
}

void MatrixItemDelegateDouble::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    line->setValidator(validator_);

    QString value = line->text();
    int pos = 0;

    if (validator_->validate(value, pos) != QValidator::Acceptable)
    {
        //do something?
        return;
    }

    model->setData(index, value);
}

void MatrixItemDelegateDouble::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex) const
{
    editor->setGeometry(option.rect);
}

