//
//  ThymeAppDelegate.h
//  Thyme
//
//  Created by João Moreno on 2/8/10.
//

#import <Cocoa/Cocoa.h>
#import "DDHotKeyCenter.h"
#import <Growl/Growl.h>

@interface ThymeAppDelegate : NSObject <NSApplicationDelegate, GrowlApplicationBridgeDelegate>
{
    // Session
    NSInteger hours;
    NSInteger minutes;
    NSInteger seconds;
	NSString *name;
    
    // Timer
    Boolean isTicking;
    NSTimer *timer;
    NSThread *timerThread;
    
    // Hotkeys
    DDHotKeyCenter *hotKeyCenter;
    
    // Interface
    NSWindow *window;
    NSPersistentStoreCoordinator *persistentStoreCoordinator;
    NSManagedObjectModel *managedObjectModel;
    NSManagedObjectContext *managedObjectContext;
	
	NSPanel *namePanel;
	NSTextField *nameField;
    
    NSStatusItem *statusItem;
    NSMenu *menu;
    NSMenuItem *startStopItem;
    NSMenuItem *resetItem;
	NSMenuItem *startNamed;
    
    NSMenuItem *sessionsMenuSeparator;
    NSMenuItem *sessionsMenuClearItem;
    NSMutableArray *sessionsMenuItems;
}

@property(retain) NSTimer *timer;
@property(assign) NSThread *timerThread;

@property(retain) DDHotKeyCenter *hotKeyCenter;

@property(nonatomic, retain) IBOutlet NSWindow *window;
@property(nonatomic, retain, readonly) IBOutlet NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property(nonatomic, retain, readonly) IBOutlet NSManagedObjectModel *managedObjectModel;
@property(nonatomic, retain, readonly) IBOutlet NSManagedObjectContext *managedObjectContext;

@property(nonatomic, retain) IBOutlet NSPanel *namePanel;
@property(nonatomic, retain) IBOutlet NSTextField *nameField;

@property(retain) NSStatusItem *statusItem;
@property(nonatomic, retain) IBOutlet NSMenu *menu;
@property(nonatomic, retain) IBOutlet NSMenuItem *startStopItem;
@property(nonatomic, retain) IBOutlet NSMenuItem *resetItem;
@property(nonatomic, retain) IBOutlet NSMenuItem *startNamed;

@property(nonatomic, retain) NSMenuItem *sessionsMenuSeparator;
@property(nonatomic, retain) NSMenuItem *sessionsMenuClearItem;
@property(nonatomic, retain) NSMutableArray *sessionsMenuItems;

- (IBAction)saveAction:sender;
- (IBAction)startStop:(id)sender;
- (IBAction)reset:(id)sender;
- (IBAction)startNamed:(id)sender;
- (IBAction)showNamePanel:(id)sender;
- (IBAction)nameFieldKeyDown:(id)sender;
@end
