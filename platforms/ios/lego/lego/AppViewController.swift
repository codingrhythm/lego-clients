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
    @IBOutlet fileprivate var stateChangeHistoryTextView: UITextView!
    fileprivate var startTime = Date()

    fileprivate var stateChanges: [String] = [] {
        didSet {
            stateChangeHistoryTextView.text = stateChanges.joined(separator: "\n")
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        manager = LGUiManager.create(self, platform: platformSupport)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        startTime = Date()
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

    @IBAction func firstNameFieldDidChange(_ sender: UITextField) {
        manager?.updateFirstName(firstNameField.text!)
        manager?.getTimeStringAsync()
    }

    @IBAction func lastNameFieldDidChange(_ sender: UITextField) {
        manager?.updateLastName(lastNameField.text!)
        manager?.getTimeStringAsync()
    }
}

extension AppViewController: LGUiObserver {
    func titleUpdated(_ title: String) {
        DispatchQueue.main.async { [unowned self] in
            self.navigationItem.title = title
            self.stateChanges.append(String(format: "[%0.5f] title: %@", -self.startTime.timeIntervalSinceNow, title))
        }
    }

    func peopleUpdated(_ people: LGPeople) {
        self.nameLabel.text = people.firstName + " " + people.lastName
        self.stateChanges.append(String(format: "[%0.5f] people: %@", -self.startTime.timeIntervalSinceNow, self.nameLabel.text!))
    }

    func timeStringUpdated(_ timeString: String) {
        DispatchQueue.main.async { [unowned self] in
            self.timeLabel.text = timeString
            self.stateChanges.append(String(format: "[%0.5f] timeString: %@", -self.startTime.timeIntervalSinceNow, timeString))
        }

    }
}
