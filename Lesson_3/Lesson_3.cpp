#include "Lesson_3.h"
#include<QDir>
#include<QTextStream>
#include<QFileDialog>

static QString oldtext;

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
    txtEdit = std::make_unique<QTextEdit>();
    txtEdit->resize(300, 300);
    QString str = ":/Resource/info.txt";
    QFile file(str);
    if (file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
        QTextStream stream(&file);
        txtEdit->setText(stream.readAll());
        file.close();
    }
    txtEdit->setWindowTitle("Справка");
    txtEdit->setReadOnly(true);
    txtEdit->show();
    
}