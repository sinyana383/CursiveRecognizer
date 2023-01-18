#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qframe.h>

void MainWindow::handleButton()
{
    if (!(ui->widget->Pixels.empty()))
    {
        //QMessageBox::about(this,"test output", QString::number(ui->widget->Pixels[1]));//здесь нужно вызвать функцию распознавания
//        for (size_t i = 0; i < ui->widget->Pixels.size(); ++i)
//            std::cout << ui->widget->Pixels[i] << ",";
//        std::cout << std::endl;

        std::vector<int> results = _cont.predict(ui->widget->Pixels);
        std::cout << (char)(results[0] + 'A') << std::endl;
        std::cout << (char)(results[1] + 'A')  << std::endl;
        std::cout << (char)(results[2] + 'A')  << std::endl;
        std::cout << (char)(results[3] + 'A')  << std::endl;
        std::cout << std::endl;
//        QString a;
//        a[0] = QChar('A' + results[0]);
//        ui->label->setText(a);
    ui->widget->Pixels.clear();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(ui->pushButton_2, SIGNAL (clicked()), this, SLOT (bmp_file_dialog()));
}

void MainWindow::bmp_file_dialog() {
    QImage img = QImage(
        QFileDialog::getOpenFileName(this, tr("Open File"), "/path/to/file/", tr("Object Files (*.bmp)")));
    if (img.isNull())
    {
        return;
    }
    if (img.size().width() != img.size().height() || img.size().width() > 512 || img.size().height() > 512 ||
        img.size().width() < 28 || img.size().height() < 28) {
        QMessageBox::about(this, "Ошибка",
                           "Выберите квадратное изображение .bmp не меньше "
                           "28x28 и не больше 512x512");
    } else {
        img = img.scaled(28, 28);
        img = img.transformed(QTransform().rotate(-90)); // уже отзеркалено, нужно только повернуть

        ui->widget->Pixels.push_back(15); // -1 -> 15
        for (int i = img.size().width() - 1; i >= 0; i--) {
            for (int j = 0; j < img.size().height(); j++) {
                ui->widget->Pixels.push_back(img.pixelColor(j, i).black());
            }
        }
    }
    for (size_t i = 0; i < ui->widget->Pixels.size(); ++i)
        std::cout << ui->widget->Pixels[i] << ",";
    std::cout << std::endl;

    std::vector<int> results = _cont.predict(ui->widget->Pixels);
    std::cout << results[0] << std::endl;
    std::cout << results[1] << std::endl;
    std::cout << results[2] << std::endl;
    std::cout << results[3] << std::endl;
}


MainWindow::~MainWindow()
{
    delete ui;
}

