#include <QSqlQuery>
#include <QSqlError>

#include "program_channel_output.h"
#include "ui_program_channel_output.h"

program_channel_output::program_channel_output(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::program_channel_output)
{
    ui->setupUi(this);

    connect(ui->combo_assign,SIGNAL(activated(QString)),this, SLOT(chan_assign(QString)));
}

program_channel_output::~program_channel_output()
{
    delete ui;
}

void program_channel_output::chan_assign(QString indeksString)
{
    qDebug()<<"Channel Assign Berubah";
	QSqlQuery query;

    if(!QString::compare(indeksString, "-"))
    {
        qDebug()<<"Chanel Nama : -";
        ui->combo_assign_jenis->hide();
        ui->combo_assign_channel->hide();
    }
    else if(!QString::compare(indeksString, "Channel"))
    {
        query.clear();
        qDebug()<<"Channel Assign Channel";
        ui->combo_assign_jenis->hide();
        ui->combo_assign_jenis->setEnabled(false);
        ui->combo_assign_channel->show();
        ui->combo_assign_channel->setEnabled(true);
//        QString assign_channel = ui->combo_assign_channel->currentText();
//        qDebug()<<"assign jenis= "<<assign_channel;
//        query.prepare(QString("UPDATE ddu_ch SET cur_assign_channel='%1' where ch_id=%2;").arg(assign_channel).arg(id_channel));
//        query.exec();
//        qDebug()<<"Debug database assign channel"<<query.lastQuery();
    }
    else if(!QString::compare(indeksString, "Jenis"))
    {
        query.clear();
        qDebug()<<"Channel Assign Jenis";
        ui->combo_assign_channel->hide();
        ui->combo_assign_channel->setEnabled(false);
        ui->combo_assign_jenis->show();
        ui->combo_assign_jenis->setEnabled(true);
    }
}

void program_channel_output::on_pushButton_19_clicked()
{
    back_to_home_1();
    create_database();
}

void program_channel_output::create_database()
{
	QSqlQuery query;

    query.prepare(QString("UPDATE ddu_ch SET cur_restarted_stat='1' where ch_id=%1;").arg(id_channel_input));
    query.exec();
    qDebug()<<"debug restarted"<<query.lastQuery();

    query.clear();

    QString ambil_jenis = ui->combo_jenis_sensor->currentText();
    QString ambil_nama = ui->combo_nama_sensor->currentText();
    QString ambil_baudrate = ui->combo_baudrate->currentText();
    QString ambil_databit = ui->combo_databits->currentText();
    QString ambil_parity = ui->combo_parity->currentText();
    QString ambil_stopbit = ui->combo_stopbits->currentText();
    QString ambil_flow = ui->combo_flow_control->currentText();
    QString ambil_output_value = ui->combo_output_value->currentText();
    QString ambil_assign = ui->combo_assign->currentText();
    QString ambil_assign_jenis = ui->combo_assign_jenis->currentText();
    QString ambil_assign_channel = ui->combo_assign_channel->currentText();

    if(ambil_assign=="Jenis")
    {
        query.prepare(QString("UPDATE ddu_ch SET cur_jenis_sensor='%2', cur_sensor_name='%3', cur_ser_baud='%5', cur_ser_parity='%6', cur_ser_data_bits='%7', cur_ser_stop_bit='%8', cur_ser_flow='%9', cur_protokol='%13', cur_assign_channel='%14' where ch_id=%15;").arg(ambil_jenis).arg(ambil_nama).arg(ambil_baudrate).arg(ambil_parity).arg(ambil_databit).arg(ambil_stopbit).arg(ambil_flow).arg(ambil_output_value).arg(ambil_assign_jenis).arg(id_channel_input));
        query.exec();

        qDebug()<<"Update Combobox"<<query.lastQuery();
    }
    else if(ambil_assign=="Channel")
    {
        query.prepare(QString("UPDATE ddu_ch SET cur_jenis_sensor='%2', cur_sensor_name='%3', cur_ser_baud='%5', cur_ser_parity='%6', cur_ser_data_bits='%7', cur_ser_stop_bit='%8', cur_ser_flow='%9', cur_protokol='%13', cur_assign_channel='%14' where ch_id=%15;").arg(ambil_jenis).arg(ambil_nama).arg(ambil_baudrate).arg(ambil_parity).arg(ambil_databit).arg(ambil_stopbit).arg(ambil_flow).arg(ambil_output_value).arg(ambil_assign_channel).arg(id_channel_input));
        query.exec();

        qDebug()<<"Update Combobox"<<query.lastQuery();
    }
    else if(ambil_assign=="-")
    {
        query.prepare(QString("UPDATE ddu_ch SET cur_jenis_sensor='%2', cur_sensor_name='%3', cur_ser_baud='%5', cur_ser_parity='%6', cur_ser_data_bits='%7', cur_ser_stop_bit='%8', cur_ser_flow='%9', cur_protokol='%13', cur_assign_channel='%14' where ch_id=%15;").arg(ambil_jenis).arg(ambil_nama).arg(ambil_baudrate).arg(ambil_parity).arg(ambil_databit).arg(ambil_stopbit).arg(ambil_flow).arg(ambil_output_value).arg(ambil_assign_jenis).arg(id_channel_input));
        query.exec();

        qDebug()<<"Update Combobox"<<query.lastQuery();
    }
}

void program_channel_output::setup_program_channel_output(QString id_channel)
{
    qDebug()<<"masuk sinyal dari channel "<<id_channel;
	QSqlQuery query;

    query.prepare(QString("SELECT * FROM ddu_ch where ch_id = %1;").arg(id_channel));
    query.exec();
    query.seek(0);
    qDebug()<<query.lastQuery();

    id_channel_input=id_channel;

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
    else if(!QString::compare(nama_sensor, "RS232"))
        ui->combo_nama_sensor->setCurrentIndex(16);
    else if(!QString::compare(nama_sensor, "Speedlog 1"))
        ui->combo_nama_sensor->setCurrentIndex(17);
    else if(!QString::compare(nama_sensor, "Speedlog 2"))
        ui->combo_nama_sensor->setCurrentIndex(18);
    else if(!QString::compare(nama_sensor, "Speedlog 3"))
        ui->combo_nama_sensor->setCurrentIndex(19);
    else if(!QString::compare(nama_sensor, "Wind Direction 1"))
        ui->combo_nama_sensor->setCurrentIndex(20);
    else if(!QString::compare(nama_sensor, "Wind Direction 2"))
        ui->combo_nama_sensor->setCurrentIndex(21);
    else if(!QString::compare(nama_sensor, "Wind Direction 3"))
        ui->combo_nama_sensor->setCurrentIndex(22);

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

    QString assign_jenis = query.value(19).toString();
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

    QString assign_channel = query.value(19).toString();
    if(!QString::compare(assign_channel, ""))
        ui->combo_assign_channel->setCurrentIndex(0);
    else if(!QString::compare(assign_channel, "-"))
        ui->combo_assign_channel->setCurrentIndex(0);
    else if(!QString::compare(assign_channel, "1"))
        ui->combo_assign_channel->setCurrentIndex(1);
    else if(!QString::compare(assign_channel, "2"))
        ui->combo_assign_channel->setCurrentIndex(2);
    else if(!QString::compare(assign_channel, "3"))
        ui->combo_assign_channel->setCurrentIndex(3);
    else if(!QString::compare(assign_channel, "4"))
        ui->combo_assign_channel->setCurrentIndex(4);
    else if(!QString::compare(assign_channel, "5"))
        ui->combo_assign_channel->setCurrentIndex(5);
    else if(!QString::compare(assign_channel, "6"))
        ui->combo_assign_channel->setCurrentIndex(6);
    else if(!QString::compare(assign_channel, "7"))
        ui->combo_assign_channel->setCurrentIndex(7);
    else if(!QString::compare(assign_channel, "8"))
        ui->combo_assign_channel->setCurrentIndex(8);
    else if(!QString::compare(assign_channel, "9"))
        ui->combo_assign_channel->setCurrentIndex(9);
    else if(!QString::compare(assign_channel, "10"))
        ui->combo_assign_channel->setCurrentIndex(10);
    else if(!QString::compare(assign_channel, "11"))
        ui->combo_assign_channel->setCurrentIndex(11);
    else if(!QString::compare(assign_channel, "12"))
        ui->combo_assign_channel->setCurrentIndex(12);
    else if(!QString::compare(assign_channel, "13"))
        ui->combo_assign_channel->setCurrentIndex(13);
    else if(!QString::compare(assign_channel, "14"))
        ui->combo_assign_channel->setCurrentIndex(14);
    else if(!QString::compare(assign_channel, "15"))
        ui->combo_assign_channel->setCurrentIndex(15);
    else if(!QString::compare(assign_channel, "16"))
        ui->combo_assign_channel->setCurrentIndex(16);
    else if(!QString::compare(assign_channel, "17"))
        ui->combo_assign_channel->setCurrentIndex(17);
    else if(!QString::compare(assign_channel, "18"))
        ui->combo_assign_channel->setCurrentIndex(18);
    else if(!QString::compare(assign_channel, "19"))
        ui->combo_assign_channel->setCurrentIndex(19);
    else if(!QString::compare(assign_channel, "20"))
        ui->combo_assign_channel->setCurrentIndex(20);
    else if(!QString::compare(assign_channel, "21"))
        ui->combo_assign_channel->setCurrentIndex(21);
    else if(!QString::compare(assign_channel, "22"))
        ui->combo_assign_channel->setCurrentIndex(22);
    else if(!QString::compare(assign_channel, "23"))
        ui->combo_assign_channel->setCurrentIndex(23);
    else if(!QString::compare(assign_channel, "24"))
        ui->combo_assign_channel->setCurrentIndex(24);
    else if(!QString::compare(assign_channel, "25"))
        ui->combo_assign_channel->setCurrentIndex(25);
    else if(!QString::compare(assign_channel, "26"))
        ui->combo_assign_channel->setCurrentIndex(26);

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

    ui->combo_assign->show();
    QString assign = query.value(19).toString();
    if(!QString::compare(assign, "-"))
    {
        ui->combo_assign->setCurrentIndex(0);
        ui->combo_assign_channel->hide();
        ui->combo_assign_jenis->hide();
    }
    else if(!QString::compare(assign, ""))
    {
        ui->combo_assign->setCurrentIndex(0);
        ui->combo_assign_channel->hide();
        ui->combo_assign_jenis->hide();
    }
    else if(assign=="1" || assign=="2" || assign=="3" || assign=="4" || assign=="5" || assign=="6" || assign=="7" || assign=="8" || assign=="9" || assign=="10" || assign=="11" || assign=="12" || assign=="13" || assign=="14" || assign=="15" || assign=="16" || assign=="17" || assign=="18" || assign=="19" || assign=="20" || assign=="21" || assign=="22" || assign=="23" || assign=="24" || assign=="25" || assign=="26" )
    {
        ui->combo_assign->setCurrentIndex(1);
        ui->combo_assign_channel->show();
        ui->combo_assign_jenis->hide();
    }
    else if(assign=="AG" || assign=="AP" || assign=="CD" || assign=="CR" || assign=="CS" || assign=="CT" || assign=="CV" || assign=="CX" || assign=="DE" || assign=="DF" || assign=="EC" || assign=="EP" || assign=="ER" || assign=="GL" || assign=="GN" || assign=="GP" || assign=="HC" || assign=="HE" || assign=="HN" || assign=="II" || assign=="IN" || assign=="LA" || assign=="LC" || assign=="OM" || assign=="P" || assign=="RA"|| assign=="SD"|| assign=="SN"|| assign=="SS"|| assign=="TI"|| assign=="TR"|| assign=="VD"|| assign=="VM"|| assign=="VW"|| assign=="YX"|| assign=="ZA"|| assign=="ZC"|| assign=="ZQ"|| assign=="ZV"|| assign=="WI")
    {
        ui->combo_assign->setCurrentIndex(2);
        ui->combo_assign_channel->hide();
        ui->combo_assign_jenis->show();
    }

    qDebug()<<"id channel "<<id_channel;
    qDebug()<<"nama sensor"<<nama_sensor;
    qDebug()<<"ip sensor"<<baudrate;
    qDebug()<<"databits"<<databits;
    qDebug()<<"parity"<<parity;
    qDebug()<<"stopbits"<<stopbits;
    qDebug()<<"jenis sensor"<<jenis_sensor;
    qDebug()<<"flow control"<<flow_control;
    qDebug()<<"outputname"<<outputname;
    qDebug()<<"assign"<<assign;
    qDebug()<<"assign jenis"<<assign_jenis;
    qDebug()<<"assign channel"<<assign_channel;
}
