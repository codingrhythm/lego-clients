//
//  UIPlatformSupport.swift
//  lego
//
//  Created by Yuzhou Zhu on 20/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

import Foundation

class UIPlatformSupport: LGUiPlatformSupport {
    func getStoragePath() -> String {
        return NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
    }
    
    func getTimeString() -> String {
        return String(format: "System time: %@", Date() as CVarArg)
    }

    func getTimeStringAsync(_ manager: LGUiManager?) {
        DispatchQueue.global().async { [unowned self] in
            manager?.timeStringUpdated(self.getTimeString())
        }
    }

    func postTask(inBackgroundThread task: LGTask?) {
        DispatchQueue.global().async {
            task?.execute()
        }
    }
}
