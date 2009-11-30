#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QObject>

class settings_window : public QWidget
{
    Q_OBJECT

public:
    settings_window();
    ~settings_window();

public slots:
    void apply_slot();
    void cancel_slot();

private:
    void connections();

    QTextEdit *nick_;
    QTextEdit *port_;
    QTextEdit *server_;

    QLabel *nick_label_;
    QLabel *port_label_;
    QLabel *server_label_;

    QPushButton *apply_button_;
    QPushButton *cancel_button_;
};

#endif // SETTINGS_WINDOW_H
