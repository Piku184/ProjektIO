#ifndef TASK_H
#define TASK_H

#include <QDateTime>
#include <QTime>

class Task
{
  public:
    bool ifDone;
    QString *name;
    QString *description;
    QDateTime *startTime;
    QTime *start;
    QDateTime *endTime;
    QTime *end;
    bool neededReminder;
    QDateTime *reminderTime;

    Task(QString *_name, QString *_description, QDate *dayClicked, int startHour, int startMinute, int endHour, int endMinute, bool reminder);
};

#endif // TASK_H
