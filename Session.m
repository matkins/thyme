// 
//  Session.m
//  Thyme
//
//  Created by João Moreno on 6/4/10.
//

#import "Session.h"
#import "ThymeAppDelegate.h"

#define AppDelegate ((ThymeAppDelegate*) [[NSApplication sharedApplication] delegate])

@interface Session(hidden)
- (NSString*)formattedDate;
@end


@implementation Session 

@dynamic hours;
@dynamic minutes;
@dynamic seconds;
@dynamic date;
@dynamic name;

- (NSString*)formatDate
{
    static NSDateFormatter *dateFormatter = nil;
    
    if (dateFormatter == nil)
    {
        dateFormatter = [[NSDateFormatter alloc] init];
        [dateFormatter setTimeStyle:NSDateFormatterShortStyle];
        [dateFormatter setDateStyle:NSDateFormatterMediumStyle];
    }
    
    return [dateFormatter stringFromDate:self.date];
}

+ (NSArray*)allSessions
{
    NSFetchRequest *request = [[NSFetchRequest alloc] init];
    [request setEntity:[[AppDelegate.managedObjectModel entitiesByName] valueForKey:@"Session"]];
    NSArray *result = [AppDelegate.managedObjectContext executeFetchRequest:request error:nil];
    [request release];
    return result;
}

+ (Session*)sessionWithSeconds:(NSInteger)_seconds minutes:(NSInteger)_minutes hours:(NSInteger)_hours name:(NSString*)_name
{
    Session* session = (Session*) [NSEntityDescription insertNewObjectForEntityForName:@"Session" 
                                                     inManagedObjectContext:AppDelegate.managedObjectContext];

    session.hours = [NSNumber numberWithInt:_hours];
    session.minutes = [NSNumber numberWithInt:_minutes];
    session.seconds = [NSNumber numberWithInt:_seconds];
    session.date = [NSDate date];
	session.name = [_name copy];
    
    return session;
}

- (NSString*)timeStringRepresentation
{
    if ([self.hours intValue] > 0)
        return [NSString stringWithFormat:@"%02d:%02d:%02d", [self.hours intValue], [self.minutes intValue], [self.seconds intValue]];
    else
        return [NSString stringWithFormat:@"%02d:%02d", [self.minutes intValue], [self.seconds intValue]];
}

- (NSString*)stringRepresentation
{
	if (self.name == nil) {
		return [NSString stringWithFormat:@"%@ - %@", [self timeStringRepresentation], [self formatDate]];
	} else {
		return [NSString stringWithFormat:@"%@: %@ - %@", self.name, [self timeStringRepresentation], [self formatDate]];		
	}
}

@end
