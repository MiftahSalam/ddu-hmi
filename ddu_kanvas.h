#ifndef DDU_KANVAS_H
#define DDU_KANVAS_H

#include <QMainWindow>
#include "home_1.h"
#include "home_2.h"
#include "program_channel_input.h"
#include "program_channel_output.h"
#include "program_channel_output_special.h"
#include "control_sensor.h"
#include "program_channel_simulation.h"

namespace Ui {
class ddu_kanvas;
}

class ddu_kanvas : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ddu_kanvas(QWidget *parent = 0);
    QString id_channel;
    ~ddu_kanvas();
    
private:
    Ui::ddu_kanvas *ui;
    home_1 * home_satu;
    home_2 * home_dua;
    program_channel_input * channel_input_clicked;
    program_channel_output * channel_output_clicked;
    program_channel_output_special * channel_output_special_clicked;
    control_sensor * control_sensor_clicked;
    program_channel_simulation * channel_simulation_clicked;

private slots:
    void go_to_home_1_slot();
    void go_to_home_2_slot();
    void program_channel_input_slot();
    void program_channel_output_slot();
    void program_channel_output_special_slot();
    void program_channel_control_sensor_slot();
    void program_channel_simulation_slot();

};

#endif // DDU_KANVAS_H
