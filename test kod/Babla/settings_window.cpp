#include "settings_window.h"

settings_window::settings_window()
{
    nick_label_ = new QLabel(this);
    nick_ = new QTextEdit(this);
    nick_label_->setText(QString("Preferd nick"));
    nick_label_->setGeometry(10,10,100,20);
    nick_->setGeometry(10,30,100,25);

    port_label_ = new QLabel(this);
    port_ = new QTextEdit(this);
    port_label_->setText(QString("Port"));
    port_label_->setGeometry(10,80,30,20);
    port_->setGeometry(10,100,100,25);

    server_label_ = new QLabel(this);
    server_ = new QTextEdit(this);
    server_label_->setText(QString("Server adress or IP"));
    server_label_->setGeometry(10,150,200,20);
    server_->setGeometry(10,170,200,25);

    apply_button_ = new QPushButton(this);
    apply_button_->setText(QString("Apply"));
    apply_button_->setGeometry(350,200,70,25);

    cancel_button_ = new QPushButton(this);
    cancel_button_->setText(QString("Cancel"));
    cancel_button_->setGeometry(270,200,70,25);

    connections();

}
settings_window::~settings_window()
{
    delete nick_;
    delete port_;
    delete server_;

    delete nick_label_;
    delete port_label_;
    delete server_label_;

    delete apply_button_;
    delete cancel_button_;
}

void settings_window::connections()
{
    QWidget::connect(apply_button_, SIGNAL(clicked()), this, SLOT(apply_slot()));
    QWidget::connect(cancel_button_, SIGNAL(clicked()), this, SLOT(cancel_slot()));
}

void settings_window::apply_slot()
{
}

void settings_window::cancel_slot()
{
    this->hide();
}
