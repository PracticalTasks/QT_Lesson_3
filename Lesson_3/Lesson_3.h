#pragma once

#include <QtWidgets>
#include "ui_Lesson_3.h"

class Lesson_3 : public QWidget
{
    Q_OBJECT

public:
    Lesson_3(QWidget *parent = Q_NULLPTR);

private:
    Ui::Lesson_3Class ui;
    QString filter;
    std::unique_ptr<QTextEdit> txtEdit;

private slots:
    void onSaveButton();
    void onOpenButton();
    void onInfoButton();

};
