/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/browser/brave_ads/ads_tooltips_delegate_impl.h"

#include <string>

#include "brave/components/brave_adaptive_captcha/buildflags/buildflags.h"
#include "chrome/browser/profiles/profile.h"

#if BUILDFLAG(BRAVE_ADAPTIVE_CAPTCHA_ENABLED)
#include "brave/browser/brave_adaptive_captcha/brave_adaptive_captcha_service_factory.h"
#endif

namespace brave_ads {

AdsTooltipsDelegateImpl::AdsTooltipsDelegateImpl(Profile* profile)
    : ads_tooltips_controller_(
#if BUILDFLAG(BRAVE_ADAPTIVE_CAPTCHA_ENABLED)
          brave_adaptive_captcha::BraveAdaptiveCaptchaServiceFactory::
              GetForProfile(profile),
#endif
          profile) {
}

#if BUILDFLAG(BRAVE_ADAPTIVE_CAPTCHA_ENABLED)
void AdsTooltipsDelegateImpl::ShowCaptchaTooltip(const std::string& payment_id,
                                                 const std::string& captcha_id,
                                                 bool enable_cancel_button) {
  ads_tooltips_controller_.ShowCaptchaTooltip(payment_id, captcha_id,
                                              enable_cancel_button);
}

void AdsTooltipsDelegateImpl::CloseCaptchaTooltip() {
  ads_tooltips_controller_.CloseCaptchaTooltip();
}
#endif

}  // namespace brave_ads
