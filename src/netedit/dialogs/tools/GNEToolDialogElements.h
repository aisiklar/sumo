/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2022 German Aerospace Center (DLR) and others.
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
/// @file    GNEToolDialog.h
/// @author  Pablo Alvarez Lopez
/// @date    Jun 2022
///
// Elements used in GNEToolDialog
/****************************************************************************/
#pragma once
#include <config.h>

#include <fx.h>
#include <string>
#include <vector>


// ===========================================================================
// class declaration
// ===========================================================================

class GNEToolDialog;

// ===========================================================================
// class definitions
// ===========================================================================

/// @brief elements used in Tool Dialogs
class GNEToolDialogElements {
    
public:
    /// @brief argument
    class Argument {

    public:
        /// @brief constructor
        Argument(GNEToolDialog *toolDialogParent, const std::string name, const std::string parameter_);

        /// @brief destructor
        virtual ~Argument();

        /// get argument (parameter and value)
        virtual std::string getArgument() const = 0;

    protected:
        /// pointer to toolDialog parent
        const GNEToolDialog *toolDialogParent; 

        /// @brief argument name
        const std::string argumentName;

        /// @brief parameter
        const std::string parameter;

    private:
        /// @brief default constructor
        Argument();

        /// @brief Invalidated copy constructor.
        Argument(const Argument&) = delete;

        /// @brief Invalidated assignment operator.
        Argument& operator=(const Argument&) = delete;
    };

    /// @brief filename
    class FileNameArgument : protected FXVerticalFrame, protected Argument {
    
    public:
        /// @brief constructor
        FileNameArgument(FXComposite *parent, GNEToolDialog *toolDialogParent, const std::string name, const std::string parameter);

        /// get argument (parameter and value)
        std::string getArgument() const;

    private:
        /// @brief Invalidated copy constructor.
        FileNameArgument(const FileNameArgument&) = delete;

        /// @brief Invalidated assignment operator.
        FileNameArgument& operator=(const FileNameArgument&) = delete;
    };
};