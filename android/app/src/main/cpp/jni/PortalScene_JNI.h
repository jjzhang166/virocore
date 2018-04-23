/**
 * Copyright © 2017 Viro Media. All rights reserved.
 */

#ifndef ANDROID_PORTALSCENE_JNI_H
#define ANDROID_PORTALSCENE_JNI_H

#include <VROPortal.h>
#include "PersistentRef.h"

#include "VRODefines.h"
#include VRO_C_INCLUDE

namespace PortalScene {
    inline VRO_REF jptr(std::shared_ptr<VROPortal> shared_portal) {
        PersistentRef<VROPortal> *native_portal = new PersistentRef<VROPortal>(shared_portal);
        return reinterpret_cast<intptr_t>(native_portal);
    }

    inline std::shared_ptr<VROPortal> native(VRO_REF ptr) {
        PersistentRef<VROPortal> *persistentPortal = reinterpret_cast<PersistentRef<VROPortal> *>(ptr);
        return persistentPortal->get();
    }

}



#endif //ANDROID_PORTALSCENE_JNI_H