#pragma once

#include <Geode/ui/General.hpp>
#include <server/Server.hpp>
#include "../sources/ModSource.hpp"
#include "../UpdateModListState.hpp"

using namespace geode::prelude;

class ModItem : public CCNode {
protected:
    ModSource m_source;
    CCScale9Sprite* m_bg;
    CCNode* m_logo;
    CCNode* m_infoContainer;
    CCNode* m_titleContainer;
    CCLabelBMFont* m_titleLabel;
    CCLabelBMFont* m_versionLabel;
    CCNode* m_developers;
    CCLabelBMFont* m_developerLabel;
    ButtonSprite* m_restartRequiredLabel;
    CCMenu* m_viewMenu;
    CCMenuItemToggler* m_enableToggle = nullptr;
    CCMenuItemSpriteExtra* m_updateBtn = nullptr;
    EventListener<UpdateModListStateFilter> m_updateStateListener;
    EventListener<PromiseEventFilter<std::optional<server::ServerModUpdate>, server::ServerError>> m_checkUpdateListener;
    std::optional<server::ServerModUpdate> m_availableUpdate;

    /**
     * @warning Make sure `getMetadata` and `createModLogo` are callable 
     * before calling `init`!
    */
    bool init(ModSource&& source);

    void updateState();
    
    void onCheckUpdates(PromiseEvent<std::optional<server::ServerModUpdate>, server::ServerError>* event);

    void onEnable(CCObject*);
    void onView(CCObject*);
    void onInstall(CCObject*);

public:
    static ModItem* create(ModSource&& source);

    void updateSize(float width, bool big);
};