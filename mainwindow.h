#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "day.h"
#include "task.h"
#include <QList>

class QCalendarWidget;
class QCheckBox;
class QComboBox;
class QDate;
class QDateEdit;
class QGroupBox;
class QLabel;
class QGridLayout;
class QListWidget;
class QListWidgetItem;
class QButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void localeChanged(int index);
    void firstDayChanged(int index);
    void selectedDateChanged();
    void dayClicked(const QDate date);
    void checkItem(QListWidgetItem *newItem);
    void taskWindowPopup();


private:
    void createCalendarViewGroupBox();
    void createOptionsGroupBox();
    void createDayViewGroupBox();

    QGroupBox *calendarViewGroupBox;
    QGridLayout *calendarViewLayout;
    QCalendarWidget *calendar;

    QGroupBox *optionsGroupBox;
    QLabel *localeLabel;
    QLabel *firstDayLabel;
    QComboBox *localeCombo;
    QComboBox *firstDayCombo;
    QGroupBox *datesGroupBox;
    QLabel *currentDateLabel;
    QDateEdit *currentDateEdit;
    QLabel *informationLabel;
    QGroupBox *dayViewGroupBox;
	QCheckBox *checkbox;

    QGridLayout *dayViewBoxLayout;

    QList<Day> *daysList;
    int checkLayout;

};

#endif
