#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    juego = new Juego(this);

    setCentralWidget(juego);
}

MainWindow::~MainWindow()
{
    delete ui;
}
