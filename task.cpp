#include "task.h"


Task::Task(QString *_name, QString *_description, QDate *dayClicked, int startHour, int startMinute,
           int endHour, int endMinute, bool reminder)
{
    ifDone = 0;
    name = _name;
    description = _description;
    QTime *start = new QTime(startHour, startMinute);
    QTime *end = new QTime(endHour, endMinute);
    startTime = new QDateTime(*dayClicked, *start);
    endTime = new QDateTime(*dayClicked, *end);
    neededReminder = reminder;
}
