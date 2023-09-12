#ifndef DOCWINDOW_FLAT_ZHUKOV_H
#define DOCWINDOW_FLAT_ZHUKOV_H
#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>
class DocWindow_Flat_Zhukov : public QTextEdit
{
    Q_OBJECT
private:
    QString m_srtFileName;
public:
    DocWindow_Flat_Zhukov(QWidget* pgwt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_FLAT_ZHUKOV_H
