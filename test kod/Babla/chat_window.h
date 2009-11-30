#ifndef CHAT_WINDOW_H
#define CHAT_WINDOW_H

#include <QWidget>
#include <QObject>
#include "msg_window.h"
#include "msg_box.h"
#include "user_list_window.h"

class chat_window : public QWidget
{
    Q_OBJECT
public:
    chat_window(std::string);
    ~chat_window();

    std::string get_name() { return name_; }
    void new_message(std::string sender,std::string message);
    void add_contact(std::string user);
/*
protected:
    void contextMenuEvent(QContextMenuEvent *event);

public slots:
    void copy();
*/
public slots:
    void new_msg(std::string);
private:
    msg_window* msg_window_;
    msg_box* msg_box_;
    user_list_window* contact_list_;
    std::string name_;

    //QAction *copyAct;
};

#endif // CHAT_WINDOW_H
