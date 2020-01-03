#include "sortingchart.h"

#include <QBarSet>
#include <QBarSeries>

QT_CHARTS_BEGIN_NAMESPACE

SortingChart::SortingChart(QGraphicsItem *parent, Qt::WindowFlags wFlags): QChart(parent, wFlags)
{
    legend()->setVisible(false);
    //setAnimationOptions(QChart::AllAnimations);
    //chart->setAnimationOptions(QChart::NoAnimation);
}

void SortingChart::setValues(const std::vector<double> &values)
{
    removeAllSeries();
    this->values = values;

    QBarSet *barSet1 = new QBarSet("QBarSet");
    QBarSet *barSet2 = new QBarSet("QBarSet");

    //QPen pen(QColor(67,171,250), 10, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    //barSet1->setPen(pen);

    //barSet2->setPen(QPen(QColor(150,50,250), 2, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));

    /*for (double value: values) {
        barSet->append(value);
    }*/

    barSet1->append(1);
    barSet2->append(2);

    barSet1->setColor(Qt::red);

    QBarSeries *barSeries = new QBarSeries();
    barSeries->setUseOpenGL(true);
    barSeries->append(barSet1);
    barSeries->append(barSet2);

    barSeries->setBarWidth(10);

    addSeries(barSeries);
}

QT_CHARTS_END_NAMESPACE
