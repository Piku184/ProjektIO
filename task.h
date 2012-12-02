#ifndef TASK_H
#define TASK_H

#include <QDateTime>
#include <QTime>

class Task
{
    bool ifDone;
    QString name;
    QString description;
    QDateTime startTime;
    QDateTime endTime;
    bool neededReminder;
    QDateTime reminderTime;

public:
    Task(QString _name, QString _description, QDate *dayClicked, int startHour, int startMinute, int endHour, int endMinute, bool reminder);
};

#endif // TASK_H
