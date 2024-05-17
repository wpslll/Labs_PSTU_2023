#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void get_tired(QTextBrowser *display);
    void drink_coffee(QTextBrowser *display);
    void end_the_day(QTextBrowser *display);
    void print_check(QTextBrowser *display);
    void ask_to_delete(QTextBrowser *display);
    void create_random_order(QTextBrowser *display);
    void start_the_day();
private slots:
    void on_add_bread_clicked();
    void on_add_meat_clicked();
    void on_add_oil_clicked();
    void on_add_pasta_clicked();
    void on_add_water_clicked();
    void on_ask_to_delete_clicked();
    void on_buy_coffee_clicked();
    void on_end_the_day_clicked();
    void on_print_a_check_clicked();
    void reset_user_order();
    void on_start_the_day_clicked();

private:
    Ui::MainWindow *ui;
    int cheerfulness;
    int coffee;
    int money;
    int day;
    bool day_in_progress;
    QTextBrowser *display;
    std::mt19937 rng;
    std::vector<QString> products;
    std::vector<QString> current_order;
    std::vector<QString> user_order;

    void update_display();
};
#endif // MAINWINDOW_H
