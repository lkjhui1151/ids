#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QDate>

void MainWindow::timefunction()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    QString time_text = date.toString("d / M / yyyy") + " " + time.toString(" H : mm : ss");

    this->setWindowTitle(time_text);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefunction()));
    timer->start(1000);
    ui->webView->load(QUrl("http://172.16.20.6/"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
