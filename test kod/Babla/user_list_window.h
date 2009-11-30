#ifndef USER_LIST_WINDOW_H
#define USER_LIST_WINDOW_H

#include <QWidget>
#include <QObject>
#include <QListWidget>
#include <QAction>
#include <QMenu>
#include <QWidget>
#include <string>

class user_list_window : public QWidget
{
    Q_OBJECT
public:
    user_list_window(QWidget* parent);
    ~user_list_window() { delete user_list_; delete slapAct; }

    void set_size(int x,int y,int w,int h);
    void add_contact(std::string name);

public slots:
    void showContextMenuForWidget(const QPoint &pos);
    void slap();

signals:
    void slap_signal(std::string who);

private:
    QListWidget *user_list_;

    QAction *slapAct;
};

#endif // USER_LIST_WINDOW_H
