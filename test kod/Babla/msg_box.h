#ifndef MSG_BOX_H
#define MSG_BOX_H

#include <QWidget>
#include <QTextEdit>
#include <QMessageBox>

class msg_box : public QWidget
{
    Q_OBJECT
public:
    msg_box(QWidget* parent);
    ~msg_box() { delete msg_box_; }
    void set_size(int x,int y,int w,int h);
private slots:
    void send_msg();
    void send_msg(std::string str);

private:
     QTextEdit *msg_box_;
};

#endif // MSG_BOX_H
