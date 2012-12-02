#include "day.h"

Day::Day(QDate dateClicked)
{
    this->date = &dateClicked;
    this->taskList = new QList<Task>;

}
