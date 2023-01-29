#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

// Library needed for processing XML documents
#include <QtXml>
// Library needed for processing files
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QTimer timer;

    QString archivo_entrada_name;

    QFile archivo_entrada;

     QString line;

    int tipo; // Tipo de grafico a ser plotado

    //Parametros del motor
    float diametro, masa, rozamiento, reduccion, bateria, Ts, rendimiento;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void OnTimer();

    void on_ui_checkBox_param_clicked();

    void on_ui_checkBox_pausa_stateChanged(int arg1);

    void on_ui_pushButton_start_clicked();

    void on_ui_pushButton_guardar_clicked();

    void on_ui_checkBox_param_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
