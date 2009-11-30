#include "main_window.h"

main_window::main_window()
{
   tab_bar = new QTabWidget(this);
   tab_bar->setGeometry(0,22,800,600);
   tab_bar->setTabsClosable(true);
   settings_ = new settings_window();
   create_chat_window("#Nr 1");
   create_chat_window("#Nr 2");
   create_chat_window("Nr 3");
   connect(tab_bar,SIGNAL(tabCloseRequested(int)),this,SLOT(remove_chat_window(int)));

   add_contact("#Nr 1","niklas");
   new_message("#Nr 1","niklas","yey det fungerar!\n");
   create_menu();
}

main_window::~main_window()
{
    delete settings_;
    delete tab_bar;

    delete fileMenu;
    delete toolMenu;

    delete exitAct;
    delete optionsAct;
}

void main_window::create_chat_window(std::string name)
{
        chat_window* temp = new chat_window(name);
        tabs.append(temp);
        tab_bar->addTab(tabs.at(tabs.size()-1),QString(name.c_str()));
}

void main_window::remove_chat_window(std::string name)
{
    for(int i = 0 ; i < tabs.size() ; i++)
       if(tabs.at(i)->get_name() == name)
        {
           tabs.remove(i);
           tab_bar->removeTab(i);
       }
}

void main_window::remove_chat_window(int i)
{
           tabs.remove(i);
           tab_bar->removeTab(i);
}

void main_window::new_message(std::string reciver, std::string sender, std::string message)
{
    for(int i=0 ; i < tabs.size() ; i++)
    {
        if(tabs.at(i)->get_name() == reciver)
        {
            tabs.at(i)->new_message(sender,message);
            return;
        }

    }
    create_chat_window(sender);
    tabs.at(tabs.size()-1)->new_message(sender, message);

}

void main_window::add_contact(std::string channel,std::string user)
{
    for(int i=0 ; i < tabs.size() ; i++)
        if(tabs.at(i)->get_name() == channel)
        {
            tabs.at(i)->add_contact(user);
            break;
        }
}

void main_window::create_menu()
{
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    fileMenu = menuBar()->addMenu(QString("&File"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);



    optionsAct = new QAction(tr("O&ptions"), this);
    optionsAct->setShortcut(tr("Ctrl+O"));
    optionsAct->setStatusTip(tr("Open options/settings"));
    connect(optionsAct, SIGNAL(triggered()), settings_, SLOT(show()));

    toolMenu = menuBar()->addMenu(QString("&Tools"));
    toolMenu->addSeparator();
    toolMenu->addAction(optionsAct);
}
