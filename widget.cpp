#include "widget.h"
#include "ui_widget.h"
#include "openglwindow.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(Pages::LOGIN_PAGE);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_createAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::CREATE_ACCOUNT_PAGE);
}

void Widget::on_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::GAME_MENU_PAGE);
}

void Widget::on_back_createAccount_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::LOGIN_PAGE);
}

void Widget::on_create_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::LOGIN_PAGE);
}

void Widget::on_back_GameMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::LOGIN_PAGE);
}

void Widget::on_createGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(Pages::GAME_WINDOW_PAGE);
}

void Widget::on_joinGame_clicked()
{

}

void Widget::on_resumeGame_clicked()
{

}

void Widget::on_settings_clicked()
{

}
