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
#ifndef GODPROFILE_H
#define GODPROFILE_H

#include "apistructures.h"
#include "apiworker.h"

class GodProfile
{
public:
    GodProfile();

    void update();

    APIProfile getAPIProfile();
    QString getHeroName();
    QString getGodName();
    QString getGender();
    int getLevel();
    int getMaximumHealth();
    int getMaximumInventorySlots();
    QString getProfileStatus();
    QString getClan();
    QString getClanPosition();
    QString getAligment();
    int getGoldenBricks();
    APIPet getPet();
    QString getPetName();
    QString getPetClass();
    int getPetLevel();
    QString getArkCompletedAt();
    int getArenaWon();
    int getArenaLost();
    int getCurrentHealth();
    int getQuestProgress();
    int getExperience();
    int getPrana();
    QString getGold();
    QString getLastDiary();
    QString getLastEye();
    QString getCity();
    int getDistance();
    bool getIsAtArena();
    int getCurrentInventorySlots();
    QString getQuest();
    std::vector<QString> getActivables();
    QString getPairsAt();
private:
    APIProfile prof;
    ApiWorker* aw;
};

#endif // GODPROFILE_H
