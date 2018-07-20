//
//  UIPlatformSupport.swift
//  lego
//
//  Created by Yuzhou Zhu on 20/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

import Foundation

class UIPlatformSupport: LGUiPlatformSupport {
    func getTimeString() -> String {
        return String(format: "System time: %@", Date() as CVarArg)
    }
}
