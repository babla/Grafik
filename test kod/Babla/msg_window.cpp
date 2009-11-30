#include "msg_window.h"

msg_window::msg_window(QWidget* parent)
{
    msg_window_ = new QTextBrowser(parent);
}

void msg_window::set_size(int x,int y,int w,int h)
{
    msg_window_->setGeometry(x,y,w,h);
}

void msg_window::new_message(std::string sender , std::string message)
{
    QString msg = QString(message.c_str());
    /*
    int typ =0;
    switch ( typ )
    {
        case 0: //Privat meddelande
            {
                msg_window_->setTextColor(QColor(QString("gray")));
                msg = QString(sender.c_str()) + QString(" says: ") + QString(message.c_str());
                break;
            }
        case 1: //Privat meddelande
            {
                msg_window_->setTextColor(QColor(QString("magenta")));
                msg = QString(sender.c_str()) + QString(" says: ") + QString(message.c_str());
                break;
            }
        case 2: //Yell, skir ut ett meddelande
            {
                msg_window_->setTextColor(QColor(QString("red")));
                msg = QString(sender.c_str()) + QString(" Yell's: ") + QString(message.c_str());
                break;
            }
        case 3: //Moderator
            {
                msg_window_->setTextColor(QColor(QString("blue")));
                msg = QString(sender.c_str()) + QString(" says: ") + QString(message.c_str());
                break;
            }
        default: //Standard text
            {
                msg = QString(sender.c_str()) + QString(" says: ") + QString(message.c_str());
                msg_window_->setTextColor(QColor(QString("black")));
            }
        }*/
    if(msg.startsWith(QString("?ACTION slaps")))
    {
        msg_window_->setTextColor(QColor(QString("magenta")));
        msg = msg.remove(QString("?ACTION"));
        msg = QString(sender.c_str()) + msg;
    }
    else
    {
        msg_window_->setTextColor(QColor(QString("gray")));
        msg = QString(sender.c_str()) + QString(" says: ") + QString(message.c_str());
    }
    msg_window_->insertPlainText(msg);
}
