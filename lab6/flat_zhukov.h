#ifndef FLAT_ZHUKOV_H
#define FLAT_ZHUKOV_H

#include <QWidget>
#include <QAbstractButton>


namespace Ui {
class Flat_Zhukov;
}

class Flat_Zhukov : public QWidget
{
    Q_OBJECT

public:
    explicit Flat_Zhukov(QWidget *parent = nullptr);
    ~Flat_Zhukov();

private:
    Ui::Flat_Zhukov *ui;
public slots:
    void recieveData(QString str);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // FLAT_ZHUKOV_H
