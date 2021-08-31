/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_CHROMIUM_SRC_COMPONENTS_UPDATE_CLIENT_PROTOCOL_SERIALIZER_H_
#define BRAVE_CHROMIUM_SRC_COMPONENTS_UPDATE_CLIENT_PROTOCOL_SERIALIZER_H_

#define BuildUpdateCheckExtraRequestHeaders           \
  BuildUpdateCheckExtraRequestHeaders_ChromiumImpl(); \
  base::flat_map<std::string, std::string> BuildUpdateCheckExtraRequestHeaders

#include "../../../../../components/update_client/protocol_serializer.h"
#undef BuildUpdateCheckExtraRequestHeaders

#endif  // BRAVE_CHROMIUM_SRC_COMPONENTS_UPDATE_CLIENT_PROTOCOL_SERIALIZER_H_
