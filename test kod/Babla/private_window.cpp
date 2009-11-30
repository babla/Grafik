#include "private_window.h"

private_window::private_window(std::string name)
{
    name_ = name;
    msg_window_ = new msg_window(this);
    msg_box_ = new msg_box(this);
    msg_window_->set_size(0,0,400,400);
    msg_box_->set_size(0,420,400,50);


    msg_window_->new_message("Babla>> ","Välkommen till IRC-klienten Babla 0.1 Beta\n");
    msg_window_->new_message("Babla>> ","För hjälp skriv /help\n");

}

void private_window::new_message(std::string sender,std::string message)
{
    msg_window_->new_message(sender,message);
}
