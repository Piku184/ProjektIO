
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDate>
#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
class QTextBrowser;
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void setMonth(int month);
    void setYear(int year);

private:
    void insertCalendar();

    int fontSize;
    QDate selectedDate;
    QTextBrowser *editor;
};

#endif
