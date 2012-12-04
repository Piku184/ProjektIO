#include "newtaskdialog.h"

NewTaskDialog::NewTaskDialog(QWidget *parent)
    : QDialog(parent)
{
    mainLabel = new QLabel(tr("Please fill in fields below before saving the task."));
    taskTitleLabel = new QLabel(tr("Task title: "));
    titleEdit = new QLineEdit;
    taskTitleLabel->setBuddy(titleEdit);
    taskDescriptionLabel = new QLabel(tr("Task description: "));
    descriptionEdit = new QTextEdit;
    taskDescriptionLabel->setBuddy(descriptionEdit);
    startTimeLabel = new QLabel(tr("Start time: "));
    startTime = new QTimeEdit;
    startTime->setDisplayFormat("HH:mm");
    startTimeLabel->setBuddy(startTime);
    endTimeLabel = new QLabel(tr("End time: "));
    endTime = new QTimeEdit;
    endTime->setDisplayFormat("HH:mm");
    endTimeLabel->setBuddy(endTime);
    reminderNeededCheckBox = new QCheckBox(tr("Set a reminder"));

    saveButton = new QPushButton(tr("Save"));
    cancelButton = new QPushButton(tr("Cancel"));
    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(saveButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);

    QGridLayout *topLayout = new QGridLayout;
    topLayout->addWidget(mainLabel);

    QGridLayout *leftLayout = new QGridLayout();
    leftLayout->addWidget(taskTitleLabel,0,0);
    leftLayout->addWidget(titleEdit,0,1);
    leftLayout->addWidget(startTimeLabel,1,0);
    leftLayout->addWidget(startTime,1,1);
    leftLayout->addWidget(endTimeLabel,2,0);
    leftLayout->addWidget(endTime,2,1);
    leftLayout->addWidget(reminderNeededCheckBox, 3, 0);

    QGridLayout *rightLayout = new QGridLayout;
    rightLayout->addWidget(taskDescriptionLabel);
    rightLayout->addWidget(descriptionEdit);

    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addLayout(topLayout, 0, 0, 1, 7);
    mainLayout->addLayout(leftLayout, 1, 0, 3, 3);
    mainLayout->addLayout(rightLayout, 1, 3, 3, 4);
    mainLayout->addWidget(buttonBox, 4, 0, 1, 7);

    setLayout(mainLayout);

    setWindowTitle(tr("Add new task"));
}


