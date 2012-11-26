#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QCalendarWidget;
class QCheckBox;
class QComboBox;
class QDate;
class QDateEdit;
class QGroupBox;
class QLabel;
class QGridLayout;


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void localeChanged(int index);
    void firstDayChanged(int index);
    void selectedDateChanged();
	void dayClicked();


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

    QGroupBox *dayViewGroupBox;
	QCheckBox *checkbox;

};

#endif
