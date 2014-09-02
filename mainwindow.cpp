#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    counter = 0;

    QDir dir("D:/Photos");
    filesList = dir.entryList(QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files);
    qDebug() << filesList.size();
    qDebug() << filesList;

    ui->labelPrevImage->setText("");
    ui->labelCurImage->setText(filesList.at(counter));
    ui->labelNextImage->setText(filesList.at(counter+1));

    QPixmap img("D:/Photos/"+filesList.at(counter));
    ui->labelImage->setPixmap(img);

    ui->labelPrevImage->setEnabled(false);
    ui->buttonPrev->setEnabled(false);
    ui->buttonNext->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonNext_clicked()
{
    qDebug()<<counter;
    ui->labelPrevImage->setEnabled(true);
    ui->buttonPrev->setEnabled(true);

    if(++counter > filesList.size()-2)
    {
        ui->labelNextImage->setText("");
        ui->labelNextImage->setEnabled(false);
        ui->buttonNext->setEnabled(false);
    }
    else
    {
        ui->labelNextImage->setText(filesList.at(counter+1));
        ui->buttonNext->setEnabled(true);
    }

    ui->labelPrevImage->setText(filesList.at(counter-1));
    ui->labelCurImage->setText(filesList.at(counter));

    QPixmap img("D:/Photos/"+filesList.at(counter));
    ui->labelImage->setPixmap(img);
}

void MainWindow::on_buttonPrev_clicked()
{
    qDebug()<<counter;
    ui->labelNextImage->setEnabled(true);
    ui->buttonNext->setEnabled(true);

    if(--counter < 1)
    {
        ui->labelPrevImage->setText("");
        ui->labelPrevImage->setEnabled(false);
        ui->buttonPrev->setEnabled(false);
    }
    else
    {
        ui->labelPrevImage->setText(filesList.at(counter-1));
        ui->buttonPrev->setEnabled(true);
    }

    ui->labelNextImage->setText(filesList.at(counter+1));
    ui->labelCurImage->setText(filesList.at(counter));

    QPixmap img("D:/Photos/"+filesList.at(counter));
    ui->labelImage->setPixmap(img);
}
