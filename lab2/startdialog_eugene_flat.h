#ifndef STARTDIALOG_EUGENE_FLAT_H
#define STARTDIALOG_EUGENE_FLAT_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_eugene_flat.h"

class StartDialog_Eugene_Flat: public QPushButton{
    Q_OBJECT


public:
    bool isClicked = false;



    StartDialog_Eugene_Flat(QWidget* pwgt = 0) : QPushButton(pwgt)
    {
        connect(this, SIGNAL(clicked(bool)), SLOT(slotButtonClicked()));

    }
public slots:
    void slotButtonClicked()
    {
        InputDialog_Eugene_Flat* pInputDialog = new InputDialog_Eugene_Flat;

        if (pInputDialog->exec() == QDialog::Accepted)
        {
            QString firstName = pInputDialog->firstName();
            QString lastName = pInputDialog->lastName();
            if (firstName != nullptr && lastName != nullptr) QMessageBox::information(nullptr, "Ваша информация: ", "Имя: " + firstName + " Фамилия: " + lastName);
            else QMessageBox::information(nullptr, "Ошибка", "Одно из полей оказалось пустым! Повторите ввод...");
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_EUGENE_FLAT_H
