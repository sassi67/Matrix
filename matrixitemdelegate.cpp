#include "matrixitemdelegate.h"
#include "validator.h"

MatrixItemDelegate::MatrixItemDelegate(QObject *parent) :
        QItemDelegate(parent),
        validator_(NULL)
{

}
