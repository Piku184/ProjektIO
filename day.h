#ifndef DAY_H
#define DAY_H

#include <QObject>
#include <QWidget>
#include <QDate>
#include "task.h"

class Day : public QObject
{
    Q_OBJECT

    QDate date;
    QWidgetList taskList;


public:
    explicit Day(QObject *parent = 0);  
    Day(QDate *dateClicked);

signals:
    
public slots:
    
};

#endif // DAY_H
