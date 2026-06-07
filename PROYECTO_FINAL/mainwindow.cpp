#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap fondo(":/sprites/fondo_menu.png");

    QPalette palette;
    palette.setBrush(
        QPalette::Window,
        fondo.scaled(
            size(),
            Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation
            )
        );

    setPalette(palette);
    setAutoFillBackground(true);

    qDebug() << fondo.isNull();

    ui->btnNivel1->setText("");

    ui->btnNivel1->setIcon(
        QIcon(":/sprites/nivel1.png")
        );

    ui->btnNivel1->setIconSize(
        ui->btnNivel1->size()
        );

    ui->btnNivel2->setText("");

    ui->btnNivel2->setIcon(
        QIcon(":/sprites/nivel2.png")
        );

    ui->btnNivel2->setIconSize(
        ui->btnNivel2->size()
        );

    ui->btnSalir->setText("");

    ui->btnSalir->setIcon(
        QIcon(":/sprites/salir.png")
        );

    ui->btnSalir->setIconSize(
        ui->btnSalir->size()
        );

    ui->btnNivel1->setStyleSheet(
        "border:none;"
        );

    ui->btnNivel2->setStyleSheet(
        "border:none;"
        );

    ui->btnSalir->setStyleSheet(
        "border:none;"
        );

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


    audioMenu = new QAudioOutput(this);

    musicaMenu = new QMediaPlayer(this);

    musicaMenu->setAudioOutput(audioMenu);

    audioMenu->setVolume(0.5);

    musicaMenu->setSource(
        QUrl("qrc:/sprites/menu.mp3")
        );

    musicaMenu->setLoops(
        QMediaPlayer::Infinite
        );

    musicaMenu->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarNivel1()
{
    musicaMenu->stop();

    juego = new Juego(1);

    juego->showMaximized();

    hide();
}

void MainWindow::iniciarNivel2()
{
    musicaMenu->stop();

    juego = new Juego(2);

    juego->showMaximized();

    hide();

}

void MainWindow::salir()
{
    close();
}
