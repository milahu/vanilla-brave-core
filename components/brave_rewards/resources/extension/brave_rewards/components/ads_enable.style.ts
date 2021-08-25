/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

import styled from 'styled-components'

import modalBackground from '../../../shared/components/onboarding/assets/opt_in_modal_bg.svg'

export const root = styled.div`
   flex: 0 0 auto;
   min-width: 365px;
   padding: 17px;
   font-family: var(--brave-font-heading);
   text-align: center;
   background-color: var(--brave-palette-white);
   background-image: url(${modalBackground});
   background-repeat: no-repeat;
   background-position: 4px -11px;
   background-size: auto 200px;
   box-shadow: 0px 0px 16px rgba(99, 105, 110, 0.2);
   border-radius: 8px;
 `

export const header = styled.div`
   margin-top: 17px;
   color: var(--brave-palette-black);
   font-weight: 600;
   font-size: 18px;
   line-height: 22px;

   .icon {
     vertical-align: middle;
     width: 26px;
     margin-right: 5px;
     margin-bottom: 3px;
   }
 `

export const text = styled.div`
   margin: 8px 6px 0;
   color: var(--brave-palette-neutral700);
   font-size: 14px;
   line-height: 24px;
 `

export const enable = styled.div`
   margin-top: 25px;

   button {
    min-width: 330px;
   }
 `

export const terms = styled.div`
   margin: 50px 14px 15px;
   color: var(--brave-palette-neutral600);
   font-size: 11px;
   line-height: 16px;

   a {
     color: var(--brave-color-brandBat);
     font-weight: 600;
     text-decoration: none;
   }
 `
