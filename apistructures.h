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
