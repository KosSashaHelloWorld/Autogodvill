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
#include "godprofile.h"
#include <QDebug>

GodProfile::GodProfile()
{
    qDebug() << "GodProfile: Creating GodProfile...";
    aw = new ApiWorker();
    prof = aw->getProfile();
    qDebug() << "GodProfile: GodProfile created";
}

void GodProfile::update()
{
    qDebug() << "GodProfile: Updating profile...";
    prof = aw->getProfile();
    qDebug() << "GodProfile: Profile Updated";
}

APIProfile GodProfile::getAPIProfile()
{
    return prof;
}

QString GodProfile::getHeroName()
{
    return prof.name;
}

QString GodProfile::getGodName()
{
    return prof.godname;
}

QString GodProfile::getGender()
{
    return prof.gender;
}

int GodProfile::getLevel()
{
    return prof.level;
}

int GodProfile::getMaximumHealth()
{
    return prof.max_health;
}

int GodProfile::getMaximumInventorySlots()
{
    return prof.inventory_max_num;
}

QString GodProfile::getProfileStatus()
{
    return prof.motto;
}

QString GodProfile::getClan()
{
    return prof.clan;
}

QString GodProfile::getClanPosition()
{
    return prof.clan_position;
}

QString GodProfile::getAligment()
{
    return prof.alignment;
}

int GodProfile::getGoldenBricks()
{
    return prof.bricks_cnt;
}

APIPet GodProfile::getPet()
{
    return prof.pet;
}

QString GodProfile::getPetName()
{
    return prof.pet.pet_name;
}

QString GodProfile::getPetClass()
{
    return prof.pet.pet_class;
}

int GodProfile::getPetLevel()
{
    return prof.pet.pet_level;
}

QString GodProfile::getArkCompletedAt()
{
    return prof.ark_completed_at;
}

int GodProfile::getArenaWon()
{
    return prof.arena_won;
}

int GodProfile::getArenaLost()
{
    return prof.arena_lost;
}

int GodProfile::getCurrentHealth()
{
    return prof.health;
}

int GodProfile::getQuestProgress()
{
    return prof.quest_progress;
}

int GodProfile::getExperience()
{
    return prof.exp_progress;
}

int GodProfile::getPrana()
{
    return prof.godpower;
}

QString GodProfile::getGold()
{
    return prof.gold_approx;
}

QString GodProfile::getLastDiary()
{
    return prof.diary_last;
}

QString GodProfile::getLastEye()
{
    return prof.eye_last;
}

QString GodProfile::getCity()
{
    return prof.town_name;
}

int GodProfile::getDistance()
{
    return prof.distance;
}

bool GodProfile::getIsAtArena()
{
    return prof.arena_fight;
}

int GodProfile::getCurrentInventorySlots()
{
    return prof.inventory_num;
}

QString GodProfile::getQuest()
{
    return prof.quest;
}

std::vector<QString> GodProfile::getActivables()
{
    return prof.activatables;
}

QString GodProfile::getPairsAt()
{
    return prof.pairs_at;
}
