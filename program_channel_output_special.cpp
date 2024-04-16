#include <QSqlQuery>
#include <QSqlError>

#include "program_channel_output_special.h"
#include "ui_program_channel_output_special.h"

program_channel_output_special::program_channel_output_special(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::program_channel_output_special)
{
    ui->setupUi(this);

    ui->checkBox_dbt->setChecked(false);
    ui->checkBox_gll->setChecked(false);
    ui->checkBox_hdt->setChecked(false);
    ui->checkBox_mwv->setChecked(false);
    ui->checkBox_rmc->setChecked(false);
    ui->checkBox_status_sensor->setChecked(false);
    ui->checkBox_vbw->setChecked(false);
    ui->checkBox_xdr->setChecked(false);
    ui->checkBox_zda->setChecked(false);

}

program_channel_output_special::~program_channel_output_special()
{
    delete ui;
}

void program_channel_output_special::on_pushButton_19_clicked()
{
    back_to_home_1();
    create_database();
}

void program_channel_output_special::create_database()
{
	QSqlQuery query;

    query.prepare(QString("UPDATE ddu_ch SET cur_restarted_stat='1' where ch_id=%1;").arg(id_channel_input));
    query.exec();
    qDebug()<<"debug restarted"<<query.lastQuery();

    query.clear();

    QString ambil_baudrate = ui->combo_baudrate->currentText();
    QString ambil_databit = ui->combo_databits->currentText();
    QString ambil_parity = ui->combo_parity->currentText();
    QString ambil_stopbit = ui->combo_stopbits->currentText();
    QString ambil_flow = ui->combo_flow_control->currentText();
    QString ambil_frekuensi = ui->combo_frekuensi->currentText();

        query.prepare(QString("UPDATE ddu_ch SET cur_ser_baud='%5', cur_ser_parity='%6', cur_ser_data_bits='%7', cur_ser_stop_bit='%8', cur_ser_flow='%9', cur_freq_out='%13' where ch_id=%15;").arg(ambil_baudrate).arg(ambil_parity).arg(ambil_databit).arg(ambil_stopbit).arg(ambil_flow).arg(ambil_frekuensi).arg(id_channel_input));
        query.exec();
        qDebug()<<"last error update query"<<query.lastError();

        qDebug()<<"Update Combobox output special"<<query.lastQuery();

//        query.clear();
//        rmc_on, zda_on, gll_on, dbt_on, mwv_on, hdt_on, vbw_on, xdr_on, sta_on = '0';
//        *_rmc, *_zda, *_gll, *_dbt, *_mwv, *_hdt, *_vbw, *_xdr, *_sta;

        if(ui->checkBox_rmc->isChecked())
        {
            rmc_on = '1';
        }else rmc_on = '0';

        if(ui->checkBox_zda->isChecked())
        {
            zda_on = '1';
        }else zda_on = '0';

        if(ui->checkBox_gll->isChecked())
        {
            gll_on = '1';
        }else gll_on = '0';

        if(ui->checkBox_dbt->isChecked())
        {
            dbt_on = '1';
        }else dbt_on = '0';

        if(ui->checkBox_mwv->isChecked())
        {
            mwv_on = '1';
        }else mwv_on = '0';

        if(ui->checkBox_hdt->isChecked())
        {
            hdt_on = '1';
        }else hdt_on = '0';

        if(ui->checkBox_vbw->isChecked())
        {
            vbw_on = '1';
        }else vbw_on = '0';

        if(ui->checkBox_xdr->isChecked())
        {
            xdr_on = '1';
        }else xdr_on = '0';

        if(ui->checkBox_status_sensor->isChecked())
        {
            sta_on = '1';
        }else sta_on = '0';

        query.clear();

        qDebug()<<"RMC ="<<rmc_on<<"ZDA ="<<zda_on<<"GLL ="<<gll_on<<"DBT ="<<dbt_on;
        qDebug()<<"MWV ="<<mwv_on<<"hdt ="<<hdt_on<<"VBW ="<<vbw_on<<"XDR ="<<xdr_on<<"STA ="<<sta_on;

        if(id_channel_input=="13")
            update_special_id = "sent_status_1";
        else if(id_channel_input=="14")
            update_special_id = "sent_status_2";

        qDebug()<<"hasil konversi id = " <<update_special_id;

        query.prepare(QString("UPDATE appended_data SET %1 = CASE data_id "
                              "WHEN 1 THEN %2 "
                              "WHEN 2 THEN %3 "
                              "WHEN 3 THEN %4 "
                              "WHEN 4 THEN %5 "
                              "WHEN 5 THEN %6 "
                              "WHEN 6 THEN %7 "
                              "WHEN 7 THEN %8 "
                              "WHEN 8 THEN %9 "
                              "WHEN 9 THEN %10 "
                              "END ;").arg(update_special_id).arg(rmc_on).arg(zda_on).arg(gll_on).arg(dbt_on).arg(mwv_on).arg(hdt_on).arg(vbw_on).arg(xdr_on).arg(sta_on));
        query.exec();
        qDebug()<<"debug query update "<< query.lastQuery();
        qDebug()<<"debug query update "<< query.lastError();
}

void program_channel_output_special::setup_program_channel_output_special(QString id_channel)
{
    ui->checkBox_dbt->setChecked(false);
    ui->checkBox_gll->setChecked(false);
    ui->checkBox_hdt->setChecked(false);
    ui->checkBox_mwv->setChecked(false);
    ui->checkBox_rmc->setChecked(false);
    ui->checkBox_status_sensor->setChecked(false);
    ui->checkBox_vbw->setChecked(false);
    ui->checkBox_xdr->setChecked(false);
    ui->checkBox_zda->setChecked(false);

    qDebug()<<"masuk sinyal dari channel ke output special "<<id_channel;
	QSqlQuery query;

    query.prepare(QString("SELECT * FROM ddu_ch where ch_id = %1;").arg(id_channel));
    query.exec();
    query.seek(0);
    qDebug()<<"debug last query combo output "<<query.lastQuery();

    id_channel_input=id_channel;

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

    QString frekuensi = query.value(20).toString();
    if(!QString::compare(frekuensi, ""))
        ui->combo_frekuensi->setCurrentIndex(0);
    else if(!QString::compare(frekuensi, "1"))
        ui->combo_frekuensi->setCurrentIndex(1);
    else if(!QString::compare(frekuensi, "5"))
        ui->combo_frekuensi->setCurrentIndex(2);
    else if(!QString::compare(frekuensi, "10"))
        ui->combo_frekuensi->setCurrentIndex(3);
    else if(!QString::compare(frekuensi, "50"))
        ui->combo_frekuensi->setCurrentIndex(4);

    int nomer_output_special;

    if(id_channel=="13")
        nomer_output_special = 4;
    else if (id_channel=="14")
        nomer_output_special = 5;


    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '1';");
    query.exec();
    query.next();
    qDebug()<<" debug last query ambil output special"<< query.lastQuery();
    qDebug()<<" debug last query ambil output special"<< query.lastError();

    QString rmc_stat = query.value(nomer_output_special).toString();
    qDebug()<<"rmc stat "<< rmc_stat;
    if(rmc_stat=="1")
    {
        ui->checkBox_rmc->setChecked(true);
    }
    else
        ui->checkBox_rmc->setChecked(false);

    query.clear();


    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '2';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString zda_stat = query.value(nomer_output_special).toString();
    if(zda_stat=="1")
    {
        ui->checkBox_zda->setChecked(true);
    }
    else
        ui->checkBox_zda->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '3';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString gll_stat = query.value(nomer_output_special).toString();
    if(gll_stat=="1")
    {
        ui->checkBox_gll->setChecked(true);
    }
    else
        ui->checkBox_gll->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '4';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString dbt_stat = query.value(nomer_output_special).toString();
    if(dbt_stat=="1")
    {
        ui->checkBox_dbt->setChecked(true);
    }
    else
        ui->checkBox_dbt->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '5';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString mwv_stat = query.value(nomer_output_special).toString();
    if(mwv_stat=="1")
    {
        ui->checkBox_mwv->setChecked(true);
    }
    else
        ui->checkBox_mwv->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '6';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString hdt_stat = query.value(nomer_output_special).toString();
    if(hdt_stat=="1")
    {
        ui->checkBox_hdt->setChecked(true);
    }
    else
        ui->checkBox_hdt->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '7';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString vbw_stat = query.value(nomer_output_special).toString();
    if(vbw_stat=="1")
    {
        ui->checkBox_vbw->setChecked(true);
    }
    else
        ui->checkBox_vbw->setChecked(false);

    query.clear();

    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '8';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

    QString xdr_stat = query.value(nomer_output_special).toString();
    if(xdr_stat=="1")
    {
        ui->checkBox_xdr->setChecked(true);
    }
    else
        ui->checkBox_xdr->setChecked(false);

    query.clear();


    query.clear();
    query.prepare("SELECT * FROM appended_data where data_id = '9';");
    query.exec(); query.next();
    qDebug()<<query.lastQuery();

//    QString status_sensor_stat = query.value(nomer_output_special).toString();
    if(mwv_stat=="1")
    {
        ui->checkBox_status_sensor->setChecked(true);
    }
    else
        ui->checkBox_status_sensor->setChecked(false);

    query.clear();

//    qDebug()<<"id channel "<<id_channel;
//    qDebug()<<"databits"<<databits;
//    qDebug()<<"parity"<<parity;
//    qDebug()<<"stopbits"<<stopbits;
//    qDebug()<<"jenis sensor"<<frekuensi;
//    qDebug()<<"flow control"<<flow_control;
}


void program_channel_output_special::on_pushButton_clicked()
{
    qDebug()<<"Ke klik loh";
    ui->checkBox_dbt->setChecked(true);
    ui->checkBox_gll->setChecked(true);
    ui->checkBox_hdt->setChecked(true);
    ui->checkBox_mwv->setChecked(true);
    ui->checkBox_rmc->setChecked(true);
    ui->checkBox_status_sensor->setChecked(true);
    ui->checkBox_vbw->setChecked(true);
    ui->checkBox_xdr->setChecked(true);
    ui->checkBox_zda->setChecked(true);
}
