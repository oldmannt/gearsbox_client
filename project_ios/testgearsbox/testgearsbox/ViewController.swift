//
//  ViewController.swift
//  testgearsbox
//
//  Created by dyno on 5/17/16.
//  Copyright © 2016 dyno. All rights reserved.
//

import UIKit

public
class CallbackHttp: GBCallbackHttpGen {
    
    @objc public func callback(id: Int64, result: Bool, data: String) -> Bool{
        GBLogGen.instance()!.log(GBLogGenLOGCONSOLE, lev: GBLogGenLOGINFO, msg: data)
        return true
    }
}

func dosth (elapse:Int64){
    GBAsyncLoopGen.instance()!.process(elapse)
}

class ViewController: UIViewController {
    
    var call:CallbackHttp?
    var loop:MainLoop=MainLoop(frameInterval: 1, doSomething: dosth)
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        GBLogGen.instance()!.log(GBLogGenLOGCONSOLE, lev: GBLogGenLOGINFO, msg: "fire")
        
        call = CallbackHttp()
        GBHttpRequestGen.create()!.get("http://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20yahoo.finance.xchange%20where%20pair%20in%20(%22USDCNY%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys", callback: call)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

