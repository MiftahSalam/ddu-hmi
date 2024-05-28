#include "ddu_kanvas.h"
#include "ui_ddu_kanvas.h"
#include <QDesktopWidget>

ddu_kanvas::ddu_kanvas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ddu_kanvas)
{
    ui->setupUi(this);

    this->resize(QApplication::desktop()->width(),QApplication::desktop()->height());

    home_satu = new home_1(this);
    ui->verticalLayout_2->addWidget(home_satu);

    home_dua = new home_2(this);
    ui->verticalLayout_2->addWidget(home_dua);
    home_dua->hide();

    channel_input_clicked = new program_channel_input(this);
    ui->verticalLayout_2->addWidget(channel_input_clicked);
    channel_input_clicked->hide();

    channel_output_clicked = new program_channel_output(this);
    ui->verticalLayout_2->addWidget(channel_output_clicked);
    channel_output_clicked->hide();

    channel_output_special_clicked = new program_channel_output_special(this);
    ui->verticalLayout_2->addWidget(channel_output_special_clicked);
    channel_output_special_clicked->hide();

    control_sensor_clicked = new control_sensor(this);
    ui->verticalLayout_2->addWidget(control_sensor_clicked);
    control_sensor_clicked->hide();

    channel_simulation_clicked = new program_channel_simulation(this);
    ui->verticalLayout_2->addWidget(channel_simulation_clicked);
    channel_simulation_clicked->hide();

    connect(home_satu,SIGNAL(go_to_home_2()),SLOT(go_to_home_2_slot()));
    connect(home_dua,SIGNAL(go_to_home_1()),SLOT(go_to_home_1_slot()));

    connect(channel_input_clicked,SIGNAL(back_to_home(int)),SLOT(go_to_home_slot(int)));
    connect(channel_output_clicked,SIGNAL(back_to_home(int)),SLOT(go_to_home_slot(int)));
    connect(channel_output_special_clicked,SIGNAL(back_to_home(int)),SLOT(go_to_home_slot(int)));
    connect(control_sensor_clicked,SIGNAL(back_to_home(int)),SLOT(go_to_home_slot(int)));
    connect(channel_simulation_clicked,SIGNAL(back_to_home(int)),SLOT(go_to_home_slot(int)));

    connect(home_satu,SIGNAL(goto_channel_output()),SLOT(program_channel_output_slot()));
    connect(home_satu,SIGNAL(goto_channel_output_string(QString)),channel_output_clicked,SLOT(setup_program_channel_output(QString)));
    connect(home_satu,SIGNAL(goto_channel_output_special()),SLOT(program_channel_output_special_slot()));
    connect(home_satu,SIGNAL(goto_channel_output_special_string(QString)),channel_output_special_clicked,SLOT(setup_program_channel_output_special(QString)));
    connect(home_satu,SIGNAL(goto_control_sensor()),SLOT(program_channel_control_sensor_slot()));
    connect(home_satu,SIGNAL(goto_control_sensor_string(QString)),control_sensor_clicked,SLOT(setup_sensor_string(QString)));

    connect(home_dua,SIGNAL(goto_channel_output()),SLOT(program_channel_output_slot()));
    connect(home_dua,SIGNAL(goto_channel_output_string(QString)),channel_output_clicked,SLOT(setup_program_channel_output(QString)));
    connect(home_dua,SIGNAL(goto_channel_input()),SLOT(program_channel_input_slot()));
    connect(home_dua,SIGNAL(goto_channel_input_string(QString)),channel_input_clicked,SLOT(setup_program_channel_input(QString)));
    connect(home_dua,SIGNAL(goto_channel_simulation()),SLOT(program_channel_simulation_slot()));
    connect(home_dua,SIGNAL(goto_channel_simulation_string(QString)),channel_simulation_clicked,SLOT(setup_program_channel_simulation(QString)));
    connect(home_dua,SIGNAL(goto_control_sensor()),SLOT(program_channel_control_sensor_slot()));
    connect(home_dua,SIGNAL(goto_control_sensor_string(QString)),control_sensor_clicked,SLOT(setup_sensor_string(QString)));
}

ddu_kanvas::~ddu_kanvas()
{
    delete ui;
}

void ddu_kanvas::go_to_home_slot(int page)
{
    switch (page) {
    case 1:
        go_to_home_1_slot();
        break;
    case 2:
        go_to_home_2_slot();
        break;
    default:
        break;
    }
}

void ddu_kanvas::go_to_home_1_slot()
{
    home_satu->show();
    home_dua->close();
    channel_input_clicked->close();
    channel_output_clicked->close();
    channel_output_special_clicked->close();
    control_sensor_clicked->close();
    channel_simulation_clicked->close();
}

void ddu_kanvas::go_to_home_2_slot()
{
    home_satu->close();
    home_dua->show();
    channel_input_clicked->close();
    channel_output_clicked->close();
    channel_output_special_clicked->close();
    control_sensor_clicked->close();
    channel_simulation_clicked->close();
}

void ddu_kanvas::program_channel_output_slot()
{
    home_satu->close();
    home_dua->close();
    channel_input_clicked->close();
    channel_output_clicked->show();
    channel_output_special_clicked->close();
    control_sensor_clicked->close();
    channel_simulation_clicked->close();
}

void ddu_kanvas::program_channel_output_special_slot()
{
    home_satu->close();
    home_dua->close();
    channel_input_clicked->close();
    channel_output_clicked->close();
    channel_output_special_clicked->show();
    control_sensor_clicked->close();
    channel_simulation_clicked->close();
}

void ddu_kanvas::program_channel_input_slot()
{
    home_satu->close();
    home_dua->close();
    channel_input_clicked->show();
    channel_output_clicked->close();
    channel_output_special_clicked->close();
    control_sensor_clicked->close();
    channel_simulation_clicked->close();
}

void ddu_kanvas::program_channel_control_sensor_slot()
{
    home_satu->close();
    home_dua->close();
    channel_input_clicked->close();
    channel_output_clicked->close();
    channel_output_special_clicked->close();
    control_sensor_clicked->show();
    channel_simulation_clicked->close();
}

void ddu_kanvas::program_channel_simulation_slot()
{
    home_satu->close();
    home_dua->close();
    channel_input_clicked->close();
    channel_output_clicked->close();
    channel_output_special_clicked->close();
    control_sensor_clicked->hide();
    channel_simulation_clicked->show();
}
