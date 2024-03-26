#include "home_1.h"
#include "ui_home_1.h"
#include <QFile>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMessage>
#include <QProcess>
#include <QDebug>
#include <QSqlQuery>

home_1::home_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::home_1)
{
    ui->setupUi(this);

    channelpush<<ui->channel1
               <<ui->channel2
              <<ui->channel3
             <<ui->channel4
            <<ui->channel5
           <<ui->channel6
          <<ui->channel7
         <<ui->channel8
        <<ui->channel9
       <<ui->channel10
      <<ui->channel11
     <<ui->channel12
    <<ui->channel13
   <<ui->channel14;

	QSqlQuery query;
    for(int baris=0;baris<14;baris++){
        channelpush.at(baris)->setStyleSheet("font:10pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
        query.exec();
        query.first();
        QString channelname = query.value(0).toString();
        channelpush.at(baris)->setText(QString("%2").arg(channelname));
        qDebug()<<"channelname"<<channelname;
    }

    sensorpush<<ui->sensor1
               <<ui->sensor2
              <<ui->sensor3
             <<ui->sensor4
            <<ui->sensor5
           <<ui->sensor6
          <<ui->sensor7
         <<ui->sensor8
        <<ui->sensor9
       <<ui->sensor10
      <<ui->sensor11
     <<ui->sensor12
    <<ui->sensor13
   <<ui->sensor14;

    for(int baris=0;baris<14;baris++){
        sensorpush.at(baris)->setStyleSheet("font:10pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
        query.exec();
        query.first();
        QString sensorname = query.value(1).toString();
        sensorpush.at(baris)->setText(QString("%2").arg(sensorname));
        qDebug()<<"channelname"<<sensorname;
    }

    valuepush<<ui->value1
               <<ui->value2
              <<ui->value3
             <<ui->value4
            <<ui->value5
           <<ui->value6
          <<ui->value7
         <<ui->value8
        <<ui->value9
       <<ui->value10
      <<ui->value11
     <<ui->value12
    <<ui->value13
   <<ui->value14;

    for(int baris=0;baris<14;baris++){
        valuepush.at(baris)->setStyleSheet("font:10pt ; color: rgb(255, 255, 255) ; border-color: rgb(255, 255, 255)");
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
        query.exec();
        query.first();
        QString valuename = query.value(3).toString();
        valuepush.at(baris)->setText(QString("%2").arg(valuename));
        qDebug()<<"channelname"<<valuename;
    }

    query.lastInsertId();

    updateTimer=new QTimer(this);
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateStatus()));
    updateTimer->start(250);

    /*tambahan miftah*/
    qDebug()<<"const";
    for(int i=0;i<24;i++)
        statusWarna[i] = true;
    for(int i=0;i<24;i++){
        connectStatus[i]=false;
    }
}

home_1::~home_1()
{
    delete ui;
}

void home_1::on_next_clicked()
{
    go_to_home_2();
}

void home_1::on_channel1_clicked()
{
    id_channel="1";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel2_clicked()
{
    id_channel="2";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel3_clicked()
{
    id_channel="3";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel4_clicked()
{
    id_channel="4";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel5_clicked()
{
    id_channel="5";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel6_clicked()
{
    id_channel="6";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel7_clicked()
{
    id_channel="7";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel8_clicked()
{
    id_channel="8";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel9_clicked()
{
    id_channel="9";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel10_clicked()
{
    id_channel="10";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel11_clicked()
{
    id_channel="11";
    goto_channel_output_string(id_channel);
    goto_channel_output();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel12_clicked()
{
    id_channel="12";
//    goto_channel_output_string(id_channel);
//    goto_channel_output();
    qDebug()<<"kirim id_channel syncro "<<id_channel;
}

void home_1::on_channel13_clicked()
{
    id_channel="13";
    goto_channel_output_special_string(id_channel);
    goto_channel_output_special();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_channel14_clicked()
{
    id_channel="14";
    goto_channel_output_special_string(id_channel);
    goto_channel_output_special();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor1_clicked()
{
    id_channel="1";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor2_clicked()
{
    id_channel="2";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor3_clicked()
{
    id_channel="3";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor4_clicked()
{
    id_channel="4";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor5_clicked()
{
    id_channel="5";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor6_clicked()
{
    id_channel="6";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor7_clicked()
{
    id_channel="7";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor8_clicked()
{
    id_channel="8";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor9_clicked()
{
    id_channel="9";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor10_clicked()
{
    id_channel="10";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor11_clicked()
{
    id_channel="11";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor12_clicked()
{
    id_channel="12";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel "<<id_channel;
}

void home_1::on_sensor13_clicked()
{
    id_channel="13";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel 13 "<<id_channel;
}

void home_1::on_sensor14_clicked()
{
    id_channel="14";
    goto_control_sensor_string(id_channel);
    goto_control_sensor();
    qDebug()<<"kirim id_channel 14 "<<id_channel;
}

void home_1::updateStatus()
{
    updateTimer->stop();
    for(int baris=0;baris<14;baris++){
        QSqlDatabase dataBase;
		QSqlQuery query;
        query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
        query.exec();
        query.first();
        QString eror_status = query.value(14).toString();
        if(eror_status.contains("NORMAL"))
        {
                query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
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

                    if(parsing_gyro.contains("-"))
                    {
                        valuepush.at(baris)->setText("H: - \n P: - \n R: -");
                        valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                    }
                    else
                    {
                       double heading = parsing_gyro.split(",").at(0).toDouble();
                       double pitch = parsing_gyro.split(",").at(1).toDouble();
                       double role = parsing_gyro.split(",").at(2).toDouble();
                       valuepush.at(baris)->setText(QString("H: %1 \n P: %2 \n R: %3").arg(heading).arg(pitch).arg(role));
                       valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                       qDebug()<<"masuk gyro if"<<channelname;
                    }

                }
                else{
                valuepush.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"ga masuk gyro if"<<channelname;
                valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                }
                //tambahan sampai sini

                channelpush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                QString sensorname = query.value(1).toString();
                sensorpush.at(baris)->setText(QString("%1").arg(sensorname));
                sensorpush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                QString id_sensor = query.value(0).toString();
                QString mode_sensor = query.value(2).toString();
                channelpush.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }
        else if(eror_status.contains("TIMEOUT") || eror_status.contains("ERROR"))
        {
                query.prepare(QString("SELECT * FROM ddu_ch where ch_id=%1;").arg(baris+1));
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

                    if(parsing_gyro.contains("-"))
                    {
                        valuepush.at(baris)->setText("H: - \n P: - \n R: -");
                        valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                    }
                    else
                    {
                       double heading = parsing_gyro.split(",").at(0).toDouble();
                       double pitch = parsing_gyro.split(",").at(1).toDouble();
                       double role = parsing_gyro.split(",").at(2).toDouble();
                       valuepush.at(baris)->setText(QString("H: %1 \n P: %2 \n R: %3").arg(heading).arg(pitch).arg(role));
                       valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                       qDebug()<<"masuk gyro if"<<channelname;
                    }

                }
                else{
                valuepush.at(baris)->setText(QString("%1").arg(channelname));
                qDebug()<<"ga masuk gyro if"<<channelname;
                valuepush.at(baris)->setStyleSheet("background-color:yellow ; font:10pt ; color: rgb(0, 0, 0)");
                }
                //tambahan sampai sini

                channelpush.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                QString sensorname = query.value(1).toString();
                sensorpush.at(baris)->setText(QString("%1").arg(sensorname));
                sensorpush.at(baris)->setStyleSheet("background-color:red ; font:10pt ; color: rgb(255, 255, 255)");
                QString id_sensor = query.value(0).toString();
                QString mode_sensor = query.value(2).toString();
                channelpush.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }
        else
        {
            sensorpush.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            sensorpush.at(baris)->setText("Not Connected");
            channelpush.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            valuepush.at(baris)->setStyleSheet("background-color:black ; font:10pt ; color: rgb(255, 255, 255)");
            valuepush.at(baris)->setText("0");
            QString id_sensor = query.value(0).toString();
            QString mode_sensor = query.value(2).toString();
            channelpush.at(baris)->setText(QString("%1 \n (%2)").arg(id_sensor).arg(mode_sensor));
        }

    }
    updateTimer->start(250);
}

void home_1::on_pushButton_2_clicked()
{
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
