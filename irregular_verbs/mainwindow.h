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
    void verificar();
    void setVerbo();
    void corregir();
    void mostrarPuntuacion();
    void iniciarVentanas();

private slots:
    void on_boton_clicked();

private:
    Ui::MainWindow *ui;
    verb verboSeleccionado;
    int pos;
    vector<verb> verbs;
    bool infiniteMode = false;
    int cantVerbosIniciales;
    int puntos = 0;
    int puntosTotales = 0;
    QMessageBox errorArchivo;
    QMessageBox ayuda1;
    QMessageBox eleccionModo;
    QMessageBox puntuacion;
};
#endif // MAINWINDOW_H
