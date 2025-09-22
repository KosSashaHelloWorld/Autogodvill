/*
 * This file is part of Your Project Name.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
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
