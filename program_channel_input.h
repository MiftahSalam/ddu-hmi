#ifndef PROGRAM_CHANNEL_INPUT_H
#define PROGRAM_CHANNEL_INPUT_H

#include <QWidget>
#include "qdebug.h"
#include <QFile>

namespace Ui {
class program_channel_input;
}

class program_channel_input : public QWidget
{
    Q_OBJECT
    
public:
    explicit program_channel_input(QWidget *parent = 0);
    QString id_channel_input;
    ~program_channel_input();
    
private:
    Ui::program_channel_input *ui;
    void create_database();

signals:
    void back_to_home_2();

private slots:
    void on_pushButton_19_clicked();
    void setup_program_channel_input(QString id_channel);

};

#endif // PROGRAM_CHANNEL_INPUT_H
