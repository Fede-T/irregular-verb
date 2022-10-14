#include <qapplication.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QString>
#include <QTimer>
#include <string>
#include <QDebug>
#include <time.h>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon.png"));
    srand(time(NULL));
    iniciarVentanas();
    inicializar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarVentanas()
{
    //errorArchivo
    errorArchivo.setWindowTitle("Failed to open file");
    errorArchivo.setText("Error opening the file. Verify that the file exists");
    errorArchivo.setIcon(QMessageBox::Critical);
    errorArchivo.setWindowIcon(QIcon(":/icon.png"));
    errorArchivo.setEscapeButton(QMessageBox::Ok);


    //Eleccion de modo
    eleccionModo.setWindowTitle("Select mode");
    eleccionModo.setText("Select the mode to practice");
    eleccionModo.setIcon(QMessageBox::Question);
    eleccionModo.addButton("no repeat", QMessageBox::NoRole);
    eleccionModo.addButton("infinite", QMessageBox::YesRole);
    eleccionModo.addButton("help", QMessageBox::HelpRole);
    eleccionModo.setWindowIcon(QIcon(":/icon.png"));

    //Ayuda
    ayuda1.setWindowTitle("Help");
    ayuda1.setIcon(QMessageBox::Question);
    ayuda1.setText("- Infinite: Verbs will appear randomly without end.\n- No repeat: Verbs will appear randomly only 1 time.");
    ayuda1.setWindowIcon(QIcon(":/icon.png"));

    //Puntaje
    puntuacion.setWindowTitle("practice finished!");
    puntuacion.setText("Your score is: " + QString::number(this->puntos) + "/" + QString::number(this->puntosTotales) +
                       " points.\nWould you like to start again?");
    puntuacion.setIcon(QMessageBox::Information);
    puntuacion.addButton(QMessageBox::Yes);
    puntuacion.addButton(QMessageBox::No);
    puntuacion.setDefaultButton(QMessageBox::Yes);
    puntuacion.setEscapeButton(QMessageBox::No);
    puntuacion.setWindowIcon(QIcon(":/icon.png"));
}


void MainWindow::leerVerbos()
{
    fstream archivo("irregular_verbs.txt", ios::in);
    if (archivo.fail()){
        if(errorArchivo.exec() == QMessageBox::Ok)
            QTimer::singleShot(250, qApp, SLOT(quit()));
    }

    string infinitive, past_simple, past_participle;
    while(!archivo.eof()){
        //cin.ignore();
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

    eleccionModo.exec();
    int respuesta = eleccionModo.buttonRole(eleccionModo.clickedButton());
    while(respuesta == QMessageBox::HelpRole){
        //qDebug("help");
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
    ui->inf_verb->setText("verb");
    ui->ps_verb->setText("");
    ui->pp_verb->setText("");
    ui->puntos->setText(QString::number(0));
    ui->puntos_totales->setText(QString::number(0));
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
    this->setVerbo();
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

    ui->puntos->setText(QString::number(this->puntos));
    if(this->infiniteMode == true){
        this->puntosTotales += 2;
        ui->puntos_totales->setText(QString::number(this->puntosTotales));
    }

    if((this->infiniteMode == false) && (this->verbs.size() == 0)){
        puntuacion.setText("Your score is: " + QString::number(this->puntos) + "/" + QString::number(this->puntosTotales*2) +
                           " points.\nWould you like to start again?");
        mostrarPuntuacion();
    }
    else{
        this->setVerbo();
    }
}

void MainWindow::mostrarPuntuacion()
{
    if(puntuacion.exec() == QMessageBox::Yes){
        inicializar();
    }
    else{
        QTimer::singleShot(250, qApp, SLOT(quit()));
    }
}

void MainWindow::on_boton_clicked()
{
    corregir();
}

