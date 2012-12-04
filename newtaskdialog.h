#ifndef NEWTASKDIALOG_H
#define NEWTASKDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QtGui>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QTimeEdit;
class QPushButton;
class QComboBox;
QT_END_NAMESPACE

class NewTaskDialog : public QDialog {



            Q_OBJECT

        public:
            NewTaskDialog(QWidget *parent = 0);

        private:
            QLabel *mainLabel;
            QLabel *taskTitleLabel;
            QLabel *taskDescriptionLabel;
            QLabel *startTimeLabel;
            QLabel *endTimeLabel;
            QLabel *timeSpanLabel;
            QLineEdit *titleEdit;
            QTextEdit *descriptionEdit;
            QCheckBox *reminderNeededCheckBox;
            QTimeEdit *startTime;
            QTimeEdit *endTime;

            QDialogButtonBox *buttonBox;
            QPushButton *saveButton;
            QPushButton *cancelButton;
        };


#endif // NEWTASKDIALOG_H
