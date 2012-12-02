#include "day.h"

Day::Day(QObject *parent) :
    QObject(parent)
{
    Day::Day(QDate *dateClicked){
        date = dateClicked;
        taskList = new QWidgetList;
    }

}
