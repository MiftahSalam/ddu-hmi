#ifndef PROGRAM_CHANNEL_SIMULATION_H
#define PROGRAM_CHANNEL_SIMULATION_H

#include <QWidget>
#include <QDebug>
#include <QFile>

namespace Ui {
class program_channel_simulation;
}

class program_channel_simulation : public QWidget
{
    Q_OBJECT
    
public:
    explicit program_channel_simulation(QWidget *parent = 0);
    QString id_channel_input;
    ~program_channel_simulation();
    
private:
    Ui::program_channel_simulation *ui;
    void create_database();

signals:
    void back_to_home_2();

private slots:
    void on_pushButton_19_clicked();
    void setup_program_channel_simulation(QString id_channel);
};

#endif // PROGRAM_CHANNEL_SIMULATION_H
