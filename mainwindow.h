#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void handleInjectButton();
    void handleUnloadButton();

private:
    Ui::MainWindow *ui;
    QPushButton *injectButton;
    QPushButton *unloadButton;
};
#endif // MAINWINDOW_H
