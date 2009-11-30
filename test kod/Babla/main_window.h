#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>

#include "chat_window.h"
#include "settings_window.h"

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window();
    ~main_window();
    void new_message(std::string reciver, std::string sender, std::string messege);
    void add_contact(std::string channel,std::string user);

private slots:
    void remove_chat_window(int i);


private:
    void create_chat_window(std::string name);
    void remove_chat_window(std::string name);
    void create_menu();

    settings_window* settings_;
    QTabWidget *tab_bar;
    QVector<chat_window*> tabs;

    QMenu *fileMenu;
    QMenu *toolMenu;

    QAction *exitAct;
    QAction *optionsAct;
};

#endif // MAIN_WINDOW_H
