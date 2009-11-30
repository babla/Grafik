#ifndef PRIVATE_WINDOW_H
#define PRIVATE_WINDOW_H

#include <QWidget>

class private_window : public QWidget
{
    Q_OBJECT
public:
    private_window(std::string);
    std::string get_name() { return name_; }
    void new_message(std::string sender,std::string message);
private:
    msg_window* msg_window_;
    msg_box* msg_box_;
    std::string name_;
};

#endif // PRIVATE_WINDOW_H
