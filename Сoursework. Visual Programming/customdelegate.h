#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QLineEdit>
#include <QRegularExpressionValidator>

class CustomDelegate : public QStyledItemDelegate
{
public:
    explicit CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QLineEdit *editor = new QLineEdit(parent);
        QRegularExpressionValidator *validator = new QRegularExpressionValidator(QRegularExpression("^\\D*$"), editor);
        editor->setValidator(validator);
        return editor;
    }
};



#endif // CUSTOMDELEGATE_H
