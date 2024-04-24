#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    ui->setupUi(this);
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);
    this->resize(800, 600);

    injectButton = new QPushButton("注入", this);
    unloadButton = new QPushButton("卸载", this);
    injectButton->setFixedSize(100,50);
    unloadButton->setFixedSize(100,50);
    layout->addWidget(injectButton);
    layout->addWidget(unloadButton);

    // Connect button click signals to the handling functions
    connect(injectButton, &QPushButton::clicked, this, &MainWindow::handleInjectButton);
    connect(unloadButton, &QPushButton::clicked, this, &MainWindow::handleUnloadButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleInjectButton()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("注入中...");
    msgBox->show();

    QTimer::singleShot(2000, this, [=]() {
        msgBox->setText("注入成功!");
    });
}

void MainWindow::handleUnloadButton()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText("卸载中...");
    msgBox->show();

    QTimer::singleShot(2000, this, [=]() {
        msgBox->setText("卸载成功!");
    });
}
