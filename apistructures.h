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
#ifndef APISTRUCTURES_H
#define APISTRUCTURES_H
#include <QString>
#include <vector>

struct APIPet
{
    QString pet_name;
    QString pet_class;
    int         pet_level;
};

struct APIProfile
{
    QString     name;
    QString     godname;
    QString     gender;
    int         level;
    int         max_health;
    int         inventory_max_num;
    QString     motto;
    QString     clan;
    QString     clan_position;
    QString     alignment;
    int         bricks_cnt;
    APIPet      pet;
    QString     ark_completed_at;
    int         arena_won;
    int         arena_lost;
    int         health;
    int         quest_progress;
    int         exp_progress;
    int         godpower;
    QString     gold_approx;
    QString     diary_last;
    QString     eye_last;
    QString     town_name;
    int         distance;
    bool        arena_fight;
    int         inventory_num;
    QString     quest;
    std::vector<QString> activatables;
    QString     pairs_at;
};

/**
   {
    "name": "Принц Хаоса",
    "godname": "Тальзеур",
    "gender": "male",
    "level": 27,
    "max_health": 204,
    "inventory_max_num": 20,
    "motto": "Делай плохо!",
    "clan": "Евангелион",
    "clan_position": "адепт",
    "alignment": "агрессивный",
    "bricks_cnt": 164,
    "pet": {
        "pet_name": "Кузя «Суровый»",
        "pet_class": "скроллик",
        "pet_level": 8
    },
    "ark_completed_at": null,
    "arena_won": 0,
    "arena_lost": 1,
    "health": 129,
    "quest_progress": 68,
    "exp_progress": 96,
    "godpower": 5,
    "gold_approx": "около 2 тысяч",
    "diary_last": "✑ Был успешно зондирован.",
    "eye_last": "Навык «клинический удар» повышен до 11-го уровня! Тренинг обошёлся в 5969 золотых.",
    "town_name": "Еретиченск",
    "distance": 92,
    "arena_fight": false,
    "inventory_num": 13,
    "quest": "вдохнуть жизнь в звезду смерти",
    "activatables": [
        "случайный гриб",
        "мешок с трофеями",
        "ассасиновик"
    ],
    "pairs_at": null
}
*/

struct APIPublicProfile
{

};

#endif // APISTRUCTURES_H
