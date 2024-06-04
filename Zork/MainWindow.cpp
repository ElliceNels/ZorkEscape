#include <QtWidgets>

#include "arrowpad.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
    arrowPad = new ArrowPad;
    setCentralWidget(arrowPad);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(QKeySequence(tr("Ctrl+Q", "Quit")));
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);

    // fileMenu = menuBar()->addMenu(tr("&File"));
    // fileMenu->addAction(exitAct);
}
