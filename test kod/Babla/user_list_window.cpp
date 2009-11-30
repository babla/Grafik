#include "user_list_window.h"

user_list_window::user_list_window(QWidget* parent)
{
    user_list_ = new QListWidget(parent);
    //user_list_->mousePressEvent(QMouseEvent(Qt::RightButton));
    user_list_->addItem(QString("+o Marcus"));
    user_list_->addItem(QString("+o Anders"));
    user_list_->addItem(QString("+o Barsk"));
    user_list_->addItem(QString("+o Niklas"));
    add_contact("+o Erik");

    /*/================================================================
   copyAct = new QAction(tr("&Copy"), this);
   copyAct->setShortcut(tr("Ctrl+C"));
   copyAct->setStatusTip(tr("TEST"));
   connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));
   //================================================================*/
   user_list_->setContextMenuPolicy(Qt::CustomContextMenu);
   connect(user_list_, SIGNAL(customContextMenuRequested(const QPoint &)),
         SLOT(showContextMenuForWidget(const QPoint &)));
}


void user_list_window::set_size(int x,int y,int w,int h)
{
    user_list_->setGeometry(x,y,w,h);
}

void user_list_window::add_contact(std::string name)
{
    user_list_->addItem(QString(name.c_str()));
}


void user_list_window::showContextMenuForWidget(const QPoint &pos)
{
    slapAct = new QAction(tr("&Slap"), user_list_);
    slapAct->setStatusTip(tr("Slap him across the face!"));
    connect(slapAct, SIGNAL(triggered()), this, SLOT(slap()));

    QMenu contextMenu(tr("Context menu"), user_list_);
    contextMenu.addAction(slapAct);
    contextMenu.statusTip();
    contextMenu.exec(mapFromGlobal(QCursor::pos()));
 }
 void user_list_window::slap()
{
    QString who = user_list_->currentItem()->text();
    emit slap_signal("?ACTION slaps " + who.toStdString() + " across the face!\n");
}
/*
void user_list_window::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    //menu.addAction(cutAct);
    menu.addAction(copyAct);
    //menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}

void user_list_window::copy()
{
}*/

