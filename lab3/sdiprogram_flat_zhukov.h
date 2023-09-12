#ifndef SDIPROGRAM_FLAT_ZHUKOV_H
#define SDIPROGRAM_FLAT_ZHUKOV_H

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include "docwindow_flat_zhukov.h"
namespace Ui {
class SDIProgram_Flat_Zhukov;
}

class SDIProgram_Flat_Zhukov : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_Flat_Zhukov(QWidget *parent = 0) : QMainWindow(parent)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindow_Flat_Zhukov* pdoc = new DocWindow_Flat_Zhukov;
        pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",  pdoc, SLOT(slotSave()), QKeySequence("CTRL+S"));
        pmnuFile->addAction("&SaveAs", pdoc, SLOT(slotSaveAs()), QKeySequence("CTRL+F"));
        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()),  QKeySequence("CTRL+J"));
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("CTRL+Q"));
        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);
        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);
        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);

    }
    ~SDIProgram_Flat_Zhukov();

private:
    Ui::SDIProgram_Flat_Zhukov *ui;

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "IP-114. Flat_and_Zhukov!");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }
};

#endif // SDIPROGRAM_FLAT_ZHUKOV_H
