#include "home_2.h"
#include "ui_home_2.h"
#include <QFile>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMessage>
#include <QProcess>
#include <QDebug>
#include <QSqlQuery>

home_2::home_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home_2)
{
    ui->setupUi(this);

	QSqlQuery query;

    channelpush1<<ui->channel15
               <<ui->channel16
              <<ui->channel17
             <<ui->channel18
            <<ui->channel19
           <<ui->channel20
          <<ui->channel21
         <<ui->channel22
        <<ui->channel23
       <<ui->channel24
      <<ui->channel25
     <<ui->channel26;

    for(int baris=0;baris<12;baris++){
        channelpush1.at(baris)->setStyleSheet("font:12pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
        qDebug()<<"debug last query"<<query.lastQuery();
        query.exec();
        query.first();
        QString channelname = query.value(0).toString();
        channelpush1.at(baris)->setText(QString("%2").arg(channelname));
        qDebug()<<"debug channel push"<<channelpush1.at(baris)->text();
        qDebug()<<"channelname home 2"<<channelname;
    }

    sensorpush1<<ui->sensor15
               <<ui->sensor16
              <<ui->sensor17
             <<ui->sensor18
            <<ui->sensor19
           <<ui->sensor20
          <<ui->sensor21
         <<ui->sensor22
        <<ui->sensor23
       <<ui->sensor24
      <<ui->sensor25
     <<ui->sensor26;

    for(int baris=0;baris<12;baris++){
        sensorpush1.at(baris)->setStyleSheet("font:12pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
        query.exec();
        query.first();
        QString sensorname = query.value(1).toString();
        sensorpush1.at(baris)->setText(QString("%2").arg(sensorname));
        qDebug()<<"sensorname home 2"<<sensorname;
    }

    valuepush1<<ui->value15
               <<ui->value16
              <<ui->value17
             <<ui->value18
            <<ui->value19
           <<ui->value20
          <<ui->value21
         <<ui->value22
        <<ui->value23
       <<ui->value24
      <<ui->value25
     <<ui->value26;

    for(int baris=0;baris<12;baris++){
        valuepush1.at(baris)->setStyleSheet("font:12pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
        query.exec();
        query.first();
        QString valuename = query.value(3).toString();
        valuepush1.at(baris)->setText(QString("%2").arg(valuename));
        qDebug()<<"valuename home 2"<<valuename;
    }

    updateTimer=new QTimer(this);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateStatus()));
    updateTimer->start(1250);

    /*tambahan miftah*/
    qDebug()<<"const";
    for(int i=0;i<24;i++)
        statusWarna[i] = true;
    for(int i=0;i<24;i++){
        connectStatus[i]=false;
    }
}

home_2::~home_2()
{
    delete ui;
}

void home_2::on_back_clicked()
{
    go_to_home_1();
}

void home_2::on_channel15_clicked()
{
    id_channel="15";
//    goto_channel_simulation_string(id_channel);
//    goto_channel_simulation();
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel16_clicked()
{
    id_channel="16";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel17_clicked()
{    
    id_channel="17";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel 17 "<<id_channel;
}

void home_2::on_channel18_clicked()
{
    id_channel="18";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel 18"<<id_channel;
}

void home_2::on_channel19_clicked()
{
    id_channel="19";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel20_clicked()
{
    id_channel="20";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel21_clicked()
{
    id_channel="21";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel22_clicked()
{
    id_channel="22";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel23_clicked()
{
    id_channel="23";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel24_clicked()
{
    id_channel="24";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel25_clicked()
{
    id_channel="25";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_channel26_clicked()
{
    id_channel="26";
    goto_channel_input_string(id_channel);
    goto_channel_input();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor15_clicked()
{
    id_channel="15";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor16_clicked()
{
    id_channel="16";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor17_clicked()
{
    id_channel="17";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor18_clicked()
{
    id_channel="18";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor19_clicked()
{
    id_channel="19";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor20_clicked()
{
    id_channel="20";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor21_clicked()
{
    id_channel="21";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor22_clicked()
{
    id_channel="22";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor23_clicked()
{
    id_channel="23";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor24_clicked()
{
    id_channel="24";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor25_clicked()
{
    id_channel="25";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::on_sensor26_clicked()
{
    id_channel="26";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_2::updateStatus()
{
    qDebug()<<"update timer home 2";
    updateTimer->stop();
    for(int baris=0;baris<12;baris++){
        QSqlDatabase dataBase;
        qDebug()<<"connect dong home 2";
        QSqlQuery query(dataBase);
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
        query.exec();
        query.first();
        QString eror_status = query.value(14).toString();
        qDebug()<<"eror status home 2 channel"<<baris+15<<" adalah "<<eror_status;
        if(eror_status.contains("NORMAL"))
        {
                query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
                query.exec();
                query.first();
                QString channelname = query.value(3).toString();
                channelname.replace("*", "'");

                /* murni yang dulu
                valuepush.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"valuename home 1"<<channelname;
                valuepush.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                */

                //*tambahan mulai dari sini
                QString nama_channel = query.value(1).toString();
                if(nama_channel.contains("Vertical")){
                    QString parsing_gyro = QString("%1").arg(channelname);

                    valuepush1.at(baris)->setText(parsing_gyro);
                    valuepush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                    /*
                    qDebug()<<"parsing_gyro"<<parsing_gyro;
                    if(parsing_gyro.size()==1)
                    {
                        valuepush1.at(baris)->setText("H: - \n P: - \n R: -");
                        valuepush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                    }
                    else
                    {
                       double heading = parsing_gyro.split(",").at(0).toDouble();
                       double pitch = parsing_gyro.split(",").at(1).toDouble();
                       double role = parsing_gyro.split(",").at(2).toDouble();
                       valuepush1.at(baris)->setText(QString("H: %1 \n P: %2 \n R: %3").arg(heading).arg(pitch).arg(role));
                       valuepush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                       qDebug()<<"masuk gyro if"<<channelname;
                    }
                    */

                }
                else{
                valuepush1.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"ga masuk gyro if"<<channelname;
                valuepush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                }
                //tambahan sampai sini

                channelpush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                QString sensorname = query.value(1).toString();
                sensorpush1.at(baris)->setText(QString("%1").arg(sensorname));
                sensorpush1.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                QString id_sensor = query.value(0).toString();
                QString mode_sensor = query.value(2).toString();
                channelpush1.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }
        else if(eror_status.contains("TIMEOUT") || eror_status.contains("ERROR"))
        {
                query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+15));
                query.exec();
                query.first();
                QString channelname = query.value(3).toString();
                channelname.replace("*", "'");

                /* murni yang dulu
                valuepush.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"valuename home 1"<<channelname;
                valuepush.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                */

                //*tambahan mulai dari sini
                QString nama_channel = query.value(1).toString();
                if(nama_channel.contains("Vertical")){
                    QString parsing_gyro = QString("%1").arg(channelname);

                    valuepush1.at(baris)->setText(parsing_gyro);
                    valuepush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(0, 0, 0)");
                    /*
                    if(parsing_gyro.size()==1)
                    {
                        valuepush1.at(baris)->setText("H: - \n P: - \n R: -");
                        valuepush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(0, 0, 0)");
                    }
                    else
                    {
                       double heading = parsing_gyro.split(",").at(0).toDouble();
                       double pitch = parsing_gyro.split(",").at(1).toDouble();
                       double role = parsing_gyro.split(",").at(2).toDouble();
                       valuepush1.at(baris)->setText(QString("H: %1 \n P: %2 \n R: %3").arg(heading).arg(pitch).arg(role));
                       valuepush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(0, 0, 0)");
                       qDebug()<<"masuk gyro if"<<channelname;
                    }
                    */
                }
                else{
                valuepush1.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"ga masuk gyro if"<<channelname;
                valuepush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(0, 0, 0)");
                }
                //tambahan sampai sini

                channelpush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                QString sensorname = query.value(1).toString();
                sensorpush1.at(baris)->setText(QString("%1").arg(sensorname));
                sensorpush1.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                QString id_sensor = query.value(0).toString();
                QString mode_sensor = query.value(2).toString();
                channelpush1.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }
        else
        {
            sensorpush1.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            sensorpush1.at(baris)->setText("Not Connected");
            channelpush1.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            valuepush1.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            valuepush1.at(baris)->setText("0");
            QString id_sensor = query.value(0).toString();
            QString mode_sensor = query.value(2).toString();
            channelpush1.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }

        qDebug()<<"update home 2 akhir";

    }
    updateTimer->start(1250);
}

void home_2::on_pushButton_2_clicked()
{
    system("sudo shutdown -P now");

    return;

    bool shutdown_works = false;
    bool gnome_power1 = false;
    bool gnome_power2 = false;
    bool hal_works = false;
    QDBusMessage response;
    bool verbose = false;

    QDBusInterface gnomeSessionManager("org.gnome.SessionManager",
                                       "/org/gnome/SessionManager", "org.gnome.SessionManager",
                                       QDBusConnection::sessionBus());
    response = gnomeSessionManager.call("RequestShutdown");
    if(response.type() == QDBusMessage::ErrorMessage){
        if(verbose)
            qWarning() << "W: " << response.errorName() << ":" << response.errorMessage();
        gnome_power1 = QProcess::startDetached("gnome-power-cmd.sh shutdown");
        gnome_power2 = QProcess::startDetached("gnome-power-cmd shutdown");
        if(verbose && !gnome_power1 && !gnome_power2)
            qWarning() << "W: gnome-power-cmd and gnome-power-cmd.sh didn't work";
    }
    else
        shutdown_works = true;

    QDBusInterface kdeSessionManager("org.kde.ksmserver", "/KSMServer",
                                     "org.kde.KSMServerInterface", QDBusConnection::sessionBus());
    response = kdeSessionManager.call("logout", 0, 2, 2);
    if(response.type() == QDBusMessage::ErrorMessage){
        if(verbose)
            qWarning() << "W: " << response.errorName() << ":" << response.errorMessage();
    }
    else
        shutdown_works = true;

    if(!shutdown_works && !gnome_power1 && !gnome_power2){
        QDBusInterface powermanagement("org.freedesktop.Hal",
                                       "/org/freedesktop/Hal/devices/computer",
                                       "org.freedesktop.Hal.Device.SystemPowerManagement",
                                       QDBusConnection::systemBus());
        response = powermanagement.call("Shutdown");
        if(response.type() == QDBusMessage::ErrorMessage){
            if(verbose)
                qWarning() << "W: " << response.errorName() << ":" << response.errorMessage();
        }
        else
            hal_works = true;
    }

    if(!hal_works && !shutdown_works && !gnome_power1 && !gnome_power2){
        QDBusInterface powermanagement("org.freedesktop.ConsoleKit",
                                       "/org/freedesktop/ConsoleKit/Manager", "org.freedesktop.ConsoleKit.Manager",
                                       QDBusConnection::systemBus());
        response = powermanagement.call("Stop");
        if(response.type() == QDBusMessage::ErrorMessage){
            if(verbose)
                qWarning() << "W: " << response.errorName() << ":" << response.errorMessage();
            QProcess::startDetached("sudo shutdown -P now");
        }
    }
}
