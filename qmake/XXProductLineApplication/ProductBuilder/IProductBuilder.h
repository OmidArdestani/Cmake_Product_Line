#include <QMenuBar>
#include <QObject>
#include <sharedassets.h>

#pragma once

class IProductBuilder : public QObject{
    Q_OBJECT

public:
    IProductBuilder():QObject(nullptr){}

    virtual ~IProductBuilder() = default;

    virtual bool buildMenu(QMenuBar* menuBar) = 0;
    virtual bool registerFeatures(QMap<QString, IPLAsset*>& refMap) = 0;
    virtual bool decorate(QWidget* mainWidget) = 0;
};
