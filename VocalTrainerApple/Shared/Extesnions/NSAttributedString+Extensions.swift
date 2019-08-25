//
// Created by Semyon Tykhonenko on 2019-06-06.
// Copyright (c) 2019 Indiglobal Ltd. All rights reserved.
//

import Cocoa

extension NSAttributedString {
    private func getRenderedLinesAsNSArray(width: CGFloat) -> NSArray? {
        let path = CGPath(rect: CGRect(x: 0, y: 0, width: width, height: CGFloat(MAXFLOAT)), transform: nil)
        let frameSetterRef : CTFramesetter = CTFramesetterCreateWithAttributedString(self as CFAttributedString)
        let frameRef: CTFrame = CTFramesetterCreateFrame(frameSetterRef, CFRangeMake(0, 0), path, nil)
        return CTFrameGetLines(frameRef)
    }

    func getRenderedLineRanges(forWidth width: CGFloat) -> [CFRange] {
        let linesNS: NSArray?  = getRenderedLinesAsNSArray(width: width)
        guard let lines = linesNS as? [CTLine] else { return [] }
        return lines.map { CTLineGetStringRange($0) }
    }

    func numberOfLines(forWidth width: CGFloat) -> Int {
        return getRenderedLinesAsNSArray(width: width)?.count ?? 0
    }

    convenience init(image: NSImage) {
        let attachment = NSTextAttachment()
        attachment.bounds = CGRect(origin: CGPoint.zero, size: image.size)
        attachment.image = image
        self.init(attachment: attachment)
    }

    convenience init(text: String, font: NSFont, textColor: NSColor) {
        self.init(string: text, attributes: [
            NSAttributedString.Key.font: font,
            NSAttributedString.Key.foregroundColor: textColor
        ])
    }

    func draw(centredAt center: CGPoint) {
        let textSize = self.size()
        self.draw(at: CGPoint(x: center.x - textSize.width / 2, y: center.y - textSize.height / 2))
    }
}

extension NSMutableAttributedString {
    public func trimEnd(charSet: CharacterSet) {
        // Trim trailing characters from character set.
        let nsString = string as NSString
        var range = nsString.rangeOfCharacter(from: charSet, options: .backwards)
        while range.length != 0 && NSMaxRange(range) == length {
            replaceCharacters(in: range, with: "")
            range = nsString.rangeOfCharacter(from: charSet, options: .backwards)
        }
    }
}