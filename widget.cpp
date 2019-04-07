#include "widget.h"
#include "ui_widget.h"
#include "openglwindow.h"
#include "clientprotocol.h"
#include <QTcpSocket>

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

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    OpenGLWindow window;
}


void Widget::on_pushButton_2_clicked()
{
    ClientProtocol::connectMainServer();
}
