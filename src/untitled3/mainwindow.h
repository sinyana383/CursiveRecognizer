#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/Users/ddurrand/Desktop/MLLP/src/control/Control.hpp" // относительный путь будет

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public Q_SLOTS:
    void handleButton();
    void bmp_file_dialog();

private:
    Ui::MainWindow *ui;
    s21::Control _cont;
};
#endif // MAINWINDOW_H
