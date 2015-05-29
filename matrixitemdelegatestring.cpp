/**************************************************************************
** Qt Creator license header template
**   Special keywords: alessandro 29.05.2015 2015
**   Environment variables:
**   To protect a percent sign, use '%'.
**************************************************************************/

#include "matrixitemdelegatestring.h"
#include "validatorstring.h"
#include <QLineEdit>

MatrixItemDelegateString::MatrixItemDelegateString(const QRegExp &rx, QObject *parent) :
    MatrixItemDelegate(parent)
{
    validator_ = new ValidatorString(rx, parent);
}

QWidget *MatrixItemDelegateString::createEditor(QWidget *parent, const QStyleOptionViewItem, const QModelIndex) const
{
    QLineEdit *editor = new QLineEdit(parent);
    return editor;
}

void MatrixItemDelegateString::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    QLineEdit *line = static_cast<QLineEdit*>(editor);
    line->setValidator(validator_);
    line->setText(value);
}

void MatrixItemDelegateString::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
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

void MatrixItemDelegateString::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex) const
{
    editor->setGeometry(option.rect);
}
