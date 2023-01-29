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
   // Leer, simula y plota datos

    //Leer
    QTextStream qtOut(stdout);

    QTextStream in(&archivo_entrada);
       //if (!in.atEnd())
      // {
          line = in.readLine();
          QString line2 = archivo_entrada.readAll();

       //}

    qtOut <<"Data Received" << line << line2 <<"\n";
    qtOut.flush();




   //Simula
    switch(tipo){
    case 1:
        //a. Fuerza de empuje de la rueda (N)
    break;
    case 2:
       // b. Velocidad de giro del motor (rpm)
    break;
    case 3:
        //c. Velocidad lineal del vehículo (km/h)
    break;
    case 4:
        //d. Desplazamiento del vehículo (m)
    break;
    case 5:
        //e. Potencia consumida por el motor (W)
    break;
    case 6:
        //f. Corriente suministrada por la batería (A)
    break;
    }


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
    archivo_entrada_name = ui->ui_lineEdit_entrada->text();

    // Load xml file
    archivo_entrada.setFileName(archivo_entrada_name);

    bool file_ok = archivo_entrada.open(QIODevice::ReadOnly);

    if(file_ok)
    {
        ui->ui_label_error->setText(" ");
        // verifica el tipo de grafico deseado
        tipo = ui->comboBox->currentIndex();


    }
    else
    {
        ui->ui_label_error->setText("Archivo no encontrado");
    }

    //Actualiza los parametros baseados en la spinbox







}


void MainWindow::on_ui_pushButton_guardar_clicked()
{
    // Cerra el archivo de entrada
    archivo_entrada.close();

    // Escribe el archivo de salida
}


void MainWindow::on_ui_checkBox_param_stateChanged(int arg1)
{
    if(ui->ui_checkBox_param->isChecked())
    {
    // Read XML File

    // Actualiza y Bloquea los spinbox
    }



}

