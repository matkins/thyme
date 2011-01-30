//
//  Session.h
//  Thyme
//
//  Created by João Moreno on 6/4/10.
//

#import <CoreData/CoreData.h>


@interface Session :  NSManagedObject  
{
}

@property (nonatomic, retain) NSNumber * hours;
@property (nonatomic, retain) NSNumber * minutes;
@property (nonatomic, retain) NSNumber * seconds;
@property (nonatomic, retain) NSDate * date;
@property (nonatomic, retain) NSString * name;

+ (NSArray*)allSessions;
+ (Session*)sessionWithSeconds:(NSInteger)_seconds minutes:(NSInteger)_minutes hours:(NSInteger)_hours name:(NSString*)_name;
- (NSString*)timeStringRepresentation;
- (NSString*)stringRepresentation;

@end
