//
//  AppDelegate.m
//  Chapter15
//
//  Created by Bruce Sutherland on 9/03/2015.
//  Copyright (c) 2015 Apress Publishing. All rights reserved.
//

#import "AppDelegate.h"
#include "lua.hpp"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    lua_State* pLuaState{ luaL_newstate() };
    if (pLuaState)
    {
        luaL_openlibs(pLuaState);
        
        lua_close(pLuaState);
    }
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

@end
