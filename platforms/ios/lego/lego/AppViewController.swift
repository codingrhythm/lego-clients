//
//  AppViewController.swift
//  lego
//
//  Created by Yuzhou Zhu on 20/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

import UIKit

class AppViewController: UIViewController {
    // todo: the observer should be weak reference
    var manager: LGUiManager?
    let platformSupport = UIPlatformSupport()
    @IBOutlet fileprivate var timeLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        manager = LGUiManager.create(self, platform: platformSupport)
    }

    @IBAction func titleFieldDidChange(_ sender: UITextField) {
        manager?.updateTitle(sender.text!)
        timeLabel.text = manager?.getTimeString()
    }
}

extension AppViewController: LGUiObserver {
    func titleUpdated(_ title: String) {
        navigationItem.title = title
    }

    func peopleUpdated(_ people: LGPeople) {

    }
}
