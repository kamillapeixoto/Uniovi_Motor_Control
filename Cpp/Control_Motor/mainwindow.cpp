#include "mainwindow.h"
#include "ui_mainwindow.h"

float MainWindow::readXML(const QString str_xml, const QString tag_xml)
{

    QString open_tag = "<" + tag_xml + ">";
    QString close_tag = "</" + tag_xml + ">";


    // Indices de inicio y final de las tags
    int tag_start = str_xml.indexOf(open_tag);
    int tag_end = str_xml.indexOf(close_tag);

    // Donde la tag de inicio termina
    tag_start =tag_start + open_tag.length();

    // Calcular el tamaño de la variable
    int length_variable = tag_end - tag_start;

    // Cortar solamente la parte interesante
    QString valor_string = str_xml.mid(tag_start, length_variable);

    // Limpiar los espacios extras
    valor_string = valor_string.trimmed();

    // Cambia para float
    float valor_xml = valor_string.toFloat();

    return valor_xml;


}

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
      //{
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

        //Actualiza los parametros baseados en la spinbox
        diametro = ui->ui_doubleSpinBox_diametro->value();
        masa = ui->ui_doubleSpinBox_masa->value();
        rozamiento = ui->ui_doubleSpinBox_rozamiento->value();
        reduccion = ui->ui_doubleSpinBox_reduccion->value();
        bateria = ui->ui_doubleSpinBox_tension->value();
        Ts =  ui->ui_doubleSpinBox_ts->value();
        rendimiento = ui->ui_doubleSpinBox_rendimiento->value();


    }
    else
    {
        ui->ui_label_error->setText("Archivo no encontrado");
    }





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
        //Parametros estandares cargados desde archivo xml
      /*
        QFile xml_file;
        xml_file.setFileName("params_xml.xml");

        bool filexml_ok = xml_file.open(QIODevice::ReadOnly);

        QTextStream qtOut(stdout);

        QTextStream in(&archivo_entrada);
           while (!in.atEnd())
          {
              line = in.readLine();
             // QString line2 = archivo_entrada.readAll();

           }

        qtOut <<"xml" << line <<"\n";
        qtOut.flush();

        */

        // Solamente para testar mientras aprendo a leer el archivo
        QString parametros = "   <WheelDiam_mm>200.0</WheelDiam_mm><Mass_Kg>25.0</Mass_Kg><Friction_B_N__m_s>0.5</Friction_B_N__m_s> <Reduction>20.0</Reduction> <Voltage_V>24.0</Voltage_V><Tm_ms>15</Tm_ms>";



        diametro =  readXML(parametros, "WheelDiam_mm")/1000;
        ui->ui_doubleSpinBox_diametro->setValue(diametro);

        masa = readXML(parametros, "Mass_Kg");
        ui->ui_doubleSpinBox_masa->setValue(masa);

        rozamiento = readXML(parametros, "Friction_B_N__m_s");
        ui->ui_doubleSpinBox_rozamiento->setValue(rozamiento);

        reduccion = 1/readXML(parametros, "Reduction");
        ui->ui_doubleSpinBox_reduccion->setValue(reduccion);

        bateria = readXML(parametros, "Voltage_V");
        ui->ui_doubleSpinBox_tension->setValue(bateria);

        Ts = readXML(parametros, "Tm_ms")/1000;
        ui->ui_doubleSpinBox_ts->setValue(Ts);

        rendimiento = 1;
        ui->ui_doubleSpinBox_rendimiento->setValue(rendimiento);


    // Actualiza y Bloquea las spinbox

    } else{
        // Desbloquea las spinbox
    }

}

