

#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    selectedDate = QDate::currentDate();
    fontSize = 10;


    QWidget *centralWidget = new QWidget;


    QLabel *dateLabel = new QLabel(tr("Please pick a month and a year:"));
    QComboBox *monthCombo = new QComboBox;

    for (int month = 1; month <= 12; ++month)
        monthCombo->addItem(QDate::longMonthName(month));

    QComboBox *yearCombo = new QComboBox;

    for (int year = 2000; year <= 2030; ++year) {
        QString yearString = QString::number(year);
        yearCombo->addItem(yearString.toStdString().c_str());
    }


    monthCombo->setCurrentIndex(selectedDate.month() - 1);
    yearCombo->setCurrentIndex(selectedDate.year() -1);


    editor = new QTextBrowser;
    insertCalendar();


    connect(monthCombo, SIGNAL(activated(int)), this, SLOT(setMonth(int)));
    connect(yearCombo, SIGNAL(activated(int)), this, SLOT(setYear(int)));


    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(dateLabel);
    controlsLayout->addWidget(monthCombo);
    controlsLayout->addWidget(yearCombo);
    controlsLayout->addSpacing(24);
    controlsLayout->addStretch(1);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addLayout(controlsLayout);
    centralLayout->addWidget(editor, 1);
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);
}

void MainWindow::insertCalendar()
{
    editor->clear();
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();

    QDate date(selectedDate.year(), selectedDate.month(), 1);


    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setBackground(QColor("#e00f16"));
    tableFormat.setCellPadding(2);
    tableFormat.setCellSpacing(4);

    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 13)
                << QTextLength(QTextLength::PercentageLength, 9);
    tableFormat.setColumnWidthConstraints(constraints);


    QTextTable *table = cursor.insertTable(1, 8, tableFormat);


    QTextFrame *frame = cursor.currentFrame();
    QTextFrameFormat frameFormat = frame->frameFormat();
    frameFormat.setBorder(1);
    frame->setFrameFormat(frameFormat);


    QTextCharFormat format = cursor.charFormat();
    format.setFontPointSize(fontSize);

    QTextCharFormat boldFormat = format;
    boldFormat.setFontWeight(QFont::Bold);

    QTextCharFormat highlightedFormat = boldFormat;
    highlightedFormat.setBackground(Qt::white);


    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
        QTextTableCell cell = table->cellAt(0, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QString("%1").arg(QDate::longDayName(weekDay)),
                              boldFormat);
    }
    QTextTableCell cell = table->cellAt(0, 7);
    QTextCursor cellCursor = cell.firstCursorPosition();
    cellCursor.insertText(QString("Week"), boldFormat);

    table->insertRows(table->rows(), 1);


    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();


        if (date == QDate::currentDate())
            cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat);
        else
            cellCursor.insertText(QString("%1").arg(date.day()), format);

            QTextTableCell weekNoCell = table->cellAt(table->rows()-1, 7);
            QTextCursor weekNoCellCursor = weekNoCell.firstCursorPosition();
            weekNoCellCursor.insertText(QString("%1").arg(date.weekNumber()), format);



        date = date.addDays(1);
        if (weekDay == 7 && date.month() == selectedDate.month())
            table->insertRows(table->rows(), 1);
    }

    cursor.endEditBlock();

    setWindowTitle(tr("Daily Organiser, %1, %2"
        ).arg(QDate::longMonthName(selectedDate.month())
        ).arg(selectedDate.year()));
}


void MainWindow::setMonth(int month)
{
    selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
    insertCalendar();
}

void MainWindow::setYear(int year)
{
    selectedDate = QDate(year + 2000, selectedDate.month(), selectedDate.day());
    insertCalendar();
}

