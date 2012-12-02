#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    createCalendarViewGroupBox();
    createOptionsGroupBox();
    createDayViewGroupBox();


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

void MainWindow::dayClicked()
{
	QListWidget *taskList = new QListWidget;
	QListWidgetItem *newItem1 = new QListWidgetItem;
    newItem1->setText("Zadanie 1");
    taskList->insertItem(1, newItem1);
	newItem1->setFlags(newItem1->flags()& Qt::ItemIsUserCheckable);
    newItem1->setCheckState(Qt::Unchecked);
    connect(taskList, SIGNAL(itemClicked ( QListWidgetItem * item )),
            this, SLOT(checkItem( newItem1)));
	
	QGridLayout *dayViewBoxLayout = new QGridLayout;
	
	dayViewBoxLayout->addWidget(taskList, 0, 0);
	dayViewGroupBox->setLayout(dayViewBoxLayout);
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
            this, SLOT(dayClicked()));

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
