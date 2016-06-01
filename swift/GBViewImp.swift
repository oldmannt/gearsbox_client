//
//  GBViewImp.swift
//  gearsbox
//
//  Created by dyno on 5/26/16.
//
//

import Foundation
import UIKit

public
class GBViewImp: GBViewGen {
    private var m_id: String!
    private var m_view: UIView!
    private var m_controller:UIViewController!
    private var m_subView:[String:GBViewImp] = [:]
    private var m_handler:GBViewEventHandler?
    
    public init(id: String, view: UIView, controller:UIViewController){
        m_id = id
        m_view = view
        m_controller = controller
    }
    
    @objc public func getId() -> String{
        return m_id;
    }
    
    @objc public func setFrame(frame: GBViewFrame){
        m_view.frame = CGRect(origin: CGPoint(x: CGFloat(frame.x), y: CGFloat(frame.y)),
               size: CGSize(width: CGFloat(frame.w), height: CGFloat(frame.h)))
    }
    
    @objc public func getFrame() -> GBViewFrame{
        let frame:GBViewFrame = GBViewFrame(
            x:Float(m_view.frame.origin.x),
            y:Float(m_view.frame.origin.y),
            w:Float(m_view.frame.size.width),
            h:Float(m_view.frame.size.height))
        
        return frame;
    }
    
    @objc public func setBackgroundColor(a: Float, r: Float, g: Float, b: Float){
        m_view.backgroundColor = UIColor(colorLiteralRed: r, green: g, blue: b, alpha: a)
    }
    
    @objc public func setVisiable(v: Bool){
        m_view.hidden = !v
    }
    
    @objc public func getSubView(id: String) -> GBViewGen?{
        for (view_id,view_gen) in m_subView {
            if id == view_id {
                return view_gen
            }
        }
        GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                 msg: "get sub view nil \(#file) \(#function) \(#line) ")
        return nil
    }
    
    @objc public func addSubView(id: String, type: GBViewType) -> GBViewGen?{
        if m_subView[id] != nil {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "addView failed aready exist id: \(id) \(#file) \(#function) \(#line) ")
            return nil;
        }
        
        if id == m_id {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "addView failed this parent id: \(id) \(#file) \(#function) \(#line) ")
            return nil;
        }
        let view:UIView? = createView(type)
        if nil == view {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "addView failed type: \(type) \(#file) \(#function) \(#line) ")
            return nil
        }
        
        m_view.addSubview(view!)
        let view_gen:GBViewImp = GBViewImp(id: id, view:view!,controller: m_controller)
        m_subView[id] = view_gen
        return view_gen
    }
    
    @objc public func removeSubView(id: String) -> Bool{
        if !removeSubViewImp(id){
            return false
        }
        m_subView.removeValueForKey(id)
        return true
    }
    
    private func removeSubViewImp(id:String) -> Bool{
        let view_gen:GBViewImp? = m_subView[id]
        if view_gen == nil{
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "nothing to remove \(#file) \(#function) \(#line) ")
            return false
        }
        
        view_gen?.getUIView().removeFromSuperview()
        GBUiInjecterGen.instance()?.removeView(id)
        return true
    }
    
    @objc public func removeAllSubView(){
        for (id, _) in m_subView{
            removeSubViewImp(id)
        }
        m_subView.removeAll()
    }
    
    @objc public func addConstraint(constraint: GBViewConstraint){
        let typestr = ["None    ","Leading ","Trailing","Top     ","Bottom  ","Width   ","Height  ","CenterX ","CenterY "]
        print("constraint: viewFrome:\(constraint.viewFrom) viewTo:\(constraint.viewTo) type:\(typestr[constraint.type.rawValue]) typeTo:\(typestr[constraint.typeTo.rawValue]) multiplier:\(constraint.multiplier) offset:\(constraint.offset)")
        let view:GBViewImp? = m_subView[constraint.viewFrom]
        if view == nil{
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "viewFrome nil \(#file) \(#function) \(#line) ")
            return
        }
        
        var toview:GBViewImp?
        if GBViewConstraintParent == constraint.viewTo{
            toview = self
        }else{
            toview = m_subView[constraint.viewTo]
        }
        
        let multi:CGFloat = CGFloat(constraint.multiplier)
        let offset:CGFloat = CGFloat(constraint.offset)
        let attr:NSLayoutAttribute? = transLayoutAttr(constraint.type)
        var toattr:NSLayoutAttribute? = transLayoutAttr(constraint.typeTo)
        if nil == toview{
            toattr = NSLayoutAttribute.NotAnAttribute
        }
        
        if attr == NSLayoutAttribute.NotAnAttribute {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "GBConstraintType err type:\(constraint.type) toype:\(constraint.typeTo)\(#file) \(#function) \(#line) ")
            return
        }
        
        view!.getUIView().translatesAutoresizingMaskIntoConstraints = false
        m_view.addConstraint(NSLayoutConstraint(item: view!.getUIView(), attribute: attr!, relatedBy: .Equal,
            toItem: toview!.getUIView(), attribute: toattr!, multiplier: multi, constant: offset))

    }
    
    @objc public func setEventHandler(handler: GBViewEventHandler?){
        let recognizer = UITapGestureRecognizer(target: self, action:#selector(GBViewImp.tapEvent(_:)))
        m_view.addGestureRecognizer(recognizer)
        
        if m_view is UIControl{
            let ctrl:UIControl = m_view as! UIControl;
            ctrl.addTarget(self, action: #selector(GBViewImp.textChange(_:)), forControlEvents: UIControlEvents.EditingChanged)
        }
        m_handler = handler;
    }
    
    @objc internal func tapEvent(sender:UIGestureRecognizer){
        if nil == m_handler {
            return
        }
        let point:CGPoint = sender.locationInView(sender.view)
        let param:GBViewEventParam = GBViewEventParam(x: Float(point.x), y: Float(point.y),type: GBViewEvent.EVENTTAP, text: "")
        
        m_handler!.handle(param, view: self)
    }
    
    @objc internal func textChange(sender: UITextField){
        if nil == m_handler {
            return
        }
        
        let param:GBViewEventParam = GBViewEventParam(x: 0,y: 0,type: GBViewEvent.EVENTTEXTCHANGED, text: sender.text!)
        m_handler!.handle(param, view: self)
    }
    
    
    internal func getUIView() -> UIView{
        return m_view
    }
    
    private func transLayoutAttr(type:GBConstraintType) -> NSLayoutAttribute?{
        var attr:NSLayoutAttribute = NSLayoutAttribute.NotAnAttribute
        
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
        default: break
        }
        return attr
    }
    
    private func createView(type:GBViewType) -> UIView?{
        switch type {
        case GBViewType.VIEWBASE:
            return UIView()
        case GBViewType.VIEWLABEL:
            return UILabel()
        case GBViewType.VIEWINPUT:
            let view:UITextField = UITextField()
            view.placeholder="  Enter here"
            view.borderStyle = UITextBorderStyle.RoundedRect
           return view
        default: break
        }
        return nil
    }
}