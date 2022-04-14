#include "Lesson_3.h"
#include<QDir>
#include<QTextStream>

Lesson_3::Lesson_3(QWidget* parent)
    : QWidget(parent),
    filter("Текстовый файл(*.txt);; Все(*.*)")
{
    ui.setupUi(this);
    
    QObject::connect(ui.saveButton, SIGNAL(clicked()), SLOT(onSaveButton()));
    QObject::connect(ui.openButton, SIGNAL(clicked()), SLOT(onOpenButton()));
    QObject::connect(ui.infoButton, SIGNAL(clicked()), SLOT(onInfoButton()));
}

void Lesson_3::onSaveButton()
{
    

    auto str = QFileDialog::getSaveFileName(this, "Выбор папки",
        QDir::currentPath(), filter);
    if (!str.isEmpty())
    {
        if (str.endsWith(".txt"))
        {
            QFile file(str);
            if (file.open(QFile::WriteOnly))
            {
                QTextStream stream(&file);
                stream << ui.plainTextEdit->toPlainText();
                file.close();
            }
        }
    }
}

void Lesson_3::onOpenButton()
{
    QString str = QFileDialog::getOpenFileName(this, "Выбор папки",
        QDir::currentPath(), filter);

    if (str.length() > 0)
    {
        if (!str.isEmpty())
        {
            QFile file(str);
            if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
            {
                QTextStream stream(&file);
                ui.plainTextEdit->setPlainText(stream.readAll());
                file.close();
            }
        }
    }
}

void Lesson_3::onInfoButton()
{
    QString str;
    QFile file(":/Resource/info.txt");
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
        str = file.readAll();
        file.close();
    }
    QMessageBox::information(nullptr, "Справка", str);
    
}