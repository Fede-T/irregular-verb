#include <qapplication.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QTimer>
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inicializar();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::leerVerbos()
{
    fstream archivo("irregular_verbs.txt", ios::in);
    if (archivo.fail()){
        errorArchivo.setWindowTitle("Fallo al abrir el archivo");
        errorArchivo.setText("Error al abrir el archivo. Verifique que el archivo exista");
        errorArchivo.setIcon(QMessageBox::Critical);
        if(errorArchivo.exec() == QMessageBox::Ok)
            QTimer::singleShot(250, qApp, SLOT(quit()));
    }

    string infinitive, past_simple, past_participle;
    while(!archivo.eof()){
        getline(archivo, infinitive, ' ');
        getline(archivo, past_simple, ' ');
        getline(archivo, past_participle, '\n');
        this->verbs.push_back(verb(infinitive, past_simple, past_participle));
    }

}

void MainWindow::lockCantidad()
{
    this->cantVerbosIniciales = this->verbs.size();
}

void MainWindow::selectMode()
{
    eleccionModo.setWindowTitle("Seleccionar modo");
    eleccionModo.setText("Selecciona el modo para practicar");
    eleccionModo.setIcon(QMessageBox::Question);
    eleccionModo.addButton("infinito", QMessageBox::YesRole);
    eleccionModo.addButton("sin repeticion", QMessageBox::NoRole);
    eleccionModo.addButton("ayuda", QMessageBox::HelpRole);
    eleccionModo.exec();
    int respuesta = eleccionModo.buttonRole(eleccionModo.clickedButton());
    while(respuesta == QMessageBox::HelpRole){
        //qDebug("help");
        QMessageBox ayuda1;
        ayuda1.setWindowTitle("ayuda");
        ayuda1.setIcon(QMessageBox::Question);
        ayuda1.setText("- Infinito: Saldrán verbos de manera aleatoria sin fin.\n- Sin repeticion: Saldran verbos de manera aleatoria solo 1 vez.");
        ayuda1.exec();
        eleccionModo.exec();
        respuesta = eleccionModo.buttonRole(eleccionModo.clickedButton());
    }

    if(QMessageBox::YesRole == respuesta){
        this->infiniteMode = true;
        //qDebug("modo infi");
    }else if (QMessageBox::NoRole == respuesta){
        this->infiniteMode = false;
        //qDebug("no inf");
    }
}

void MainWindow::inicializar()
{
    ui->boton->setEnabled(false);
    this->verbs.clear();
    this->leerVerbos();
    this->lockCantidad();
    this->selectMode();
    this->cantCorrectas = 0;
    this->cantVerbosUsados = 0;
    ui->boton->setEnabled(true);
}

