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
    void on_pushButton_clicked();

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
