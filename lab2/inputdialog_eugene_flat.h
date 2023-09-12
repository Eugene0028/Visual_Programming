#ifndef INPUTDIALOG_EUGENE_FLAT_H
#define INPUTDIALOG_EUGENE_FLAT_H


#include <QDialog>
#include <QLineEdit>

class InputDialog_Eugene_Flat: public QDialog
{
    Q_OBJECT

private:
    QLineEdit* m_ptxtFirstName;
    QLineEdit* m_ptxtLastName;
public:
    InputDialog_Eugene_Flat(QWidget* pwgt = nullptr);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_EUGENE_FLAT_H
