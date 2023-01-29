/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCheckBox *ui_checkBox_pausa;
    QLineEdit *ui_lineEdit_entrada;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ui_lineEdit_salida;
    QCheckBox *ui_checkBox_param;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *ui_doubleSpinBox_diametro;
    QDoubleSpinBox *ui_doubleSpinBox_masa;
    QDoubleSpinBox *ui_doubleSpinBox_rozamiento;
    QDoubleSpinBox *ui_doubleSpinBox_reduccion;
    QDoubleSpinBox *ui_doubleSpinBox_tension;
    QDoubleSpinBox *ui_doubleSpinBox_ts;
    QDoubleSpinBox *ui_doubleSpinBox_rendimiento;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBox;
    QPushButton *ui_pushButton_guardar;
    QPushButton *ui_pushButton_start;
    QLabel *ui_label_error;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuIMPLE_Motor;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(503, 289);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ui_checkBox_pausa = new QCheckBox(centralwidget);
        ui_checkBox_pausa->setObjectName(QString::fromUtf8("ui_checkBox_pausa"));
        ui_checkBox_pausa->setEnabled(true);
        ui_checkBox_pausa->setGeometry(QRect(40, 100, 58, 18));
        ui_checkBox_pausa->setChecked(true);
        ui_checkBox_pausa->setTristate(false);
        ui_lineEdit_entrada = new QLineEdit(centralwidget);
        ui_lineEdit_entrada->setObjectName(QString::fromUtf8("ui_lineEdit_entrada"));
        ui_lineEdit_entrada->setGeometry(QRect(130, 20, 113, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 111, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 170, 81, 16));
        ui_lineEdit_salida = new QLineEdit(centralwidget);
        ui_lineEdit_salida->setObjectName(QString::fromUtf8("ui_lineEdit_salida"));
        ui_lineEdit_salida->setGeometry(QRect(110, 170, 113, 20));
        ui_checkBox_param = new QCheckBox(centralwidget);
        ui_checkBox_param->setObjectName(QString::fromUtf8("ui_checkBox_param"));
        ui_checkBox_param->setGeometry(QRect(250, 10, 111, 18));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 30, 37, 12));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 60, 37, 12));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 90, 51, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 120, 41, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 150, 37, 12));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(280, 180, 37, 12));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 210, 51, 20));
        ui_doubleSpinBox_diametro = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_diametro->setObjectName(QString::fromUtf8("ui_doubleSpinBox_diametro"));
        ui_doubleSpinBox_diametro->setGeometry(QRect(330, 30, 62, 22));
        ui_doubleSpinBox_diametro->setValue(0.200000000000000);
        ui_doubleSpinBox_masa = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_masa->setObjectName(QString::fromUtf8("ui_doubleSpinBox_masa"));
        ui_doubleSpinBox_masa->setGeometry(QRect(330, 60, 62, 22));
        ui_doubleSpinBox_masa->setValue(25.000000000000000);
        ui_doubleSpinBox_rozamiento = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_rozamiento->setObjectName(QString::fromUtf8("ui_doubleSpinBox_rozamiento"));
        ui_doubleSpinBox_rozamiento->setGeometry(QRect(330, 90, 62, 22));
        ui_doubleSpinBox_rozamiento->setValue(0.500000000000000);
        ui_doubleSpinBox_reduccion = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_reduccion->setObjectName(QString::fromUtf8("ui_doubleSpinBox_reduccion"));
        ui_doubleSpinBox_reduccion->setGeometry(QRect(330, 120, 62, 22));
        ui_doubleSpinBox_reduccion->setValue(0.050000000000000);
        ui_doubleSpinBox_tension = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_tension->setObjectName(QString::fromUtf8("ui_doubleSpinBox_tension"));
        ui_doubleSpinBox_tension->setGeometry(QRect(330, 150, 62, 22));
        ui_doubleSpinBox_tension->setValue(24.000000000000000);
        ui_doubleSpinBox_ts = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_ts->setObjectName(QString::fromUtf8("ui_doubleSpinBox_ts"));
        ui_doubleSpinBox_ts->setGeometry(QRect(330, 180, 62, 22));
        ui_doubleSpinBox_ts->setValue(0.010000000000000);
        ui_doubleSpinBox_rendimiento = new QDoubleSpinBox(centralwidget);
        ui_doubleSpinBox_rendimiento->setObjectName(QString::fromUtf8("ui_doubleSpinBox_rendimiento"));
        ui_doubleSpinBox_rendimiento->setGeometry(QRect(330, 210, 62, 22));
        ui_doubleSpinBox_rendimiento->setMaximum(1.000000000000000);
        ui_doubleSpinBox_rendimiento->setValue(1.000000000000000);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(400, 30, 37, 12));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(400, 60, 37, 12));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(400, 90, 37, 12));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(400, 150, 37, 12));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(400, 180, 37, 12));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 60, 221, 22));
        ui_pushButton_guardar = new QPushButton(centralwidget);
        ui_pushButton_guardar->setObjectName(QString::fromUtf8("ui_pushButton_guardar"));
        ui_pushButton_guardar->setGeometry(QRect(90, 210, 80, 18));
        ui_pushButton_start = new QPushButton(centralwidget);
        ui_pushButton_start->setObjectName(QString::fromUtf8("ui_pushButton_start"));
        ui_pushButton_start->setGeometry(QRect(160, 100, 80, 18));
        ui_label_error = new QLabel(centralwidget);
        ui_label_error->setObjectName(QString::fromUtf8("ui_label_error"));
        ui_label_error->setEnabled(true);
        ui_label_error->setGeometry(QRect(80, 140, 141, 16));
        QFont font;
        font.setBold(true);
        ui_label_error->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 503, 17));
        menuIMPLE_Motor = new QMenu(menubar);
        menuIMPLE_Motor->setObjectName(QString::fromUtf8("menuIMPLE_Motor"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuIMPLE_Motor->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ui_checkBox_pausa->setText(QCoreApplication::translate("MainWindow", "Pausa", nullptr));
        ui_lineEdit_entrada->setText(QCoreApplication::translate("MainWindow", "v1.txt", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Archivo de entrada", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Archivo de salida", nullptr));
        ui_checkBox_param->setText(QCoreApplication::translate("MainWindow", "Parametros estandares", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Diametro", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Masa", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Rozamiento", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Reduccion", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Tension", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ts", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rendimiento", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "kg", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "N/(m/s)", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "a. Fuerza de empuje de la rueda (N)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "b. Velocidad de giro del motor (rpm)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "c. Velocidad lineal del veh\303\255culo (km/h)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "d. Desplazamiento del veh\303\255culo (m)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "e. Potencia consumida por el motor (W)", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "f. Corriente suministrada por la bater\303\255a (A)", nullptr));

        ui_pushButton_guardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        ui_pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        ui_label_error->setText(QString());
        menuIMPLE_Motor->setTitle(QCoreApplication::translate("MainWindow", "IMPLE - Motor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
