#include "control_sensor.h"
#include "ui_control_sensor.h"
#include <QFile>
#include <QSqlQuery>

control_sensor::control_sensor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::control_sensor)
{
    ui->setupUi(this);
}

control_sensor::~control_sensor()
{
    delete ui;    
}

void control_sensor::on_pushButton_19_clicked()
{
    back_to_home_1();
}

void control_sensor::setup_sensor_string(QString id_channel)
{
	QSqlQuery query;

	query.prepare(QString("SELECT * FROM ddu_ch where ch_id= %1;").arg(id_channel));
	query.exec();
	query.first();

	QString name = query.value(1).toString();
	QString portname = query.value(21).toString();
	QString baud = query.value(8).toString();
	QString dbits = query.value(10).toString();
	QString parity = query.value(15).toString();
	QString sbits = query.value(9).toString();
	QString ips = query.value(13).toString();
	QString ports = query.value(11).toString();
	QString err = query.value(14).toString();

	ui->label_channel->setText(QString("CHANNEL %1").arg(id_channel));
	ui->label_nama_sensor_value->setText(name);
	ui->label_databits_value->setText(dbits);
    ui->label_portname_value->setText(portname);
	ui->label_parity_value->setText(parity);
	ui->label_ip_value->setText(ips);
	ui->label_port_value->setText(ports);
	ui->label_detail_error_value->setText(err);
	ui->label_baudrate_value->setText(baud);
}
