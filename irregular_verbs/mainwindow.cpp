#include <qapplication.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QString>
#include <QTimer>
#include <string>
#include <QDebug>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    inicializar();
    setVerbo();
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
    eleccionModo.addButton("sin repeticion", QMessageBox::NoRole);
    eleccionModo.addButton("infinito", QMessageBox::YesRole);
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
    this->puntos = 0;
    if(this->infiniteMode == false){
        this->puntosTotales = this->verbs.size();
        ui->puntos_totales->setText(QString::number(this->puntosTotales*2));
        ui->puntos->setText(QString::number(this->puntos));
    }
    else{
        ui->puntos_totales->setText(QString::number(0));
        ui->puntos_totales->setText(QString::number(this->puntos));
    }
    ui->boton->setEnabled(true);
}

void MainWindow::verificar()
{

}

void MainWindow::setVerbo()
{
    if(this->infiniteMode == false){
        pos = rand() % this->verbs.size() + 0;
        this->verboSeleccionado.setData(this->verbs[pos].getInfinitive(), this->verbs[pos].getPast_simple(), this->verbs[pos].getPast_participle());
        ui->inf_verb->setText(QString::fromStdString(this->verboSeleccionado.getInfinitive()));
        this->verbs.erase(this->verbs.begin()+pos);
    }
    else{
        pos = rand() % this->verbs.size() + 0;
        this->verboSeleccionado.setData(this->verbs[pos].getInfinitive(), this->verbs[pos].getPast_simple(), this->verbs[pos].getPast_participle());
        ui->inf_verb->setText(QString::fromStdString(this->verboSeleccionado.getInfinitive()));
    }

    ui->ps_verb->setText("");
    ui->pp_verb->setText("");

}

void MainWindow::corregir()
{
    QString ps = ui->ps_verb->text();
    QString pp = ui->pp_verb->text();
    if(this->verboSeleccionado.comparePS(ps.toStdString())){
        this->puntos++;
        ui->ps_correct->setStyleSheet("color: green;");
        ui->ps_correct->setText(QString::fromStdString(this->verboSeleccionado.getPast_simple()));
    }
    else{
        ui->ps_correct->setStyleSheet("color: red;");
        ui->ps_correct->setText(QString::fromStdString(this->verboSeleccionado.getPast_simple()));
    }

    if(this->verboSeleccionado.comparePP(pp.toStdString())){
        this->puntos++;
        ui->pp_correct->setStyleSheet("color: green");
        ui->pp_correct->setText(QString::fromStdString(this->verboSeleccionado.getPast_participle()));
    }
    else{
        ui->pp_correct->setStyleSheet("color: red");
        ui->pp_correct->setText(QString::fromStdString(this->verboSeleccionado.getPast_participle()));
    }
    if(this->infiniteMode == true){
        this->puntosTotales += 2;
    }

    ui->puntos->setText(QString::number(this->puntos));
    if(this->infiniteMode == true){
        this->puntosTotales += 2;
        ui->puntos_totales->setText(QString::number(this->puntosTotales));
    }

    this->setVerbo();
}

void MainWindow::on_boton_clicked()
{
    corregir();
}

