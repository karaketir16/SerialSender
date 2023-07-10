#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_send_clicked();

    void on_sendPer_clicked();

    void on_stop_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort sp;
    QTimer tm;
};
#endif // MAINWINDOW_H
