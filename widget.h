#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_createAccount_clicked();
    void on_login_clicked();
    void on_back_createAccount_clicked();
    void on_create_clicked();
    void on_back_GameMenu_clicked();
    void on_createGame_clicked();
    void on_joinGame_clicked();
    void on_resumeGame_clicked();
    void on_settings_clicked();

private:
    Ui::Widget *ui;

    enum Pages {
        LOGIN_PAGE,
        CREATE_ACCOUNT_PAGE,
        GAME_MENU_PAGE,
        GAME_WINDOW_PAGE
    };
};

#endif // WIDGET_H
