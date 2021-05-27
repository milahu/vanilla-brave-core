// NOLINT(build/header_guard)
/* Copyright 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

// Multiply-included file, no traditional include guard.

#include "ipc/ipc_message_macros.h"

// The message starter should be declared in ipc/ipc_message_start.h. Since
// we don't want to patch Chromium, we just pretend to be something else.

#define IPC_MESSAGE_START TestMsgStart

// Tells the browser that content in the current page was blocked due to the
// user's content settings.
IPC_MESSAGE_ROUTED1(BraveViewHostMsg_JavaScriptBlocked,
                    std::u16string /* details on blocked content */)

IPC_MESSAGE_ROUTED1(BraveViewHostMsg_FingerprintingBlocked,
                    std::u16string /* details on blocked content */)