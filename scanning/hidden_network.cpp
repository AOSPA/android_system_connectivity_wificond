/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "wificond/scanning/hidden_network.h"

#include <android-base/logging.h>

#include "wificond/parcelable_utils.h"

using android::status_t;

namespace android {
namespace net {
namespace wifi {
namespace wificond {

status_t HiddenNetwork::writeToParcel(::android::Parcel* parcel) const {
  RETURN_IF_FAILED(parcel->writeByteVector(ssid_));
  return ::android::OK;
}

status_t HiddenNetwork::readFromParcel(const ::android::Parcel* parcel) {
  RETURN_IF_FAILED(parcel->readByteVector(&ssid_));
  return ::android::OK;
}

}  // namespace wificond
}  // namespace wifi
}  // namespace net
}  // namespace android
