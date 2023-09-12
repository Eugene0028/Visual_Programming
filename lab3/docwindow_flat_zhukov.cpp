#include "docwindow_flat_zhukov.h"

DocWindow_Flat_Zhukov::DocWindow_Flat_Zhukov(QWidget* pwgt) : QTextEdit(pwgt)
{

}


void DocWindow_Flat_Zhukov::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty())return;
    QFile file(str);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
        m_srtFileName = str;
        emit changeWindowTitle(m_srtFileName);
    }

}


void DocWindow_Flat_Zhukov::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_srtFileName);
    if (!str.isEmpty())
    {
        m_srtFileName = str;
        slotSave();
    }
}

void DocWindow_Flat_Zhukov::slotSave()
{
    if(m_srtFileName.isEmpty())
    {
        slotSaveAs();
        return;
    }
    QFile file(m_srtFileName);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(m_srtFileName);
        QMessageBox::information(this, "Save File", "File saved successfully");
    }
}


void DocWindow_Flat_Zhukov::slotColor()
{
    setTextColor(QColorDialog::getColor());
}

