#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "juego.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void iniciarNivel1();

    void iniciarNivel2();

    void salir();

private:

    Ui::MainWindow *ui;

    Juego *juego;
};

#endif // MAINWINDOW_H
