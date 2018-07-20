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

    override func viewDidLoad() {
        super.viewDidLoad()
        manager = LGUiManager.create(self)
    }

    @IBAction func titleFieldDidChange(_ sender: UITextField) {
        manager?.updateTitle(sender.text!)
    }
}

extension AppViewController: LGUiObserver {
    func titleUpdated(_ title: String) {
        navigationItem.title = title
    }

    func peopleUpdated(_ people: LGPeople) {

    }

    func timeStringUpdated(_ timeString: String) {

    }
}
