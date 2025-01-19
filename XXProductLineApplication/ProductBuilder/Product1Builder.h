#pragma once


#include "IProductBuilder.h"

#include <uniqueasset1.h>
#include <uniqueasset2.h>

class Product1Builder : public IProductBuilder{
    Q_OBJECT

public:
    explicit Product1Builder();

    // IProductBuilder interface
public:
    bool buildMenu(QMenuBar *menuBar) override;
    bool registerFeatures(QMap<QString, IPLAsset *> &refMap) override;
    bool decorate(QWidget *mainWidget) override;

private slots:
    void onProduct1MenuActionTriggered();

private:
    UniqueAsset1* asset1{nullptr};
    UniqueAsset2* asset2{nullptr};
};
