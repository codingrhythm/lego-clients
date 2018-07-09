//
//  TestBridge.swift
//  lego
//
//  Created by Yuzhou Zhu on 6/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

import Foundation

func testBridge() {
    let platform = LGLegoPlatformImpl {

    }
    let core = LGLegoCore.create(platform)
    core?.downloadFile("test")
}
