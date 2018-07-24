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
    @IBOutlet fileprivate var firstNameField: UITextField!
    @IBOutlet fileprivate var lastNameField: UITextField!
    @IBOutlet fileprivate var nameLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        manager = LGUiManager.create(self, platform: platformSupport)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        manager?.start()
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        manager?.stop()
    }

    @IBAction func titleFieldDidChange(_ sender: UITextField) {
        manager?.updateTitle(sender.text!)
        manager?.getTimeString()
    }

    @IBAction func saveButtonTapped(_ sender: UIButton) {
        manager?.updateLastName(lastNameField.text!)
        manager?.updateFirstName(firstNameField.text!)
        manager?.getTimeStringAsync()
    }
}

extension AppViewController: LGUiObserver {
    func titleUpdated(_ title: String) {
        navigationItem.title = title
    }

    func peopleUpdated(_ people: LGPeople) {
        nameLabel.text = people.firstName + " " + people.lastName
    }

    func timeStringUpdated(_ timeString: String) {
        DispatchQueue.main.async {
            self.timeLabel.text = timeString
        }

    }
}
