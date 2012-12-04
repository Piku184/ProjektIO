#ifndef DAY_H
#define DAY_H

#include <QDate>
#include "task.h"

class Day
{
  public:
    QDate *date;
    QList<Task> *taskList;
    Day( QDate dateClicked);
};

#endif // DAY_H
