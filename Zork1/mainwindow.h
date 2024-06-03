#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStackedWidget>
#include <QLabel>
#include "dialogue.h"
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Dialogue
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QStackedWidget *AllPages;
    ~MainWindow();
    void initiateGame();
    void roomCreation();
    void itemCreation();
    void setLabelText(std::string text, QLabel *label);
    void changeRoom(int index,  QLabel *label1,  QLabel *label2);
    void addToItemToInventory(Item item);
    void useItem(); //just remove from list but dont remove from inventory to keep access

private slots:
    void on_continueButton_clicked();
    void on_PlayButton_clicked();
    void on_WUpButton_clicked();
    void on_KUpButton_clicked();
    void on_KLeftButton_clicked();
    void on_KRightButton_clicked();
    void on_KWLeftButton_clicked();
    void on_KWDownButton_clicked();
    void on_BDownButton_clicked();
    void on_SRightButton_clicked();

private:
    Ui::MainWindow *ui;
    Model model;
    Character mainCharacter;
    Dialogue d;
};
#endif // MAINWINDOW_H
