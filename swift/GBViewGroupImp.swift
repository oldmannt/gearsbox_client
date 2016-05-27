//
//  GBViewGroupImp.swift
//  usnit_app
//
//  Created by dyno on 5/26/16.
//  Copyright © 2016 dyno. All rights reserved.
//

import Foundation
import UIKit

import Foundation

public
class GBViewGroupImp: GBViewGroupGen {
    private var m_id: String!
    private var m_view:UIView!
    private var m_controller:UIViewController!
    private var m_subView:[String:GBViewImp] = [:]

    init(view:UIView, controller:UIViewController){
        m_view = view
        m_controller = controller
    }
    
    @objc public func getView(id: String) -> GBViewGen?{
        for (view_id,view_gen) in m_subView {
            if id == view_id {
                return view_gen
            }
        }
        GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                        msg: "getView nil \(#file) \(#function) \(#line) ")
        return nil
    }
    
    @objc public func addView(id: String, type: GBViewType) -> Bool{
        let view:UIView? = createView(type)
        if nil == view {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "addView failed type: \(type) \(#file) \(#function) \(#line) ")
            return false
        }
        
        let view_gen:GBViewImp = GBViewImp(id: id, view:view!)
        m_subView[id] = view_gen
        return true
    }
    
    @objc public func removeView(id: String) -> Bool{
        let view_gen:GBViewImp? = m_subView[id]
        if view_gen == nil{
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "nothing to remove \(#file) \(#function) \(#line) ")
            return false
        }
        
        view_gen?.getUIView().removeFromSuperview()
        m_subView.removeValueForKey(id)
        return false
    }
    
    @objc public func addConstraint(constraint: GBViewConstraint){
        let view:GBViewImp? = m_subView[constraint.viewFrom]
        let toview:GBViewImp? = m_subView[constraint.viewTo]
        if toview == nil || view == nil{
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "viewFrome or viewTo nil \(#file) \(#function) \(#line) ")
            return
        }

        let multi:CGFloat = CGFloat(constraint.multiplier)
        let offset:CGFloat = CGFloat(constraint.offset)
        let attr:NSLayoutAttribute? = transLayoutAttr(constraint.type)
        let toattr:NSLayoutAttribute? = transLayoutAttr(constraint.typeTo)
        
        if attr == nil || toattr == nil {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "GBConstraintType err type:\(constraint.type) toype:\(constraint.typeTo)\(#file) \(#function) \(#line) ")
            return
        }
        
        m_view.addConstraint(NSLayoutConstraint(item: m_view, attribute: attr!, relatedBy: .Equal,
            toItem: toview, attribute: toattr!, multiplier: multi, constant: offset))

    }
    
    private func createView(type:GBViewType) -> UIView?{
        var view:UIView
        switch type {
        case GBViewType.VIEWBASE:
            view = UIView()
            return view
        case GBViewType.VIEWLABEL:
            view = UILabel()
            return view
        case GBViewType.VIEWINPUT:
            view = UITextField()
            return view
        default: break
        }
        return nil
    }
    
    private func transLayoutAttr(type:GBConstraintType) -> NSLayoutAttribute?{
        var attr:NSLayoutAttribute? = nil
        
        switch type {
        case GBConstraintType.Leading:
            attr = NSLayoutAttribute.Leading
            break
        case GBConstraintType.Trailing:
            attr = NSLayoutAttribute.Trailing
            break
        case GBConstraintType.Top:
            attr = NSLayoutAttribute.Top
            break
        case GBConstraintType.Bottom:
            attr = NSLayoutAttribute.Bottom
            break
        case GBConstraintType.Width:
            attr = NSLayoutAttribute.Width
            break
        case GBConstraintType.Height:
            attr = NSLayoutAttribute.Height
            break
        case GBConstraintType.CenterX:
            attr = NSLayoutAttribute.CenterX
            break
        case GBConstraintType.CenterY:
            attr = NSLayoutAttribute.CenterY
            break
            
        }
        return attr
    }
}