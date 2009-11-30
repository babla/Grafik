#ifndef MSG_WINDOW_H
#define MSG_WINDOW_H

#include <QtGui>
#include <QWidget>

class msg_window : public QWidget
{
public:
    msg_window(QWidget* parent);
    ~msg_window() { delete msg_window_; }
    void new_message(std::string sender , std::string message);
    void set_size(int x,int y,int w,int h);
private:
    QTextBrowser *msg_window_;
};

#endif // MSG_WINDOW_H
