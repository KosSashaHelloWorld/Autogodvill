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
