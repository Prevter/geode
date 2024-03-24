#pragma once

#include <Geode/ui/General.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/TextArea.hpp>
#include "list/ModItem.hpp"
#include "list/ModList.hpp"
#include "sources/ModListSource.hpp"

using namespace geode::prelude;

class ModsLayer : public CCLayer, public SetTextPopupDelegate {
protected:
    CCNode* m_frame;
    std::vector<CCMenuItemSpriteExtra*> m_tabs;
    ModListSource* m_currentSource = nullptr;
    std::unordered_map<ModListSource*, Ref<ModList>> m_lists;
    CCMenu* m_pageMenu;
    CCLabelBMFont* m_pageLabel;
    CCMenuItemSpriteExtra* m_goToPageBtn;
    CCMenuItemSpriteExtra* m_restartBtn;
    bool m_showSearch = false;
    bool m_bigView = false;

    bool init();

    void keyBackClicked() override;
    void setTextPopupClosed(SetTextPopup*, gd::string value) override;
    
    void onTab(CCObject* sender);
    void onBigView(CCObject*);
    void onSearch(CCObject*);
    void onGoToPage(CCObject*);
    void onBack(CCObject*);
    void onRefreshList(CCObject*);
    void onRestart(CCObject*);

    void updateState();

public:
    static ModsLayer* create();
    static ModsLayer* scene();

    void gotoTab(ModListSourceType type);
};