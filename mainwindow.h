#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include <QFileInfoList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonNext_clicked();

    void on_buttonPrev_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *labelImage;
    QStringList filesList;
    int counter;
};

#endif // MAINWINDOW_H
