#ifndef PROGRAM_CHANNEL_OUTPUT_SPECIAL_H
#define PROGRAM_CHANNEL_OUTPUT_SPECIAL_H

#include <QWidget>
#include <QDebug>
#include <QFile>

namespace Ui {
class program_channel_output_special;
}

class program_channel_output_special : public QWidget
{
    Q_OBJECT
    
public:
    explicit program_channel_output_special(QWidget *parent = 0);
    QString id_channel_input;
    QString update_special_id;
    QString rmc_on, zda_on, gll_on, dbt_on, mwv_on, hdt_on, vbw_on, xdr_on, sta_on;
    QString protocol_rmc, protocol_zda, protocol_gll, protocol_dbt, protocol_mwv, protocol_hdt, protocol_vbw, protocol_xdr, protocol_sta;
    ~program_channel_output_special();
    
private:
    Ui::program_channel_output_special *ui;
    void create_database();

signals:
    void back_to_home(int page);

private slots:
    void on_pushButton_19_clicked();
    void setup_program_channel_output_special(QString id_channel);
    void on_pushButton_clicked();
};

#endif // PROGRAM_CHANNEL_OUTPUT_SPECIAL_H
