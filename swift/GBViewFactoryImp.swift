//
//  GBViewFactoryImp.swift
//  usnit_app
//
//  Created by dyno on 5/27/16.
//  Copyright © 2016 dyno. All rights reserved.
//

import Foundation
import UIKit

class GBViewFactoryImp: GBViewFactoryGen {
    
    @objc public func createView(id: String, type: GBViewType) -> GBViewGen?{
        let viewGen:GBViewGen? = m_views[id]
        if viewGen!=nil {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "create same view id repeately id: \(id) \(#file) \(#function) \(#line) ")
            return nil;
        }
        
        let uiview:UIView? = createView();
        if uiview == nil {
            GBLogGen.instance()?.log(GBLogGenLOGFILE|GBLogGenLOGCONSOLE, lev: GBLogGenLOGERROR,
                                     msg: "create view failed type: \(type) \(#file) \(#function) \(#line) ")
            return nil
        }
        
        let view_gen:GBViewImp = GBViewImp(id: id, view:view!)
        return viewGen
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
}
