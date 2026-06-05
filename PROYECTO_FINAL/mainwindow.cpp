#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    juego = nullptr;

    connect(
        ui->btnNivel1,
        &QPushButton::clicked,
        this,
        &MainWindow::iniciarNivel1
        );

    connect(
        ui->btnNivel2,
        &QPushButton::clicked,
        this,
        &MainWindow::iniciarNivel2
        );

    connect(
        ui->btnSalir,
        &QPushButton::clicked,
        this,
        &MainWindow::salir
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarNivel1()
{
    juego = new Juego(1);
    juego->show();

    hide();
}

void MainWindow::iniciarNivel2()
{
    juego = new Juego(2);

    juego->show();

    hide();

}

void MainWindow::salir()
{
    close();
}
