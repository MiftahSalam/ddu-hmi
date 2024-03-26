#ifndef HOME_1_H
#define HOME_1_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class home_1;
}

class home_1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit home_1(QWidget *parent = 0);
    QString id_channel;
    ~home_1();
    
private slots:
    void on_next_clicked();
    void on_channel1_clicked();
    void on_channel2_clicked();
    void on_channel3_clicked();
    void on_channel4_clicked();
    void on_channel5_clicked();
    void on_channel6_clicked();
    void on_channel7_clicked();
    void on_channel8_clicked();
    void on_channel9_clicked();
    void on_channel10_clicked();
    void on_channel11_clicked();
    void on_channel12_clicked();
    void on_channel13_clicked();
    void on_channel14_clicked();
    void on_sensor1_clicked();
    void on_sensor2_clicked();
    void on_sensor3_clicked();
    void on_sensor4_clicked();
    void on_sensor5_clicked();
    void on_sensor6_clicked();
    void on_sensor7_clicked();
    void on_sensor8_clicked();
    void on_sensor9_clicked();
    void on_sensor10_clicked();
    void on_sensor11_clicked();
    void on_sensor12_clicked();
    void on_sensor13_clicked();
    void on_sensor14_clicked();

    void updateStatus();

    void on_pushButton_2_clicked();

signals:
    void go_to_home_2();
    void goto_channel_output_string(QString id_channel);
    void goto_channel_output();
    void goto_channel_output_special_string(QString id_channel);
    void goto_channel_output_special();
    void goto_control_sensor_string(QString id_channel);
    void goto_control_sensor();


private:
    Ui::home_1 *ui;
    QList<QPushButton*> channelpush, sensorpush, valuepush;

    QTimer *updateTimer;
    bool connectStatus[24];

    /*tambahan miftah*/
    bool statusWarna[24];
};

#endif // HOME_1_H
