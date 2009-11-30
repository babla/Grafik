#include "msg_box.h"

msg_box::msg_box(QWidget* parent)
{
    msg_box_ = new QTextEdit(parent);
}

void msg_box::set_size(int x,int y,int w,int h)
{
    msg_box_->setGeometry(x,y,w,h);
}

void msg_box::send_msg()
{
    if(msg_box_->toPlainText() == QChar('\n'))
    {
        msg_box_->clear();
        return;
    }
    else if(!msg_box_->toPlainText().endsWith(QChar('\n')))
        return;
}

void msg_box::send_msg(std::string str)
{
    QMessageBox msgBox;
    msgBox.setText(QString(str.c_str()));
    msgBox.exec();
}
