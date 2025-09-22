#include "widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QTranslator>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << "Widget: Creating widget...";


    prof = new GodProfile();


    layoutMain = new QVBoxLayout(this);


    // Health and prana bars with labels
    layoutHealth = new QVBoxLayout(this);
    layoutPrana = new QVBoxLayout(this);
    layoutHealthPrana = new QHBoxLayout(this);

    labelHealth = new QLabel(this);
    barHealth = new QProgressBar(this);
    layoutHealth->addWidget(labelHealth);
    layoutHealth->addWidget(barHealth);

    labelPrana = new QLabel(this);
    barPrana = new QProgressBar(this);
    layoutPrana->addWidget(labelPrana);
    layoutPrana->addWidget(barPrana);

    layoutHealthPrana->addLayout(layoutHealth);
    layoutHealthPrana->addLayout(layoutPrana);


    // Diary, eye and info labels
    layoutInfo = new QHBoxLayout(this);
    layoutLabels = new QVBoxLayout(this);

    labelInfoFirst = new QLabel(this);
    labelInfoSecond = new QLabel(this);
    labelDiary = new QLabel(this);
    labelEye = new QLabel(this);

    layoutInfo->addWidget(labelInfoFirst);
    layoutInfo->addWidget(labelInfoSecond);

    layoutLabels->addLayout(layoutInfo);
    layoutLabels->addWidget(labelDiary);
    layoutLabels->addWidget(labelEye);


    // Add refresh button
    buttonRefresh = new QPushButton(this);
    buttonRefresh->setText(tr("Refresh"));


    // Add all the layouts
    layoutMain->addLayout(layoutLabels);
    layoutMain->addLayout(layoutHealthPrana);
    layoutMain->addWidget(buttonRefresh);


    // Connect all the signals and slots
    connect(buttonRefresh, &QPushButton::clicked, this, &Widget::update);

    updateUI();

    qDebug() << "Widget: Widget created";
}

Widget::~Widget()
{
    qDebug() << "Widget: Widget destroyed";
}

void Widget::FillHeroFirstLabel(QLabel* label)
{
    QString str;
    str.append(prof->getGodName()).append("\n")
        .append(prof->getHeroName()).append("\n")
        .append(prof->getProfileStatus()).append("\n")
        .append(prof->getClan()).append("\n")
        .append(prof->getClanPosition());

    label->setText(str);
}

void Widget::FillHeroSecondLabel(QLabel* label)
{   
    QString str;
    str.append(prof->getAligment()).append("\n")
        .append(QString::number(prof->getArenaWon())).append(tr(" <- won | lost -> "))
        .append(QString::number(prof->getArenaLost())).append("\n")
        .append(prof->getCity().isEmpty() ? tr("Not in city now") : prof->getCity()).append("\n")
        .append(prof->getIsAtArena() ? tr("In battle at arena") : tr("Not at arena now")).append("\n")
        .append(prof->getGold()).append(tr(" <- gold | bricks -> "))
        .append(QString::number(prof->getGoldenBricks()));

    label->setText(str);
}

void Widget::FillDiaryLabel(QLabel* label)
{
    label->setText(prof->getLastDiary());
}

void Widget::FillEyeLabel(QLabel* label)
{
    label->setText(prof->getLastEye());
}

void Widget::FillHealth(QLabel* label, QProgressBar* bar)
{
    int cur = prof->getCurrentHealth();
    int max = prof->getMaximumHealth();

    bar->setMaximum(max);
    bar->setValue(cur);

    if (cur == 0)
    {
        // dead
        label->setText(tr("Dead"));
    }
    else if (cur * 8 < max)
    {
        // very low
        label->setText(tr("Very low health"));
    }
    else if (cur * 3 < max)
    {
        // low
        label->setText(tr("Low health"));
    }
    else if (cur * 1.5 < max)
    {
        // a lot of
        label->setText(tr("Health"));
    }
    else if (cur == max)
    {
        // max
        label->setText(tr("Ready to adventure"));
    }
    else
    {
        // close to max
        label->setText(tr("A lot of health"));
    }
}

void Widget::FillPrana(QLabel* label, QProgressBar* bar)
{
    int cur = prof->getPrana();

    if (prof->getGoldenBricks() == 1000)
    {
        bar->setMaximum(200);
    }
    else
    {
        bar->setMaximum(100);
    }

    bar->setValue(cur);

    if (cur == 100)
    {
        // max
        label->setText(tr("GOD'S POWER"));
    }
    else if (cur >= 75)
    {
        // high
        label->setText(tr("POWER"));
    }
    else if (cur >= 50)
    {
        // medium
        label->setText(tr("You are tired"));
    }
    else if (cur >= 25)
    {
        // low
        label->setText(tr("The last lightning"));
    }
    else if (cur > 0)
    {
        // very low
        label->setText(tr("The last word"));
    }
    else
    {
        // zero
        label->setText(tr("You are empty"));
    }
}

void Widget::updateUI()
{
    FillHeroFirstLabel(labelInfoFirst);
    FillHeroSecondLabel(labelInfoSecond);
    FillDiaryLabel(labelDiary);
    FillEyeLabel(labelEye);
    FillHealth(labelHealth, barHealth);
    FillPrana(labelPrana, barPrana);
}

void Widget::update()
{
    qDebug() << "Widget: Updating profile";
    prof->update();
    qDebug() << "Widget: Profile updated";
    qDebug() << "Widget: Updating UI...";
    updateUI();
    qDebug() << "Widget: UI updated";
}

void Widget::changeLanguage(QString languageCode)
{
    // QTranslator appTranslator;

    // if (appTranslator.load("your_project_" + languageCode, ":/translations"))
    // {
    //     qApp->removeTranslator(&currentTranslator);
    //     currentTranslator = appTranslator;
    //     qApp->installTranslator(&currentTranslator);

    //     // Retranslate UI
    //     ui->retranslateUi(this);
    // }
}
