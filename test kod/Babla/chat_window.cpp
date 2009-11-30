#include "chat_window.h"

chat_window::chat_window(std::string name)
{
    name_ = name;
    if(name.c_str()[0] == '#')
    {
        msg_window_ = new msg_window(this);
        msg_box_ = new msg_box(this);
        contact_list_ = new user_list_window(this);
        msg_window_->set_size(0,0,400,400);
        msg_box_->set_size(0,420,400,50);
        contact_list_->set_size(450,0,150,400);
        //Denna som ska användas sen!!!!!
        //connect(contact_list_,SIGNAL(slap_signal(std::string)),msg_box_,SLOT(send_msg(std::string)));
        connect(contact_list_,SIGNAL(slap_signal(std::string)),this,SLOT(new_msg(std::string)));
    }
    else
    {
        msg_window_ = new msg_window(this);
        msg_box_ = new msg_box(this);
        msg_window_->set_size(0,0,400,400);
        msg_box_->set_size(0,420,400,50);
    }

    msg_window_->new_message("Babla>> ","Välkommen till IRC-klienten Babla 0.1 Beta\n");
    msg_window_->new_message("Babla>> ","För hjälp skriv /help\n");

}

chat_window::~chat_window()
{
    delete msg_window_;
    delete msg_box_;
    delete contact_list_;
}

void chat_window::new_message(std::string sender,std::string message)
{
    msg_window_->new_message(sender,message);
}
void chat_window::new_msg(std::string str)
{
    msg_window_->new_message("You",str);
}

void chat_window::add_contact(std::string user)
{
    contact_list_->add_contact(user);
}

