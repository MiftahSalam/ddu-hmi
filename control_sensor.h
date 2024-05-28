#ifndef CONTROL_SENSOR_H
#define CONTROL_SENSOR_H

#include <QWidget>

namespace Ui {
class control_sensor;
}

class control_sensor : public QWidget
{
    Q_OBJECT
    
public:
    explicit control_sensor(QWidget *parent = 0);
    ~control_sensor();
    
private slots:
    void on_pushButton_19_clicked();
    void setup_sensor_string(QString id_channel);

signals:
    void back_to_home(int page);

private:
    Ui::control_sensor *ui;

    QString chId;
};

#endif // CONTROL_SENSOR_H
