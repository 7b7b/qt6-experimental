//===========================================
//  Lumina Desktop Source Code
//  Copyright (c) 2016, Ken Moore
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _LUMINA_CONFIG_PAGE_MAIN_H
#define _LUMINA_CONFIG_PAGE_MAIN_H
#include "../globals.h"
#include "PageWidget.h"

namespace Ui {
class page_main;
};

class page_main : public PageWidget {
    Q_OBJECT
public:
    explicit page_main(QWidget *parent);
    ~page_main();

    virtual void setPreviousPage(QString id) override;
    void clearlineEdit();

public slots:
    void SaveSettings() override;
    void LoadSettings(int screennum = -1) override;
    void updateIcons() override;

private:
    Ui::page_main *ui;
    QList<PAGEINFO> INFO;
    QShortcut *findShort;
    void UpdateItems(QString search);

private slots:
    void showFind();
    void itemTriggered(QTreeWidgetItem*, int);
    void searchChanged(QString);
};
#endif
