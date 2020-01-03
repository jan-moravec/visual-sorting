#ifndef SORTINGCHART_H
#define SORTINGCHART_H

#include <QChart>
#include <vector>

QT_CHARTS_BEGIN_NAMESPACE

class SortingChart : public QChart
{
public:
    SortingChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = Qt::WindowFlags());

    void setValues(const std::vector<double> &values);

private:
    std::vector<double> values;
};

QT_CHARTS_END_NAMESPACE

#endif // SORTINGCHART_H
