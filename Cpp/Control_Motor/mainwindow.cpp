#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(&timer, SIGNAL(timeout()),
                     this, SLOT(OnTimer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OnTimer()
{
   //plot data
}


void MainWindow::on_ui_checkBox_param_clicked()
{
    //Parametros estandares cargados desde archivo xml


}


void MainWindow::on_ui_checkBox_pausa_stateChanged(int arg1)
{
    if(ui->ui_checkBox_pausa->isChecked())
    {
        timer.stop();
        ui->ui_label_error->setText(" ");
    } else
    {
         timer.start(500);
    }


}


void MainWindow::on_ui_pushButton_start_clicked()
{
    // uncheck pausa

    ui->ui_checkBox_pausa->setChecked(0);

    // Leer archivo v1
    QString archivo_entrada_name = ui->ui_lineEdit_entrada->text();

    // Load xml file as raw data
    QFile archivo_entrada;


    archivo_entrada.setFileName("v1.txt");

    archivo_entrada.open(QIODevice::ReadWrite);

    if(archivo_entrada.open(QIODevice::ReadOnly))
    {
        ui->ui_label_error->setText(" ");
    }
    else
    {

        ui->ui_label_error->setText("Archivo no encontrado");

    }

       archivo_entrada.close();



    // verifica el tipo de grafico deseado

    // Verifica los parametros deseados

    // Simula


}

