#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "verb.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void leerVerbos();
    void lockCantidad();
    void selectMode();
    void inicializar();

private:
    Ui::MainWindow *ui;
    vector<verb> verbs;
    bool infiniteMode;
    int cantVerbosIniciales;
    int cantCorrectas;
    int cantVerbosUsados;
    QMessageBox errorArchivo;
    QMessageBox eleccionModo;
};
#endif // MAINWINDOW_H
