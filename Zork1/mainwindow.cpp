#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStackedWidget *AllPages = ui->AllPages;
    AllPages->setCurrentIndex(0);

}

// Destructor of the main window
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QStackedWidget *AllPages = ui->AllPages;
    AllPages->setCurrentIndex(1);
}

