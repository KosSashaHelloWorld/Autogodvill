#ifndef WIDGET_H
#define WIDGET_H

#include "godprofile.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

class Widget : public QWidget
{
    Q_OBJECT

    GodProfile* prof;

    QVBoxLayout* layoutMain;
    QPushButton* buttonRefresh;

    QVBoxLayout* layoutHealth;
    QVBoxLayout* layoutPrana;
    QHBoxLayout* layoutHealthPrana;
    QLabel* labelHealth;
    QProgressBar* barHealth;
    QLabel* labelPrana;
    QProgressBar* barPrana;

    QHBoxLayout* layoutInfo;
    QVBoxLayout* layoutLabels;
    QLabel* labelInfoFirst;
    QLabel* labelInfoSecond;
    QLabel* labelDiary;
    QLabel* labelEye;



    void FillHeroFirstLabel(QLabel* label);
    void FillHeroSecondLabel(QLabel* label);
    void FillDiaryLabel(QLabel* label);
    void FillEyeLabel(QLabel* label);
    void FillHealth(QLabel* label, QProgressBar* bar);
    void FillPrana(QLabel* label, QProgressBar* bar);

    void updateUI();

public:

    Widget(QWidget *parent = nullptr);

    ~Widget();

    void changeLanguage(QString languageCode);

public slots:

    void update();

};
#endif // WIDGET_H
