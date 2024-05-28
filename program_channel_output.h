#ifndef PROGRAM_CHANNEL_OUTPUT_H
#define PROGRAM_CHANNEL_OUTPUT_H

#include <QWidget>
#include <QDebug>
#include <QFile>

namespace Ui {
class program_channel_output;
}

class program_channel_output : public QWidget
{
    Q_OBJECT
    
public:
    explicit program_channel_output(QWidget *parent = 0);
    QString id_channel_input;
    ~program_channel_output();
    
private:
    Ui::program_channel_output *ui;
    void create_database();

signals:
    void back_to_home(int page);

private slots:
    void on_pushButton_19_clicked();
    void setup_program_channel_output(QString id_channel);
    void chan_assign(QString indeksString);
};

#endif // PROGRAM_CHANNEL_OUTPUT_H
