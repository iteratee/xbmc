/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "PVRBuiltins.h"

#include "Application.h"
#include "ServiceBroker.h"
#include "pvr/PVRGUIActions.h"
#include "pvr/PVRManager.h"

/*! \brief Search for missing channel icons
 *   \param params (ignored)
 */
static int SearchMissingIcons(const std::vector<std::string>& params)
{
  CServiceBroker::GetPVRManager().TriggerSearchMissingChannelIcons();
  return 0;
}

/*! \brief will toggle recording of playing channel, if any.
 *   \param params (ignored)
 */
static int ToggleRecordPlayingChannel(const std::vector<std::string>& params)
{
  CServiceBroker::GetPVRManager().GUIActions()->ToggleRecordingOnPlayingChannel();
  return 0;
}

// Note: For new Texts with comma add a "\" before!!! Is used for table text.
//
/// \page page_List_of_built_in_functions
/// \section built_in_functions_10 PVR built-in's
///
/// -----------------------------------------------------------------------------
///
/// \table_start
///   \table_h2_l{
///     Function,
///     Description }
///   \table_row2_l{
///     <b>`PVR.SearchMissingChannelIcons`</b>
///     ,
///     Will start a search for missing channel icons
///   }
///   \table_row2_l{
///     <b>`PVR.ToggleRecordPlayingChannel`</b>
///     ,
///     Will toggle recording on playing channel, if any
///   }
/// \table_end
///

CBuiltins::CommandMap CPVRBuiltins::GetOperations() const
{
  return {
           {"pvr.searchmissingchannelicons",  {"Search for missing channel icons", 0, SearchMissingIcons}},
           {"pvr.togglerecordplayingchannel", {"Toggle recording on playing channel", 0, ToggleRecordPlayingChannel}},
         };
}
