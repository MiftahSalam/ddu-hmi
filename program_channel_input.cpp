#include <QSqlQuery>
#include <QSqlError>

#include "program_channel_input.h"
#include "ui_program_channel_input.h"

program_channel_input::program_channel_input(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::program_channel_input)
{
    ui->setupUi(this);
}

program_channel_input::~program_channel_input()
{
    delete ui;
}

void program_channel_input::on_pushButton_19_clicked()
{
    back_to_home_2();
    create_database();
}


void program_channel_input::create_database()
{
	QSqlQuery query;

    query.prepare(QString("UPDATE ddu_ch SET cur_restarted_stat='1' where ch_id=%1;").arg(id_channel_input));
    query.exec();
    qDebug()<<"debug restarted"<<query.lastQuery();

    query.clear();

    QString ambil_jenis = ui->combo_jenis_sensor->currentText();
    QString ambil_nama = ui->combo_nama_sensor->currentText();
    QString ambil_priority = ui->combo_priority->currentText();
    QString ambil_baudrate = ui->combo_baudrate->currentText();
    QString ambil_databit = ui->combo_databits->currentText();
    QString ambil_parity = ui->combo_parity->currentText();
    QString ambil_stopbit = ui->combo_stopbits->currentText();
    QString ambil_flow = ui->combo_flow_control->currentText();
    QString ambil_output_value = ui->combo_output_value->currentText();

    query.prepare(QString("UPDATE ddu_ch SET cur_jenis_sensor='%2', cur_sensor_name='%3', cur_priority='%4', cur_ser_baud='%5', cur_ser_parity='%6', cur_ser_data_bits='%7', cur_ser_stop_bit='%8', cur_ser_flow='%9', cur_protokol='%13' where ch_id=%14;").arg(ambil_jenis).arg(ambil_nama).arg(ambil_priority).arg(ambil_baudrate).arg(ambil_parity).arg(ambil_databit).arg(ambil_stopbit).arg(ambil_flow).arg(ambil_output_value).arg(id_channel_input));
    query.exec();

    qDebug()<<"Update Combobox"<<query.lastQuery();
}


void program_channel_input::setup_program_channel_input(QString id_channel)
{
    qDebug()<<"Id Channel adalah "<<id_channel;
	QSqlQuery query;

    query.prepare(QString("SELECT * FROM ddu_ch where ch_id = %1;").arg(id_channel));
    query.exec();
    query.seek(0);
    qDebug()<<query.lastQuery();

    id_channel_input=id_channel;

    qDebug()<<"Id channel input "<<id_channel_input;

    ui->combo_nama_sensor->show();
    QString nama_sensor = query.value(1).toString();
    if(!QString::compare(nama_sensor, "Not Connected"))
        ui->combo_nama_sensor->setCurrentIndex(0);
    else if(!QString::compare(nama_sensor, "AIS"))
        ui->combo_nama_sensor->setCurrentIndex(1);
    else if(!QString::compare(nama_sensor, "ARPA"))
        ui->combo_nama_sensor->setCurrentIndex(2);
    else if(!QString::compare(nama_sensor, "Echo Sounder 1"))
        ui->combo_nama_sensor->setCurrentIndex(3);
    else if(!QString::compare(nama_sensor, "Echo Sounder 2"))
        ui->combo_nama_sensor->setCurrentIndex(4);
    else if(!QString::compare(nama_sensor, "Echo Sounder 3"))
        ui->combo_nama_sensor->setCurrentIndex(5);
    else if(!QString::compare(nama_sensor, "GPS 1"))
        ui->combo_nama_sensor->setCurrentIndex(6);
    else if(!QString::compare(nama_sensor, "GPS 2"))
        ui->combo_nama_sensor->setCurrentIndex(7);
    else if(!QString::compare(nama_sensor, "GPS 3"))
        ui->combo_nama_sensor->setCurrentIndex(8);
    else if(!QString::compare(nama_sensor, "Gyro Compas 1"))
        ui->combo_nama_sensor->setCurrentIndex(9);
    else if(!QString::compare(nama_sensor, "Gyro Compas 2"))
        ui->combo_nama_sensor->setCurrentIndex(10);
    else if(!QString::compare(nama_sensor, "Gyro Compas 3"))
        ui->combo_nama_sensor->setCurrentIndex(11);
    else if(!QString::compare(nama_sensor, "Gyro Vertical 1"))
        ui->combo_nama_sensor->setCurrentIndex(12);
    else if(!QString::compare(nama_sensor, "Gyro Vertical 2"))
        ui->combo_nama_sensor->setCurrentIndex(13);
    else if(!QString::compare(nama_sensor, "Gyro Vertical 3"))
        ui->combo_nama_sensor->setCurrentIndex(14);
    else if(!QString::compare(nama_sensor, "Meteo"))
        ui->combo_nama_sensor->setCurrentIndex(15);
    else if(!QString::compare(nama_sensor, "Speedlog 1"))
		ui->combo_nama_sensor->setCurrentIndex(16);
    else if(!QString::compare(nama_sensor, "Speedlog 2"))
		ui->combo_nama_sensor->setCurrentIndex(17);
    else if(!QString::compare(nama_sensor, "Speedlog 3"))
		ui->combo_nama_sensor->setCurrentIndex(18);
    else if(!QString::compare(nama_sensor, "Wind Direction 1"))
		ui->combo_nama_sensor->setCurrentIndex(19);
    else if(!QString::compare(nama_sensor, "Wind Direction 2"))
		ui->combo_nama_sensor->setCurrentIndex(20);
    else if(!QString::compare(nama_sensor, "Wind Direction 3"))
		ui->combo_nama_sensor->setCurrentIndex(21);

    ui->combo_baudrate->show();
    QString baudrate = query.value(8).toString();
    if(!QString::compare(baudrate, ""))
        ui->combo_baudrate->setCurrentIndex(0);
    else if(!QString::compare(baudrate, "1200"))
        ui->combo_baudrate->setCurrentIndex(1);
    else if(!QString::compare(baudrate, "2400"))
        ui->combo_baudrate->setCurrentIndex(2);
    else if(!QString::compare(baudrate, "4800"))
        ui->combo_baudrate->setCurrentIndex(3);
    else if(!QString::compare(baudrate, "9600"))
        ui->combo_baudrate->setCurrentIndex(4);
    else if(!QString::compare(baudrate, "38400"))
        ui->combo_baudrate->setCurrentIndex(5);
    else if(!QString::compare(baudrate, "115200"))
        ui->combo_baudrate->setCurrentIndex(6);
    else if(!QString::compare(baudrate, "829440"))
        ui->combo_baudrate->setCurrentIndex(7);

    ui->combo_databits->show();
    QString databits = query.value(10).toString();
    if(!QString::compare(databits, ""))
        ui->combo_databits->setCurrentIndex(0);
    else if(!QString::compare(databits, "5"))
        ui->combo_databits->setCurrentIndex(1);
    else if(!QString::compare(databits, "6"))
        ui->combo_databits->setCurrentIndex(2);
    else if(!QString::compare(databits, "7"))
        ui->combo_databits->setCurrentIndex(3);
    else if(!QString::compare(databits, "8"))
        ui->combo_databits->setCurrentIndex(4);

    ui->combo_parity->show();
    QString parity = query.value(15).toString();
    if(!QString::compare(parity, ""))
        ui->combo_parity->setCurrentIndex(0);
    else if(!QString::compare(parity, "NONE"))
        ui->combo_parity->setCurrentIndex(1);
    else if(!QString::compare(parity, "ODD"))
        ui->combo_parity->setCurrentIndex(2);
    else if(!QString::compare(parity, "EVEN"))
        ui->combo_parity->setCurrentIndex(3);

    ui->combo_stopbits->show();
    QString stopbits = query.value(9).toString();
    if(!QString::compare(stopbits, ""))
        ui->combo_stopbits->setCurrentIndex(0);
    else if(!QString::compare(stopbits, "1"))
        ui->combo_stopbits->setCurrentIndex(1);
    else if(!QString::compare(stopbits, "2"))
        ui->combo_stopbits->setCurrentIndex(2);

    ui->combo_jenis_sensor->show();
    QString jenis_sensor = query.value(18).toString();
    if(!QString::compare(jenis_sensor, ""))
        ui->combo_jenis_sensor->setCurrentIndex(0);
    else if(!QString::compare(jenis_sensor, "AG"))
        ui->combo_jenis_sensor->setCurrentIndex(1);
    else if(!QString::compare(jenis_sensor, "AI"))
        ui->combo_jenis_sensor->setCurrentIndex(2);
    else if(!QString::compare(jenis_sensor, "AP"))
        ui->combo_jenis_sensor->setCurrentIndex(3);
    else if(!QString::compare(jenis_sensor, "CD"))
        ui->combo_jenis_sensor->setCurrentIndex(4);
    else if(!QString::compare(jenis_sensor, "CR"))
        ui->combo_jenis_sensor->setCurrentIndex(5);
    else if(!QString::compare(jenis_sensor, "CS"))
        ui->combo_jenis_sensor->setCurrentIndex(6);
    else if(!QString::compare(jenis_sensor, "CT"))
        ui->combo_jenis_sensor->setCurrentIndex(7);
    else if(!QString::compare(jenis_sensor, "CV"))
        ui->combo_jenis_sensor->setCurrentIndex(8);
    else if(!QString::compare(jenis_sensor, "CX"))
        ui->combo_jenis_sensor->setCurrentIndex(9);
    else if(!QString::compare(jenis_sensor, "DE"))
        ui->combo_jenis_sensor->setCurrentIndex(10);
    else if(!QString::compare(jenis_sensor, "DF"))
        ui->combo_jenis_sensor->setCurrentIndex(11);
    else if(!QString::compare(jenis_sensor, "EC"))
        ui->combo_jenis_sensor->setCurrentIndex(12);
    else if(!QString::compare(jenis_sensor, "EP"))
        ui->combo_jenis_sensor->setCurrentIndex(13);
    else if(!QString::compare(jenis_sensor, "ER"))
        ui->combo_jenis_sensor->setCurrentIndex(14);
    else if(!QString::compare(jenis_sensor, "GL"))
        ui->combo_jenis_sensor->setCurrentIndex(15);
    else if(!QString::compare(jenis_sensor, "GN"))
        ui->combo_jenis_sensor->setCurrentIndex(16);
    else if(!QString::compare(jenis_sensor, "GP"))
        ui->combo_jenis_sensor->setCurrentIndex(17);
    else if(!QString::compare(jenis_sensor, "GV"))
        ui->combo_jenis_sensor->setCurrentIndex(18);
    else if(!QString::compare(jenis_sensor, "HC"))
        ui->combo_jenis_sensor->setCurrentIndex(19);
    else if(!QString::compare(jenis_sensor, "HE"))
        ui->combo_jenis_sensor->setCurrentIndex(20);
    else if(!QString::compare(jenis_sensor, "HN"))
        ui->combo_jenis_sensor->setCurrentIndex(21);
    else if(!QString::compare(jenis_sensor, "II"))
        ui->combo_jenis_sensor->setCurrentIndex(22);
    else if(!QString::compare(jenis_sensor, "IN"))
        ui->combo_jenis_sensor->setCurrentIndex(23);
    else if(!QString::compare(jenis_sensor, "LA"))
        ui->combo_jenis_sensor->setCurrentIndex(24);
    else if(!QString::compare(jenis_sensor, "LC"))
        ui->combo_jenis_sensor->setCurrentIndex(25);
    else if(!QString::compare(jenis_sensor, "OM"))
        ui->combo_jenis_sensor->setCurrentIndex(26);
    else if(!QString::compare(jenis_sensor, "P"))
        ui->combo_jenis_sensor->setCurrentIndex(27);
    else if(!QString::compare(jenis_sensor, "RA"))
        ui->combo_jenis_sensor->setCurrentIndex(28);
    else if(!QString::compare(jenis_sensor, "SD"))
        ui->combo_jenis_sensor->setCurrentIndex(29);
    else if(!QString::compare(jenis_sensor, "SN"))
        ui->combo_jenis_sensor->setCurrentIndex(30);
    else if(!QString::compare(jenis_sensor, "SS"))
        ui->combo_jenis_sensor->setCurrentIndex(31);
    else if(!QString::compare(jenis_sensor, "TI"))
        ui->combo_jenis_sensor->setCurrentIndex(32);
    else if(!QString::compare(jenis_sensor, "TR"))
        ui->combo_jenis_sensor->setCurrentIndex(33);
    else if(!QString::compare(jenis_sensor, "VD"))
        ui->combo_jenis_sensor->setCurrentIndex(34);
    else if(!QString::compare(jenis_sensor, "VM"))
        ui->combo_jenis_sensor->setCurrentIndex(35);
    else if(!QString::compare(jenis_sensor, "VW"))
        ui->combo_jenis_sensor->setCurrentIndex(36);
    else if(!QString::compare(jenis_sensor, "YX"))
        ui->combo_jenis_sensor->setCurrentIndex(37);
    else if(!QString::compare(jenis_sensor, "ZA"))
        ui->combo_jenis_sensor->setCurrentIndex(38);
    else if(!QString::compare(jenis_sensor, "ZC"))
        ui->combo_jenis_sensor->setCurrentIndex(39);
    else if(!QString::compare(jenis_sensor, "ZQ"))
        ui->combo_jenis_sensor->setCurrentIndex(40);
    else if(!QString::compare(jenis_sensor, "ZV"))
        ui->combo_jenis_sensor->setCurrentIndex(41);
    else if(!QString::compare(jenis_sensor, "WI"))
        ui->combo_jenis_sensor->setCurrentIndex(42);

    ui->combo_priority->show();
    QString priority = query.value(5).toString();
    qDebug()<<"Priority"<<priority;
    if(!QString::compare(priority, ""))
        ui->combo_priority->setCurrentIndex(0);
    else if(!QString::compare(priority, "1"))
        ui->combo_priority->setCurrentIndex(1);
    else if(!QString::compare(priority, "2"))
        ui->combo_priority->setCurrentIndex(2);
    else if(!QString::compare(priority, "3"))
        ui->combo_priority->setCurrentIndex(3);
    else if(!QString::compare(priority, "4"))
        ui->combo_priority->setCurrentIndex(4);
    else if(!QString::compare(priority, "5"))
        ui->combo_priority->setCurrentIndex(5);

    ui->combo_flow_control->show();
    QString flow_control = query.value(16).toString();
    if(!QString::compare(flow_control, ""))
        ui->combo_flow_control->setCurrentIndex(0);
    else if(!QString::compare(flow_control, "OFF"))
        ui->combo_flow_control->setCurrentIndex(1);
    else if(!QString::compare(flow_control, "HARDWARE"))
        ui->combo_flow_control->setCurrentIndex(2);
    else if(!QString::compare(flow_control, "XON/XOFF"))
        ui->combo_flow_control->setCurrentIndex(3);

    ui->combo_output_value->show();
    QString outputname = query.value(12).toString();
    if(!QString::compare(outputname, ""))
        ui->combo_output_value->setCurrentIndex(0);
    else if(!QString::compare(outputname, "DBT"))
        ui->combo_output_value->setCurrentIndex(1);
    else if(!QString::compare(outputname, "DPT"))
        ui->combo_output_value->setCurrentIndex(2);
    else if(!QString::compare(outputname, "FPD"))
        ui->combo_output_value->setCurrentIndex(3);
    else if(!QString::compare(outputname, "GGA"))
        ui->combo_output_value->setCurrentIndex(4);
    else if(!QString::compare(outputname, "GLL"))
        ui->combo_output_value->setCurrentIndex(5);
    else if(!QString::compare(outputname, "HDG"))
        ui->combo_output_value->setCurrentIndex(6);
    else if(!QString::compare(outputname, "HDT"))
        ui->combo_output_value->setCurrentIndex(7);
    else if(!QString::compare(outputname, "HSC"))
        ui->combo_output_value->setCurrentIndex(8);
    else if(!QString::compare(outputname, "MWD"))
        ui->combo_output_value->setCurrentIndex(9);
    else if(!QString::compare(outputname, "MWV"))
        ui->combo_output_value->setCurrentIndex(10);
    else if(!QString::compare(outputname, "SN"))
        ui->combo_output_value->setCurrentIndex(11);
    else if(!QString::compare(outputname, "TTM"))
        ui->combo_output_value->setCurrentIndex(12);
    else if(!QString::compare(outputname, "VBW"))
        ui->combo_output_value->setCurrentIndex(13);
    else if(!QString::compare(outputname, "VDM"))
        ui->combo_output_value->setCurrentIndex(14);
    else if(!QString::compare(outputname, "VDR"))
        ui->combo_output_value->setCurrentIndex(15);
    else if(!QString::compare(outputname, "VHW"))
        ui->combo_output_value->setCurrentIndex(16);
    else if(!QString::compare(outputname, "VTG"))
        ui->combo_output_value->setCurrentIndex(17);


    qDebug()<<"id channel"<<id_channel;
    qDebug()<<"nama sensor"<<nama_sensor;
    qDebug()<<"baudrate"<<baudrate;
    qDebug()<<"databits"<<databits;
    qDebug()<<"parity"<<parity;
    qDebug()<<"stopbits"<<stopbits;
    qDebug()<<"jenis sensor"<<jenis_sensor;
    qDebug()<<"priority"<<priority;
    qDebug()<<"flow control"<<flow_control;
    qDebug()<<"outputname"<<outputname;
}
