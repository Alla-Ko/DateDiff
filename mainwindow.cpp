
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDate dateF = QDate::currentDate();
    QDate dateL = QDate::currentDate();
    ui->dateFirst->setDate(dateF);
    ui->dateLast->setDate(dateL);
    ui->dateFirst->setCalendarPopup(true);
    ui->dateLast->setCalendarPopup(true);
    ui->dateFirst->setDateRange(QDate(1900, 01, 01), QDate(4000, 1, 1));
    ui->dateLast->setDateRange(QDate(1900, 01, 01), QDate(4000, 1, 1));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_dateFirst_userDateChanged(const QDate &date)
{
    QDate newdate=ui->dateFirst->date();
    if(newdate>ui->dateLast->date())ui->dateLast->setDate(newdate);
}


void MainWindow::on_dateLast_userDateChanged(const QDate &date)
{
    QDate newdate=ui->dateLast->date();
    if(newdate<ui->dateFirst->date())ui->dateFirst->setDate(newdate);

}


void MainWindow::on_Button_clicked()
{
    int days=ui->dateFirst->date().daysTo(ui->dateLast->date());
    ui->label->setText("Кількість днів між датами: "+QString::number(days));
}

