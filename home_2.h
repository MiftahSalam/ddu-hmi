#ifndef HOME_2_H
#define HOME_2_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class home_2;
}

class home_2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit home_2(QWidget *parent = 0);
    QString id_channel;
    ~home_2();
    
private slots:
    void on_back_clicked();
    void on_channel15_clicked();
    void on_channel16_clicked();
    void on_channel17_clicked();
    void on_channel18_clicked();
    void on_channel19_clicked();
    void on_channel20_clicked();
    void on_channel21_clicked();
    void on_channel22_clicked();
    void on_channel23_clicked();
    void on_channel24_clicked();
    void on_channel25_clicked();
    void on_channel26_clicked();
    void on_sensor15_clicked();
    void on_sensor16_clicked();
    void on_sensor17_clicked();
    void on_sensor18_clicked();
    void on_sensor19_clicked();
    void on_sensor20_clicked();
    void on_sensor21_clicked();
    void on_sensor22_clicked();
    void on_sensor23_clicked();
    void on_sensor24_clicked();
    void on_sensor25_clicked();
    void on_sensor26_clicked();

    void updateStatus();

    void on_pushButton_2_clicked();

signals:
    void go_to_home_1();
    void goto_channel_output_string(QString id_channel);
    void goto_channel_output();
    void goto_channel_input_string(QString id_channel);
    void goto_channel_input();
    void goto_control_sensor_string(QString id_channel);
    void goto_control_sensor();
    void goto_channel_simulation_string(QString id_channel);
    void goto_channel_simulation();

private:
    Ui::home_2 *ui;
    QList<QPushButton*> channelpush1, sensorpush1, valuepush1;

    QTimer *updateTimer;
    bool connectStatus[24];

    /*tambahan miftah*/
    bool statusWarna[24];
};

#endif // HOME_2_H
