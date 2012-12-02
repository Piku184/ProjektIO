#ifndef DAY_H
#define DAY_H

#include <QDate>
#include "task.h"

class Day
{
    QDate *date;
    QList<Task> *taskList;
public:
    Day( QDate dateClicked);
};

#endif // DAY_H
