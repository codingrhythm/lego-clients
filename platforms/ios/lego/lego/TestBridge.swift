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

@objc
class DataGenerator: NSObject {
    @objc
    func createLargeData(numberOfPages: Int32, questionsPerPage: Int32) -> LGSTemplate {
        var pages: [LGSPage] = []

        for p in 0...numberOfPages {
            var questions: [LGSQuestion] = []

            for q in 0...questionsPerPage {
                questions.append(LGSQuestion(
                    id: String(format: "%d", q),
                    title: String(format: "Title for question %d", q),
                    responseType: q,
                    questionDescription: String(format: "Description for question %d", q),
                    order: q))
            }

            pages.append(LGSPage(id: String(format: "%d", p), title: String(format: "Title for page %d", p), order: p, questions: questions))
        }

        return LGSTemplate(id: "template id", name: "template name", pages: pages)
    }
}
