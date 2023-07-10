#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWindow>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        ui->box->addItem(port.portName());
    }

    connect(&tm, &QTimer::timeout, this, &MainWindow::on_send_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
    sp.setPortName(ui->box->currentText());
    sp.setBaudRate(ui->baud->text().toInt());

    if(sp.open(QIODevice::ReadWrite)){
        ui->log->append("Port Opened succesfully");
    } else {
        ui->log->append(sp.errorString());
    }
}


void MainWindow::on_send_clicked()
{
    auto val = ui->data->text();
    val = val.remove("0x", Qt::CaseInsensitive);
    QByteArray data = QByteArray::fromHex(val.toUtf8());
    sp.write(data);
    qDebug() << data.toHex('-');
}


void MainWindow::on_sendPer_clicked()
{
    tm.start(ui->period->value());
}


void MainWindow::on_stop_clicked()
{
    tm.stop();
}

