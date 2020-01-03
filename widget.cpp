#include "widget.h"
#include "./ui_widget.h"

#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QBarSet>
#include <QBarSeries>
#include <QCategoryAxis>

#include <sortingchart.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->chartGraphicsView->setRenderHint(QPainter::HighQualityAntialiasing, true);
    ui->chartGraphicsView->setHidden(false);

    drawChart();
}

void Widget::drawChart()
{
    SortingChart *chart = new SortingChart();
    chart->setValues({1,2,3});

    /*chart->legend()->setVisible(false);
    chart->setAnimationOptions(QChart::AllAnimations);
    //chart->setAnimationOptions(QChart::NoAnimation);*/

    ui->chartGraphicsView->setChart(chart);

    /*QBarSet *barSet = new QBarSet("QBarSet");

    QPen pen(QColor(67,171,250), 2, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    barSet->setPen(pen);

    for (unsigned i = 0; i < 16; ++i) {
        barSet->append(i+1);
    }

    QBarSeries *barSeries = new QBarSeries();
    //barSeries->setUseOpenGL(true);
    barSeries->append(barSet);

    chart->addSeries(barSeries);*/

    /*QCategoryAxis *axisX = new QCategoryAxis();
    axisX->setLabelFormat("%d");
    axisX->setRange(0, bar_size - 1);
    axisX->setLabelsPosition(QCategoryAxis::AxisLabelsPositionOnValue);

    const double condensed_axis = histogram_size / static_cast<double>(axis_size);
    const unsigned condensed_bar = bar_size / axis_size;
    for (unsigned i = 0; i <= axis_size; ++i) {
        axisX->append(QString::number(static_cast<int>(i*condensed_axis + 0.5)), i*condensed_bar);
    }

    chart->addAxis(axisX, Qt::AlignBottom);
    barSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    barSeries->attachAxis(axisY);

    ui->chartGraphicsView->updateMargins(ui->slider->GetLowerValue() / (double)histogram_size * (bar_size - 1) + 0.5, ui->slider->GetUpperValue() / (double)histogram_size * (bar_size - 1) + 0.5);*/
}

Widget::~Widget()
{
    delete ui;
}

