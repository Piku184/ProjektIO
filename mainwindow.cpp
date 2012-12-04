#include <QtGui>
#include <iostream>

#include "mainwindow.h"

#define MESSAGE \
    MainWindow::tr("<p>This shows only in order to check validity. ")

MainWindow::MainWindow()
{
    createCalendarViewGroupBox();
    createOptionsGroupBox();
    createDayViewGroupBox();
    checkLayout = 0;
    dayViewBoxLayout = new QGridLayout;

    daysList = new QList<Day>;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(calendarViewGroupBox, 0, 0);
    layout->addWidget(optionsGroupBox, 1, 0);
    layout->addWidget(dayViewGroupBox, 0, 1, 2, 2);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    calendarViewLayout->setRowMinimumHeight(0, calendar->sizeHint().height());
    calendarViewLayout->setColumnMinimumWidth(0, calendar->sizeHint().width());

    setWindowTitle(tr("Daily Organiser"));
}

void MainWindow::localeChanged(int index)
{
    calendar->setLocale(localeCombo->itemData(index).toLocale());
}

void MainWindow::firstDayChanged(int index)
{
    calendar->setFirstDayOfWeek(Qt::DayOfWeek(
                                firstDayCombo->itemData(index).toInt()));
}


void MainWindow::selectedDateChanged()
{
    currentDateEdit->setDate(calendar->selectedDate());
}

void MainWindow::checkItem(QListWidgetItem *newItem)
{
        if(newItem->QListWidgetItem::checkState() == Qt::Checked)
        newItem->setCheckState(Qt::Unchecked);
        if(newItem->QListWidgetItem::checkState() == Qt::Unchecked)
        newItem->setCheckState(Qt::Checked);
}

void MainWindow::dayClicked(const QDate date)
{
    int counter = 0;
    QListWidget *taskListWidget = new QListWidget;
    for( int i = 0; i < daysList->count(); i++) {

        if (&date == daysList->at(i).date) {
            for( int j = 0; daysList->at(i).taskList->count(); j++) {
                QString *appender = new QString;
                appender->append(daysList->at(i).taskList->at(j).name);
                appender->append(" ");
                appender->append(daysList->at(i).taskList->at(j).start->toString("HH:mm"));
                appender->append(" - ");
                appender->append(daysList->at(i).taskList->at(j).end->toString("HH:mm"));

                QListWidgetItem *newItem = new QListWidgetItem;
                newItem->setText(*appender);
                newItem->setFlags(Qt::ItemIsSelectable);
                newItem->setFlags(Qt::ItemIsUserCheckable);
                newItem->setCheckState(Qt::Unchecked);
                taskListWidget->insertItem(j+1, newItem);
            }
            connect(taskListWidget, SIGNAL(itemClicked(QListWidgetItem* item)), this, SLOT(taskWindowPopup()));
            break;
        } else {
            counter++;
        }
    }
    if(counter == daysList->count() || daysList->isEmpty()) {
        Day *newDay = new Day(date);
        daysList->append(*newDay);
        QListWidget *emptyList = new QListWidget;
        QListWidgetItem *noTasks = new QListWidgetItem;
        QString *noTasksForToday = new QString;
        noTasksForToday->append( tr("No tasks for %1").arg(date.toString()));
        noTasks->setText(*noTasksForToday);
        emptyList->insertItem(1, noTasks);
        QPushButton *newTaskButton = new QPushButton(tr("+ New Task"), this);

        if(!dayViewBoxLayout->isEmpty())
            dayViewBoxLayout->removeWidget(emptyList);

        dayViewBoxLayout->addWidget(emptyList, 0, 0);
        dayViewBoxLayout->addWidget(newTaskButton, 4, 0);

        if(checkLayout == 0) {
        dayViewGroupBox->setLayout(dayViewBoxLayout);
        checkLayout++;
        }

    }
}

void MainWindow::createCalendarViewGroupBox()
{
    calendarViewGroupBox = new QGroupBox(tr("Calendar"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(2012, 1, 1));
    calendar->setMaximumDate(QDate(2016, 1, 1));
    calendar->setGridVisible(false);

    calendarViewLayout = new QGridLayout;
    calendarViewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    calendarViewGroupBox->setLayout(calendarViewLayout);
}

void MainWindow::createDayViewGroupBox() {

    dayViewGroupBox = new QGroupBox(tr("Day View"));

	connect(calendar, SIGNAL(clicked(const QDate&)),
            this, SLOT(dayClicked(const QDate&)));

}


void MainWindow::createOptionsGroupBox()
{
    optionsGroupBox = new QGroupBox(tr("Options"));

    localeCombo = new QComboBox;
    QLocale::Language polish = QLocale::Polish;
    QString plLabel = QLocale::languageToString(polish);
    QLocale::Language english = QLocale::English;
    QString enLabel = QLocale::languageToString(english);

    localeCombo->addItem(plLabel, polish);
    localeCombo->addItem(enLabel, english);

    localeLabel = new QLabel(tr("Language"));
    localeLabel->setBuddy(localeCombo);

    firstDayCombo = new QComboBox;
    firstDayCombo->addItem(tr("Sunday"), Qt::Sunday);
    firstDayCombo->addItem(tr("Monday"), Qt::Monday);


    firstDayLabel = new QLabel(tr("Week starts on:"));
    firstDayLabel->setBuddy(firstDayCombo);

    connect(localeCombo, SIGNAL(currentIndexChanged(int)),
            this, SLOT(localeChanged(int)));
    connect(firstDayCombo, SIGNAL(currentIndexChanged(int)),
            this, SLOT(firstDayChanged(int)));


    QGridLayout *outerLayout = new QGridLayout;
    outerLayout->addWidget(localeLabel, 0, 0);
    outerLayout->addWidget(localeCombo, 0, 1);
    outerLayout->addWidget(firstDayLabel, 1, 0);
    outerLayout->addWidget(firstDayCombo, 1, 1);

    optionsGroupBox->setLayout(outerLayout);

    firstDayChanged(firstDayCombo->currentIndex());
}

void MainWindow::taskWindowPopup() {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, tr("QMessageBox::information()"), MESSAGE);
        if (reply == QMessageBox::Ok)
            informationLabel->setText(tr("OK"));
        else
            informationLabel->setText(tr("Escape"));
}
