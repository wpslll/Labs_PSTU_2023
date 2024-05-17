#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    cheerfulness = 100;
    coffee = 5;
    money = 0;
    day = 0;
    products = {"хлеб", "масло", "вода", "мясо", "макароны"};
    ui->textBrowser_3->append(("Бодрость: " + QString::number(cheerfulness)));
    ui->textBrowser_4->append(("Деньги: " + QString::number(money)));
    ui->textBrowser_2->append(("День " + QString::number(day)));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_tired(QTextBrowser *display)
{
    cheerfulness -= 10;
    if (cheerfulness < 0)
    {
        display->append("Кассир устал и больше ничего не может делать");
        delete ui;
    }
    display->clear();
    display->append("Бодрость: " + QString::number(cheerfulness));
}
void MainWindow::end_the_day(QTextBrowser *display)
{
    cheerfulness +=50;
    coffee = 0;
    day += 1;
    ui->textBrowser_2->clear();
    ui->textBrowser_2->append("День: " + QString::number(day));
    day_in_progress = false;
    reset_user_order();
    ui->textBrowser->clear();
    display->append("День окончен");
}
void MainWindow::drink_coffee(QTextBrowser *display)
{
    if(coffee == 3)
    {
        return;
    }
    cheerfulness += 10;
    coffee++;
    display->clear();
    display->append("Бодрость: " + QString::number(cheerfulness));
}
void MainWindow::create_random_order(QTextBrowser *display)
{
    if (!day_in_progress)
    {
            display->append("Начните день, чтобы принимать заказы.");
            return;
    }
        current_order.clear();
        std::uniform_int_distribution<int> product_dist(0, products.size() - 1);
        std::uniform_int_distribution<int> quantity_dist(1, 10);

        int num_products = quantity_dist(rng);

        for (int i = 0; i < num_products; ++i)
        {
            int product_index = product_dist(rng);
            QString product = products[product_index];
            current_order.push_back(product);
            ui->textBrowser->append(product);
        }
}
void MainWindow::reset_user_order()
{
    user_order.clear();
}
void MainWindow::start_the_day()
{
    ui->textBrowser->clear();
    ui->textBrowser->append("Начат новый день");
    day_in_progress = true;
    create_random_order(ui->textBrowser);
    reset_user_order();
}
void MainWindow::print_check(QTextBrowser *display)
{
    if (current_order == user_order)
    {
       display->append("Заказ выполнен успешно!");
       ui->textBrowser->clear();
       money += 5;
       ui->textBrowser_4->clear();
       ui->textBrowser_4->append("Деньги: " + QString::number(money));
       reset_user_order();
       get_tired(ui->textBrowser_3);
       create_random_order(display);
    }
    else
    {
       display->append("Заказ не совпадает с заказом клиента. Создается новый заказ.");
       money -= 10;
       reset_user_order();
       get_tired(ui->textBrowser_3);
       create_random_order(display);
       reset_user_order();
       ui->textBrowser->clear();
    }
}
void MainWindow::ask_to_delete(QTextBrowser* display) {
    if (!user_order.empty()) {
        QString removed_product = user_order.back();
        user_order.pop_back();
        display->append("Удалено: " + removed_product);
    } else {
        display->append("Нет продуктов для удаления.");
    }
}
void MainWindow::on_add_bread_clicked()
{
    user_order.push_back("хлеб");
    ui->textBrowser->append("Добавлено: хлеб");
}
void MainWindow::on_add_meat_clicked()
{
    user_order.push_back("мясо");
    ui->textBrowser->append("Добавлено: мясо");
}
void MainWindow::on_add_oil_clicked()
{
    user_order.push_back("масло");
    ui->textBrowser->append("Добавлено: масло");
}
void MainWindow::on_add_pasta_clicked()
{
    user_order.push_back("макароны");
    ui->textBrowser->append("Добавлено: макароны");
}
void MainWindow::on_add_water_clicked()
{
    user_order.push_back("вода");
    ui->textBrowser->append("Добавлено: вода");
}
void MainWindow::on_ask_to_delete_clicked()
{
    ask_to_delete(ui->textBrowser);
}
void MainWindow::on_buy_coffee_clicked()
{
    if(money < 10)
    {
        ui->textBrowser->append("Не хватает денег на кофе");
        return;
    }
    drink_coffee(ui->textBrowser_3);
    money -= 10;
    ui->textBrowser_4->clear();
    ui->textBrowser_4->append("Деньги: " + QString::number(money));
}
void MainWindow::on_end_the_day_clicked()
{
    end_the_day(ui->textBrowser);
}
void MainWindow::on_print_a_check_clicked()
{
    print_check(ui->textBrowser);
}
void MainWindow::on_start_the_day_clicked()
{
    start_the_day();
}
