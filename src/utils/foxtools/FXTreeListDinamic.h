/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2004-2022 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    FXTreeListDinamic.h
/// @author  Pablo Alvarez Lopez
/// @date    Feb 2021
///
//
/****************************************************************************/

#pragma once
#include <config.h>

#include <vector>

#include "fxheader.h"


class FXTreeItemDynamic : public FXTreeItem {

public:
    /// @brief Constructor
    FXTreeItemDynamic(const FXString& text, FXIcon* oi = nullptr, FXIcon* ci = nullptr, void* ptr = nullptr);

protected:
    /// @brief draw tree item
    void draw(const FXTreeList* list, FXDC& dc, FXint xx, FXint yy, FXint, FXint hh) const;
};

/// @brief FXTreeListDinamic
class FXTreeListDinamic : protected FXTreeList {
    /// @brief FOX-declaration
    FXDECLARE(FXTreeListDinamic)

public:
    /// @brief Constructor
    FXTreeListDinamic(FXComposite* p, FXObject* tgt, FXSelector sel, FXuint opts);

    /// @brief Show FXTreeListDinamic
    void show();

    /// @brief Hide FXTreeListDinamic
    void hide();

    /// @brief clear items
    void clearItems();

    /// @brief get num items
    FXint getNumItems();

    /// @brief getSelected item index
    FXint getSelectedIndex();

    /// @brief Insert item with given text and icon
    FXTreeItem* insertItem(FXTreeItem* father, const FXString& text, FXIcon* oi);

    /// @brief get FXWindows associated with this FXTreeListDinamic
    FXWindow* getFXWindow();

    /// @brief Get item at x,y, if any
    FXTreeItem* getItemAt(FXint x,FXint y) const;

    /// @brief Get item 
    FXTreeItem* getItem(FXint index) const;

    /// @brief reset selected item
    void resetSelectedItem();

    /// @name FOX calls
    /// @{
    long onLeftBtnPress(FXObject*, FXSelector, void*);
    /// @}

protected:
    /// @brief default constructor
    FXTreeListDinamic();

    /// @brief list with current elements
    std::vector<FXTreeItem*> myFXTreeItems;

    /// @brief selected item
    FXint mySelectedItem = -1;
    
private:
    /// @brief Invalidated copy constructor.
    FXTreeListDinamic(const FXTreeListDinamic&) = delete;

    /// @brief Invalidated assignment operator.
    FXTreeListDinamic& operator=(const FXTreeListDinamic&) = delete;
};
